#include <bits/stdc++.h>
using namespace std;
#define N 500005
#define M 10000005
#define MOD 1000000007
int n,m,ans,a[N],p[M],mu[M],s[M],pw[N];bool vs[M];
int calc(int x) {return x?1ll*x*pw[x-1]%MOD:0;}
void sieve(int n)
{
	vs[1]=mu[1]=1;
	for(int i=2;i<=n;++i)
	{
		if(!vs[i]) p[++p[0]]=i,mu[i]=-1;
		for(int j=1;i*p[j]<=n;++j)
		{vs[i*p[j]]=1;if(!(i%p[j])) break;mu[i*p[j]]=-mu[i];}
	}
}
int main()
{
	scanf("%d",&n);pw[0]=1;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);++s[a[i]];
		m=max(m,a[i]);pw[i]=pw[i-1]*2%MOD;
	}sieve(m);
	for(int i=1;i<=p[0];++i) for(int j=m/p[i];j;--j) s[j]+=s[j*p[i]];
	for(int i=1;i<=m;++i)
	{
		ans=(ans+1ll*mu[i]*(calc(s[i])-s[i]))%MOD;
		ans=(ans-1ll*mu[i]*(1ll*n*(pw[s[i]]-1)%MOD-calc(s[i])))%MOD;
	}printf("%d\n",(ans+MOD)%MOD);return 0;
}