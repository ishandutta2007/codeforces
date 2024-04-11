
#include <bits/stdc++.h>
using namespace std;
void print(long long x){cout<<x<<endl;}
long long input(){long long x;cin>>x;return x;}
int main()
{
	long long t=((input)());
	for (long long i=(0); (i)<(t); (i)++)
	{
		long long n=((input)());
		if (((n)%(2))==(0))
		{
			(print)((n)/(2));
			(print)(0);
			(print)(0);
		}
		else
		{
			(print)(-(1));
		}
	}
}