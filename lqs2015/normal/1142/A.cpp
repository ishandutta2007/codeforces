#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
long long gcd(long long a,long long b)
{
	if (!b) return a;
	return gcd(b,a%b);
}
long long n,k,a,b,mn,mx;
bool f;
int main()
{
	cin>>n>>k>>a>>b;
	mn=1e12;mx=0;
	for (long long i=1;i<=2*k;i++)
	{
		f=0;
		if (i<=k) 
		{
			if (min(i,k-i)==a) f=1;
		}
		else
		{
			if (min(i-k,2*k-i)==a) f=1;
		}
		if (f)
		{
			for (long long j=i+1;j<=2*k;j++)
			{
				f=0;
				if (j<=k) 
				{
					if (min(j,k-j)==b) f=1;
				}
				else
				{
					if (min(j-k,2*k-j)==b) f=1;
				}
				if (f)
				{
					for (long long h=j-i,p=1;p<=n;p++,h+=k)
					{
						mx=max(mx,gcd(n*k,h));
						mn=min(mn,gcd(n*k,h));
					}
				}
			}
		}
	}
	cout<<n*k/mx<<" "<<n*k/mn<<endl;
	return Accepted;
}