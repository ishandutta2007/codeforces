#include<cstdio>
#include<iostream>

using namespace std;

const int MOD=1000000007;

long long power(long long x,long long p)
{
	if (!p) return 1;
	long long t=power(x,p/2);
	t=t*t%MOD;
	if (p&1) t=t*x%MOD;
	return t;
}

int sum0(int n)
{
	if (!n) return 0;
	return 4LL*(power(3,n)-1LL+MOD)%MOD;
}

int sum1(int n)
{
	if (!n) return 0;
	if (n==1) return 4;
	return (7LL*(power(3,n-1)-1+MOD)+4)%MOD;
}

int get(int n)
{
	if (!n) return 0;
	return (sum0(n/2)+sum1((n+1)/2))%MOD;
}

int calc0(int n)
{
	if (!n) return 0;
	return sum0(n)%MOD;
}

int calc1(int n)
{
	if (!n) return 0;
	return (sum1(n)+get(n))%MOD;
}

int solve(int n)
{
	if (!n) return 0;
	return (calc0(n/2)+calc1((n+1)/2))*power(2,MOD-2)%MOD;
}

int main()
{
	int L,R;
	cin>>L>>R;
	cout<<(solve(R)-solve(L-1)+MOD)%MOD<<endl;
	return 0;
}