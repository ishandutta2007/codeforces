#include <iostream>
using namespace std;
long long abs(long long x)
{
	return (x>0)? x:x*-1;
}
int solve (long long x)
{
	int d=0,j;
	for (j=abs(x);j>0;j/=10)
	d++;
	for (j=0;j<d;j++)
	{
		if (abs(x)%10==8)
		return 0;
		x/=10;
	}
	return 1; 
}
int main()
{
	long long a,p,i,test=0;
	cin >> a;
	p=a;
	do
	{
		p++;
		test++;
	}while (solve(p));
	cout << test;
}