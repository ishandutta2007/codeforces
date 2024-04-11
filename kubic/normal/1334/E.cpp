#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define N 105
#define ll long long
#define MOD 998244353
int m,cU[N],cV[N];ll n,ans,fc[N],invF[N],p[N];
ll inv(ll x) {return x==1?1:inv(MOD%x)*(MOD-MOD/x)%MOD;}
int main()
{
	scanf("%lld %d",&n,&m);fc[0]=invF[0]=1;
	for(int i=1;i<=100;++i) fc[i]=fc[i-1]*i%MOD;
	invF[100]=inv(fc[100]);
	for(int i=99;i>=1;--i) invF[i]=invF[i+1]*(i+1)%MOD; 
	for(int i=2;1ll*i*i<=n;++i) if(!(n%i))
	{
		p[++p[0]]=i;
		while(!(n%i)) n/=i;
	}if(n>1) p[++p[0]]=n;
	for(int i=1;i<=m;++i)
	{
		ll u,v,t1=0,t2=0;scanf("%lld %lld",&u,&v);
		for(int j=1;j<=p[0];++j)
		{
			cU[j]=cV[j]=0;
			while(!(u%p[j])) ++cU[j],u/=p[j];
			while(!(v%p[j])) ++cV[j],v/=p[j];
			if(cU[j]<cV[j]) t1+=cV[j]-cU[j];
			else t2+=cU[j]-cV[j];
		}ans=fc[t1]*fc[t2]%MOD;
		for(int j=1;j<=p[0];++j) ans=ans*invF[abs(cU[j]-cV[j])]%MOD;
		printf("%lld\n",ans);
	}return 0;
}