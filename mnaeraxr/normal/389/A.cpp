// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int _mcd(int a,int b)
{
	int t = 1;
	while (a > 0)
	{
		t = b % a;
		b = a;
		a = t;
	}
	return b;
}

int main()
{
	int times;
	cin >> times;
	int cur;
	int mcd;
	cin >> mcd;

	for (int i = 1; i < times; i++)
	{
		cin >> cur;
		mcd = _mcd(mcd,cur);
	}

	cout << mcd*times << endl;
}