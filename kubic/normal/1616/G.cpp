#include <bits/stdc++.h>
using namespace std;
#define N 500005
#define ll long long
#define pb push_back
int T,n,m,ps1,ps2,w1,w2;ll ans;bool vs1[N],vs2[N],vs3[N],e1[N];
vector<int> e2[N],e3[N],e4[N];
void dfs1(int u) {if(vs1[u]) return;vs1[u]=1;for(auto v:e3[u]) dfs1(v);}
void dfs2(int u) {if(vs1[u]) return;vs1[u]=1;for(auto v:e4[u]) dfs2(v);}
void slv()
{
	scanf("%d %d",&n,&m);n+=2;ps1=ps2=w1=w2=ans=0;
	for(int i=1;i<=n*2;++i)
		vs1[i]=vs2[i]=e1[i]=0,e2[i].clear(),e3[i].clear(),e4[i].clear();
	e1[1]=e1[n-1]=1;for(int i=1;i<n-1;++i) e2[1].pb(i+2),e2[i].pb(n); 
	for(int i=1,u,v;i<=m;++i)
	{scanf("%d %d",&u,&v);++u;++v;if(u+1==v) e1[u]=v;else e2[u].pb(v);}
	for(int i=1;i<n;++i) if(!e1[i]) {if(!ps1) ps1=i;ps2=i;}
	if(!ps1) {printf("%lld\n",1ll*(n-2)*(n-3)/2);return;}
	for(int i=n,r=n;i>1;--i)
	{
		if(!e1[i]) r=i;
		for(auto v:e2[i-1]) if(v<=r+1)
			e3[i-1].pb(n+v),e3[n+i].pb(v-1),e4[n+v].pb(i-1),e4[v-1].pb(n+i);
	}dfs1(ps1);vs1[ps1]=0;dfs2(ps1);swap(vs1,vs2);
	dfs1(n+ps1+1);vs1[n+ps1+1]=0;dfs2(n+ps1+1);
	for(int i=1;i<n;++i) vs3[i]=vs1[i]&vs2[i];
	for(int i=1;i<=ps1;++i) w1+=vs1[i];for(int i=ps2;i<n;++i) w2+=vs1[i];
	ans=1ll*w1*w2;w1=w2=0;
	for(int i=1;i<=ps1;++i) w1+=vs2[i];for(int i=ps2;i<n;++i) w2+=vs2[i];
	ans+=1ll*w1*w2;w1=w2=0;
	for(int i=1;i<=ps1;++i) w1+=vs3[i];for(int i=ps2;i<n;++i) w2+=vs3[i];
	ans-=1ll*w1*w2;printf("%lld\n",ans-(ps1==ps2));
}
int main() {scanf("%d",&T);while(T--) slv();return 0;}