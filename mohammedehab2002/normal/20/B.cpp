#include <iostream>
#include <math.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
	double a,b,c,ans,r[2];
	cin >> a >> b >> c;
	ans=pow(b,2)-(4*a*c);
	if (ans<0)
	{
		cout << 0;
		return 0;
	}
	if (a==0)
	{
		if (b==0 && c==0)
		cout << -1;
		else if (b==0 && c!=0)
		cout << 0;
		else if (b!=0 && c==0)
		cout << "1\n0.0000000";
		else if (b!=0 && c!=0)
		printf("1\n%9.7f",(-1*c)/b);
		return 0;
	}
	else
	{
			r[0]=(-1*b+(sqrt(pow(b,2)-(4*a*c))))/(2*a);
			r[1]=(-1*b-(sqrt(pow(b,2)-(4*a*c))))/(2*a);
			if (r[0]==r[1])
			printf ("1\n%9.7f",r[0]);
			else
			printf ("2\n%9.7f\n%9.7f",min(r[0],r[1]),max(r[0],r[1]));
	}
}