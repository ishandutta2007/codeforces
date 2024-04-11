#include<iostream>
#include<cstdio>
using namespace std;
int a[333333],n,d;
int prime[11111],cnt,bst,all[22222222],ans;
bool f[22222];
const int maxn=10000;
int gcd(int a,int b)
{
	if (!b) return a;
	return gcd(b,a%b);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for (int i=1;i<=n;i++)
	{
		d=gcd(d,a[i]);
	}
	for (int i=1;i<=n;i++)
	{
		a[i]/=d;
	}
	for (int i=2;i<=maxn;i++)
	{
		if (!f[i])
		{
			prime[++cnt]=i;
		}
		for (int j=1;j<=cnt && i*prime[j]<=maxn;j++)
		{
			f[i*prime[j]]=1;
			if (i%prime[j]==0) break;
		}
	}
	bst=560;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=560;j++)
		{
			if (a[i]%prime[j]==0) 
			{
				all[prime[j]]++;
				ans=max(ans,all[prime[j]]);
			}
			while(a[i]%prime[j]==0)
			{
				a[i]/=prime[j];
			}
		}
		if (a[i]!=1) 
		{
			all[a[i]]++;
			ans=max(ans,all[a[i]]);
		}
	}
	if (!ans) printf("-1\n");
	else printf("%d\n",n-ans);
	return 0;
}