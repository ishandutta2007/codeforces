#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=200000;
const int mod=1e9+7;
int n,k;
int w[maxn+5],f[maxn+5],g[maxn+5];
void add(int &x,int y)
{
	x+=y;
	if(x>=mod) x-=mod;
	return;
}
void sub(int &x,int y)
{
	x-=y;
	if(x<0) x+=mod;
	return;
}
void mul(int &x,int y)
{
	x=x*y%mod;
	return;
}
int qpow(int a,int b)
{
	if(b<0) return qpow(qpow(a,-b),mod-2);
	if(!b) return 1;
	int res=1;
	for(;b>0;b/=2,a=a*a%mod) if(b%2) mul(res,a);
	return res;
}
signed main()
{
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++) scanf("%lld",&w[i]);
	int sum=0,p=0;
	for(int i=1;i<=n;i++) add(sum,w[i]);
	f[0]=g[0]=1;
	for(int i=1;i<=n;i++) f[i]=f[i-1]*i%mod,g[i]=qpow(f[i],-1);
	for(int i=0;i<=k-1;i++)
	{
		int s=1;
		mul(s,qpow(k-i,n-2));
		mul(s,k-i+n-1);
		mul(s,g[i]);
		mul(s,g[k-i-1]);
		if(i%2==0) add(p,s);
		else sub(p,s);
	}
	mul(sum,p);
	printf("%lld\n",sum);
	return 0;
		
}