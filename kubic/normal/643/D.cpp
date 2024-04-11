#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define ll long long
#define msit multiset<ll>::iterator
int n,m,fa[N],dg[N];ll a[N],w[N];multiset<ll> z1,z[N];
ll f1(int u) {return a[u]/(dg[u]+1);}
ll f2(int u) {return a[u]-f1(u)*dg[u];}
void ins(int u) {z[fa[u]].insert(w[u]);}
void dlt(int u) {z[fa[u]].erase(z[fa[u]].find(w[u]));}
void ins1(int u)
{
	if(z[u].empty()) return;z1.insert((*z[u].begin())+f1(u));
	z1.insert((*--z[u].end())+f1(u));
}
void dlt1(int u)
{
	if(z[u].empty()) return;z1.erase(z1.find((*z[u].begin())+f1(u)));
	z1.erase(z1.find((*--z[u].end())+f1(u)));
}
void upd(int u,int v)
{
	dlt1(fa[u]);dlt1(fa[fa[u]]);dlt1(fa[fa[fa[u]]]);
	dlt(u);dlt(fa[u]);dlt(fa[fa[u]]);
	w[fa[u]]-=f1(u)+f2(fa[u]);w[fa[fa[u]]]-=f1(fa[u]);--dg[fa[u]];
	w[fa[u]]+=f2(fa[u]);w[fa[fa[u]]]+=f1(fa[u]);
	ins(fa[u]);ins(fa[fa[u]]);
	ins1(fa[u]);ins1(fa[fa[u]]);ins1(fa[fa[fa[u]]]);
	fa[u]=v;dlt1(fa[u]);dlt1(fa[fa[u]]);dlt1(fa[fa[fa[u]]]);
	ins(u);dlt(fa[u]);dlt(fa[fa[u]]);
	w[fa[u]]-=f2(fa[u]);w[fa[fa[u]]]-=f1(fa[u]);++dg[fa[u]];
	w[fa[u]]+=f1(u)+f2(fa[u]);w[fa[fa[u]]]+=f1(fa[u]);
	ins(fa[u]);ins(fa[fa[u]]);
	ins1(fa[u]);ins1(fa[fa[u]]);ins1(fa[fa[fa[u]]]);
}
int main()
{
	scanf("%d %d",&n,&m);for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
	for(int i=1;i<=n;++i) scanf("%d",&fa[i]),++dg[i],++dg[fa[i]];
	for(int i=1;i<=n;++i) w[i]+=f2(i),w[fa[i]]+=f1(i);
	for(int i=1;i<=n;++i) ins(i);for(int i=1;i<=n;++i) ins1(i);
	for(int i=1,F[3];i<=m;++i)
	{
		scanf("%d",&F[0]);
		if(F[0]==1) scanf("%d %d",&F[1],&F[2]),upd(F[1],F[2]);
		if(F[0]==2) scanf("%d",&F[1]),printf("%lld\n",w[F[1]]+f1(fa[F[1]]));
		if(F[0]==3) printf("%lld %lld\n",*z1.begin(),*--z1.end());
	}return 0;
}