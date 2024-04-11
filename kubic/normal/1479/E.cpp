#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define N 1005
#define ll long long
const int MOD=998244353;
int n,m,a[N];ll t1,t2,w1=1,w2=1,w,ans;
ll qPow(ll x,ll y)
{
	ll res=1;
	for(;y;y/=2,x=x*x%MOD) if(y&1)
		res=res*x%MOD;return res;
}
int main()
{
	scanf("%d",&n);if(n==1) {puts("0");return 0;}
	for(int i=1;i<=n;++i) scanf("%d",&a[i]),m+=a[i];
	a[++n]=m;sort(a+1,a+n+1);t1=m*2;t2=m+1; 
	for(int i=1,t=1;i<=m;++i)
	{
		--t1;--t2;w1=w1*t1%MOD;w2=w2*t2%MOD;
		while(t<=n && a[t]==i)
		{
			w=w1*qPow(w2,MOD-2)%MOD-1;
			if(t==n) ans-=w;else ans+=w;++t;
		}
	}ans=-2ll*ans%MOD*m%MOD*qPow(m-1,MOD-2)%MOD;
	printf("%lld\n",(ans+MOD)%MOD);return 0;
}