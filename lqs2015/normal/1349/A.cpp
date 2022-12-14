#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
const int maxn=600;
int test,n,a[111111],prime[111111],cnt,mn1[222222],mn2[222222],ct,rr[222222];
bool f[222222];
long long ans;
void Init()
{
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
}
void upd(int x,int y)
{
	rr[x]++;
	if (mn1[x]>y)
	{
		mn2[x]=mn1[x];
		mn1[x]=y;
	}
	else if (mn2[x]>y) mn2[x]=y;
}
long long Pow(int x,int y)
{
	long long res=1,p=x;
	for (int i=y;i;i>>=1)
	{
		if (i&1) res=res*p;
		p=p*p;
	}
	return res;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for (int i=1;i<=200000;i++) mn1[i]=mn2[i]=1e9;
	Init();
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=cnt;j++)
		{
			ct=0;
			while(a[i]%prime[j]==0)
			{
				++ct;
				a[i]/=prime[j];
			}
			upd(prime[j],ct);
		}
		if (a[i]>1) upd(a[i],1);
	}
	ans=1;
	for (int i=1;i<=200000;i++)
	{
		if (rr[i]<n-1) continue;
		if (rr[i]==n-1) ans*=Pow(i,mn1[i]);
		else ans*=Pow(i,mn2[i]);
	}
	cout<<ans<<endl;
	return Accepted;
}