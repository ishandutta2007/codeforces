#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
	char a1,a2;
	int a3,a4,d1,d2,d3,d4,i,j;
	cin >> a1 >> a3 >> a2 >> a4;
	d1=a2-a1;
	d2=a4-a3;
	if (d1<0)
	d3=d1*-1;
	else
	d3=d1;
	if (d2<0)
	d4=d2*-1;
	else
	d4=d2;
	cout << max(d3,d4) << endl;
	if (d3==d4 && d3!=0)
	{
		for (i=0;i<d3;i++)
		{
		if (d1<0)
		cout << "L";
		else
		cout << "R";
		if (d2<0)
		cout << "D";
		else
		cout << "U";
		cout << "\n";
		}
		exit(0);
	}
	else if (d3==0)
	{
		for (i=0;i<d4;i++)
		{
			if (d2<0)
			cout << "D\n";
			else
			cout << "U\n";
		}
		exit(0);		
	}
	else if (d4==0)
	{
		for (i=0;i<d3;i++)
		{
			if (d1<0)
			cout << "L\n";
			else
			cout << "R\n";
		}
		exit(0);
	}
	else if (d3>d4)
	{
		for (i=0;i<d4;i++)
		{
			if (d1<0)
			cout << "L";
			else
			cout << "R";
			if (d2<0)
			cout << "D";
			else
			cout << "U";
			cout << "\n";
		}
		for (j=d4;j<d3;j++)
		{
			if (d1<0)
			cout << "L";
			else
			cout << "R";
			cout << "\n";
		}
		exit(0);
	}
	else if (d4>d3)
	{
		for (i=0;i<d3;i++)
		{
			if (d1<0)
			cout << "L";
			else
			cout << "R";
			if (d2<0)
			cout << "D";
			else
			cout << "U";
			cout << "\n";
		}
		for (j=d3;j<d4;j++)
		{
			if (d2<0)
			cout << "D";
			else
			cout << "U";
			cout << "\n";
		}
		exit(0);
	}
}