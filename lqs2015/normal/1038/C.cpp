#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
pair<long long,long long> k[222222];
long long n,ans;
bool f;
int main()
{
	scanf("%I64d",&n);
	for (long long i=1;i<=n;i++) 
	{
		scanf("%I64d",&k[i].first);
	}
	for (long long i=1;i<=n;i++)
	{
		scanf("%I64d",&k[i+n].first);
		k[i+n].second=1;
	}
	sort(k+1,k+2*n+1);
	reverse(k+1,k+2*n+1);
	f=0;
	for (long long i=1;i<=2*n;i++)
	{
		if (k[i].second==f) 
		{
			if (!f) ans+=k[i].first;
			else ans-=k[i].first;
		}
		f=1-f;
	}
	printf("%I64d\n",ans);
	return 0;
}