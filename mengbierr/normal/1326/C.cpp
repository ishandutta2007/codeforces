#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int read()
{
	char ch=getchar();int f=0,x=1;
	while(ch<'0'||ch>'9'){if(ch=='-') x=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f*x;
}
int n,k,a[500005];bool ok[500005];
ll mod=998244353;
int main()
{
	n=read();k=read();
	for(int i=1;i<=n;i++) a[i]=read();
	ll ans=0;
	for(int i=n-k+1;i<=n;i++) ans+=i;
	cout<<ans<<" ";
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=n-k+1) ok[i]=1;
	}
	int pla=0;ans=1;
	for(int i=1;i<=n;i++)
	{
		if(ok[i])
		{
			if(!pla) pla=i;
			else ans*=(i-pla),ans%=mod,pla=i;
		}
	}
	cout<<ans;
	
}