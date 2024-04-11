#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;
int main()
{
	double a,b,n,x=-1001,i;
	cin >> a >> b >> n;
	if (a!=0)
	b/=a;
	else
	{
		if (b==0)
		cout << -1000;
		else
		cout << "No solution";
		exit(0);
	}
	for (i=-1000;i<=1000;i++)
	{
		if (pow(i,n)==b)
		x=i;
	}
	if (x!=-1001)
	cout << x;
	else
	cout << "No solution";
}