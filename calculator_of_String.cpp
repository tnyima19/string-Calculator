// convert infix to post fix. 
/*
Name:Tenzing Nyima
Project 5
CSCI 235
Date: July 13 2021

project on evaluate the string expressions using stack.


I need to improve this project, 
i need to be able to use negative integers at the beginning of the sting,
the program does not accept negative integers at the beginning.


*/



#include<iostream>
#include<stack>
#include<cmath>
#include<string>
#include<sstream>
#include<ctype.h>
#include<stdio.h>
using namespace std;

int precedence(char signs)
{
	if(signs =='*'|| signs =='/')
		return 2;
	else if(signs =='-'|| signs =='+')
		return 1;

	return 0;
}

int sum_all(int num1, int num2, char ope)
{
	int total=0;
	if(ope == '+')
		 total =num1 + num2;

	else if(ope =='-')
		total =num1 - num2;

	else if(ope =='*')
		total =num1 * num2;

	else if(ope =='/')
		total = num1 / num2;

	return total;
}



int calculate(string group1)
{
	// create two stacks. 
	stack<int> integers;
	stack<char> operators;



	for(int i =0;i<group1.size();i++)
	{

		if(group1[i]==' ')
			continue;

		else if(isdigit(group1[i]))
		{
			int num =0;
			while(i<group1.size()&& isdigit(group1[i]))
			{
				num = (num*10) + (group1[i]-'0');
				i++;
			}
			// push in the number;
			i--;// because we increase it above. balancing.
			integers.push(num);


			//if(i==0 &&)

		}

		else // usually operators like + - * and / signs go in here  
		{	
			char op;
			while(!operators.empty() && precedence(operators.top())>= precedence(group1[i]))
			{
				// here calculate
				int val2= integers.top();
				integers.pop();
				int val1 = integers.top();
				integers.pop();
				op = operators.top();
				operators.pop();
				integers.push(sum_all(val1, val2, op)); // function calculates value. 
			}
			// if an operation reaches here it must the operator must go into the operator stack
			operators.push(group1[i]);

		}



	}

	//int result =0;
	while(!operators.empty())
	{
		int val2= integers.top();
		//result = result + integers.top();
		integers.pop();
		int val1 = integers.top();
		integers.pop();
		char op = operators.top();
		operators.pop();
		integers.push(sum_all(val1, val2, op)); // function calculates value. 

	}
	
	return integers.top();

}

int main()
{
	//string group1 = "3+2-6";

	//cout<<infixToPostfix(group1);
	string group2 = "32+6-1";
	cout<<"32+6-1 ="<<calculate(group2)<<endl;

	string group3 = "2 +3 *5+8 /3-6+2*5/6-5";
	cout<<"2 +3 *5+8 /3-6+2*5/6-5 ="<<calculate(group3)<<endl;

	string group4 = "-2* -2";
	//cout<<calculate(group4)<<endl;

	string group5 = "1*2-3/4+5*6";
	cout<<"1*2-3/4+5*6= "<<calculate(group5)<<endl;


	string group6 = "1*2-3/4+5*6-7*8+9/10";
	cout<<"1*2-3/4+5*6-7*8+9/10 ="<<calculate(group6)<<endl;


	string group7 =  "3+5 / 2 ";
	cout<<" 3+5 / 2 ="<<calculate(group7)<<endl;
	string group8 = "3+2*2";
	cout<<"3+2*2 ="<<calculate(group8)<<endl;

	return 0;

}



