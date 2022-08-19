#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
#define VIZ {printf("digraph G{\n"); for(int i=1;i<=n;i++) for es(i,e) printf("%d->%d;\n",i,vb[e]); puts("}");}
#define VIZ2 {printf("graph G{\n"); for(int i=1;i<=n;i++) for es(i,e) if(vb[e]>=i)printf("%d--%d;\n",i,vb[e]); puts("}");}
#define SZ 1234567
int n,fa[SZ],dep[SZ]; Edg
int d[SZ],sz[SZ],son[SZ];
void dfs(int x)
{
	d[x]=d[fa[x]]+1; sz[x]=1;
	for esb(x,e,b)
	{
		dfs(b); sz[x]+=sz[b];
		if(sz[b]>sz[son[x]]) son[x]=b;
	}
}
int fe[SZ],top[SZ],id[SZ],C=0;
void dfs2(int x,int t)
{
	id[fe[x]=++C]=x; top[x]=t;
	if(!son[x]) return;
	dfs2(son[x],t);
	for esb(x,e,b) if(b!=son[x])
		dfs2(b,b); 
}
struct BS
{
ll a1[SZ],a2[SZ];
ll qzh(int r)
{
    ll s1=0,s2=0;
    for(int i=r;i>=1;i-=i&-i) s1+=a1[i], s2+=a2[i];
    return (r+1)*s1-s2;
}
ll sum(int l,int r)
{
    return qzh(r)-qzh(l-1);
}
void edt(ll a,ll s1)
{
    ll s2=a*s1;
    for(;a<=n;a+=a&-a) a1[a]+=s1, a2[a]+=s2;
}
void edt(int l,int r,ll a) {edt(l,a); edt(r+1,-a);}
}bb;
void add(int x)
{
	while(x)
		bb.edt(fe[top[x]],fe[x],1),x=fa[top[x]];
}
ll sum(int x)
{
	ll su=0;
	while(x)
		su+=bb.sum(fe[top[x]],fe[x]),x=fa[top[x]];
	return su; 
}
pii ds[SZ]; ll ans[SZ];
int main()
{
	scanf("%d",&n); int r=0;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",fa+i);
		if(!fa[i]) r=i;
		else ad_de(fa[i],i);
	}
	dfs(r); dfs2(r,r);
	for(int i=1;i<=n;++i)
		ds[i]=pii(d[i],fe[i]);
	sort(ds+1,ds+1+n);
	int g=1;
	for(int i=1;i<=n;++i)
	{
		while(g<=n&&ds[g].fi<=ds[i].fi)
			add(id[ds[g++].se]);
		ans[id[ds[i].se]]=sum(id[ds[i].se]);
	}
	for(int i=1;i<=n;++i)
		printf("%lld ",ans[i]-d[i]);
}