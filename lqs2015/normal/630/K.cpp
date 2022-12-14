#include<iostream>
using namespace std;
long long a[2522];
bool check(int i)
{
	for (int j=2;j<=10;j++)
	{
		if (i%j==0) return 0;
	}
	return 1;
}
int main()
{
	long long n;
	cin>>n;
	a[0]=0;
	for (int i=1;i<2520;i++)
	{
		if (check(i)) a[i]=a[i-1]+1;
		else a[i]=a[i-1];
	}
	cout<<(n/2520)*a[2519]+a[n%2520];
	return 0;
}