#include<bits/stdc++.h>
using namespace std;
const int mod=998244353,maxn=500000;
int n,k,jc[555555],injc[555555],ans;
void add(int &x,int y)
{
	x+=y;
	if (x>=mod) x-=mod;
}
int C(int n,int k)
{
	if (n<0 || k<0 || n<k) return 0;
	return 1ll*jc[n]*injc[k]%mod*injc[n-k]%mod;
}
int binpow(int a,int t)
{
	int res=1,p=a;
	for (int i=t;i;i>>=1)
	{
		if (i&1) res=1ll*res*p%mod;
		p=1ll*p*p%mod;
	}
	return res;
}
void Init()
{
	jc[0]=1;
	for (int i=1;i<=maxn;i++) jc[i]=1ll*jc[i-1]*i%mod;
	injc[maxn]=binpow(jc[maxn],mod-2);
	for (int i=maxn-1;i>=0;i--) injc[i]=1ll*injc[i+1]*(i+1)%mod;
}
int main()
{
	Init();
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) add(ans,C(n/i-1,k-1));
	printf("%d\n",ans);
	return 0;
}