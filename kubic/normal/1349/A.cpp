#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define INF 1e9
#define ll long long
int n,lim=2e5,p[N],vs[N],st[N],cnt[N],z[N],mn[N][2];ll ans=1;
void sieve(int n)
{
	vs[1]=1;
	for(int i=2;i<=n;++i)
	{
		if(!vs[i]) vs[i]=p[++p[0]]=i;
		for(int j=1;i*p[j]<=n;++j)
		{
			vs[i*p[j]]=p[j];
			if(!(i%p[j])) break;
		}
	}
}
void ins(int x)
{
	st[0]=0;
	for(int i=x,lst;i>1;i/=vs[i])
	{
		++cnt[vs[i]];
		if(vs[i]!=lst) st[++st[0]]=lst=vs[i],--z[vs[i]];
	}
	for(int i=1;i<=st[0];++i)
		if(cnt[st[i]]<mn[st[i]][0])
			mn[st[i]][1]=mn[st[i]][0],mn[st[i]][0]=cnt[st[i]];
		else if(cnt[st[i]]<mn[st[i]][1]) mn[st[i]][1]=cnt[st[i]];
	for(int i=1;i<=st[0];++i) cnt[st[i]]=0;
}
ll qPow(ll x,ll y)
{
	ll res=1;
	for(;y;y>>=1,x*=x) if(y&1) res*=x;return res;
}
int main()
{
	sieve(lim);scanf("%d",&n);
	for(int i=1;i<=lim;++i) mn[i][0]=mn[i][1]=INF,z[i]=n;
	for(int i=1,x;i<=n;++i) scanf("%d",&x),ins(x);
	for(int i=1;i<=lim;++i)
		if(z[i]<2) ans*=qPow(i,mn[i][z[i]^1]);
	printf("%lld\n",ans);return 0;
}