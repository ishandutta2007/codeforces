#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int mod=998244353;
int read()
{
	char ch=getchar();int f=0,x=1;
	while(ch<'0'||ch>'9'){if(ch=='-') x=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f*x;
}
ll f[2][505][505][2],ans[505];

int n,k;
ll quick_mod(ll x,int y)
{
	ll ret=1;
	while(y)
	{
		if(y&1) ret=ret*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return ret;
}
int main()
{
	n=read();k=read();
	f[1][1][1][1]=f[1][1][1][0]=1;
	int now=1;
	for(int i=2;i<=n;i++)
	{
		now^=1;
		for(int j=1;j<=i;j++)
		{
			for(int l=1;l<=j;l++)
			f[now][j][l][1]=f[now][j][l][0]=0;
		}
		for(int j=1;j<i;j++)
		{
			for(int l=1;l<=j;l++)
			{
				(f[now][max(j,l+1)][l+1][0]+=f[now^1][j][l][0])%=mod;
				(f[now][max(j,l+1)][l+1][1]+=f[now^1][j][l][1])%=mod;
				(f[now][j][1][0]+=f[now^1][j][l][1])%=mod;
				(f[now][j][1][1]+=f[now^1][j][l][0])%=mod;
				//cout<<f[now][j][1][1]<<" "<<j<<endl;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			(ans[i]+=f[now][i][j][1]+f[now][i][j][0])%=mod;
		}
		//cout<<ans[i]<<" ";
	}
	ll num=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i*j<k) 
			{
				//cout<<i*j<<" ";
				num+=1LL*ans[i]*ans[j]%mod;
				num%=mod;
			}
		}
	}
	cout<<1LL*num*quick_mod(2,mod-2)%mod;
}