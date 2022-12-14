#include<iostream>
#include<cstdio>
using namespace std;
long long n,k,cnt,arr;
long long a[111111];
bool f[111111],all[111111];
long long gcd(long long a,long long b)
{
	if (!b) return a;
	return gcd(b,a%b);
}
int main()
{
	scanf("%I64d%I64d",&n,&k);
	for (long long i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
		arr=gcd(arr,gcd(a[i]%k,k));
	}
	for (long long j=0;j<k;j+=arr)
	{
		all[j]=1;
	}
	for (long long j=0;j<k;j++) 
	{
		if (all[j]) cnt++;
	}
	printf("%I64d\n",cnt);
	for (long long j=0;j<k;j++)
	{
		if (all[j]) printf("%I64d ",j);
	}
	printf("\n");
	return 0;
}