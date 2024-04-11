#include<iostream>
#include<map>
#include<cstdio>
#include<cmath>
using namespace std;
long long n,a,b,cnt,k;
map<long long,long long> mp;
long long prime[111111];
bool f[1111111];
int main()
{
	for (int i=2;i<=1000000;i++)
	{
		if (!f[i])
		{
			for (int j=2;j<=1000000/i;j++)
			f[i*j]=1;
		}
	}
	for (int i=2;i<=1000000;i++) 
	{
		if (!f[i]) prime[cnt++]=i;
	}
	for (long long i=1;i<=1000000;i++)
	{
		mp[i*i*i]=i;
	}
	scanf("%lld",&n);
	while(n--)
	{
		scanf("%lld%lld",&a,&b);
		k=mp[a*b];
		if (!k) 
		{
			printf("No\n");
			continue;
		}
		if (a%k || b%k || k%(a/k)) 
		{
			printf("No\n");
			continue;
		}
		printf("Yes\n");
	}
	return 0;
}