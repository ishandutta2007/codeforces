#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N=100050;
int mod;
int mul(int x, int y){ return (ll)x*y%mod;}
int add(int x, int y){ return ((ll)x+y)%mod;}
int sb(int x, int y){ return ((x-y)%mod+mod)%mod;}
int pow(int x, int k){ int ans=1;for(;k;k>>=1,x=mul(x,x)) if(k&1) ans=mul(ans,x);return ans;}
int Euler()
{
    int ans=mod,tmp=mod;
    for(int i=2;i*i<=tmp;i++)
	{
		if(tmp%i==0)
		{
			ans/=i;
			ans*=i-1;
			while(tmp%i==0) tmp/=i;
		}
	}
	if(tmp>1) ans/=tmp,ans*=tmp-1;
	return ans;
}
int ab[N],w[N],po[N],ip[N],sz[N];
bool was[N];
vector<int> E[N];
void DFSSZ(int u, int p)
{
	sz[u]=1;
	for(int i:E[u])
	{
		int v=ab[i]^u;
		if(!was[v] && v!=p)
		{
			DFSSZ(v,u);
			sz[u]+=sz[v];
		}
	}
}
int Find(int u, int p, int n)
{
	for(int i:E[u])
	{
		int v=ab[i]^u;
		if(!was[v] && v!=p && sz[v]>n/2) return Find(v,u,n);
	}
	return u;
}
int Find(int u){ DFSSZ(u,u);return Find(u,u,sz[u]);}
map<int,int> cnt[N];
ll ans;
void Build(int u, int p, int sub, int cen, int dep, int val)
{
	cnt[sub][val]++;
	cnt[cen][val]++;
	//if(val==0) ans++;
	//printf("(%i %i) %i\n",cen,u,val);
	for(int i:E[u])
	{
		int v=ab[i]^u;
		if(!was[v] && v!=p)
		{
			Build(v,u,sub,cen,dep+1,add(val,mul(po[dep],w[i])));
		}
	}
}
void Solve(int u, int p, int sub, int cen, int dep, int val)
{
	int need=sb(0,mul(val,ip[dep]));
	ans+=cnt[cen][need]-cnt[sub][need];
	//if(val==0) ans++;
	//printf("need:(%i %i) %i\n",cen,u,need);
	for(int i:E[u])
	{
		int v=ab[i]^u;
		if(!was[v] && v!=p)
		{
			Solve(v,u,sub,cen,dep+1,add(mul(val,10),w[i]));
		}
	}
}
void Decompose(int u)
{
	u=Find(u);
	was[u]=1;
	cnt[u].clear();
	cnt[u][0]++;
	for(int i:E[u])
	{
		int v=ab[i]^u;
		if(!was[v])
		{
			cnt[v].clear();
            Build(v,u,v,u,1,w[i]%mod);
		}
	}
	ans+=cnt[u][0]-1;
	//printf("u:%i %i\n",u,cnt[u][0]);
	for(int i:E[u])
	{
		int v=ab[i]^u;
		if(!was[v])
		{
			Solve(v,u,v,u,1,w[i]%mod);
		}
	}
	for(int i:E[u])
	{
		int v=ab[i]^u;
		if(!was[v])
		{
			Decompose(v);
		}
	}
}
int main()
{
	int n,u,v;
	scanf("%i %i",&n,&mod);
    for(int i=1;i<n;i++)
	{
		scanf("%i %i %i",&u,&v,&w[i]);
		u++;v++;
		ab[i]=u^v;
		E[u].pb(i);
		E[v].pb(i);
	}
	po[0]=1;
	for(int i=1;i<=n;i++) po[i]=mul(po[i-1],10);
	int inv=pow(10,Euler()-1);
	ip[0]=1;
	for(int i=1;i<=n;i++) ip[i]=mul(ip[i-1],inv);
	Decompose(1);
	printf("%lld\n",ans);
	return 0;
}