#include<cstdio>
#include<numeric>
#include<cassert>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i=(l);i<=(r);++i)
#define rf(i,l,r) for(int i=(l);i>=(r);--i)
#define fo(i,l,r) for(int i=(l);i<(r);++i)
#define foredge(i,u,v) for(int i=fir[u],v;v=to[i],i;i=nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N=1e5+5;
int n,m,h,a[N];
vector<int> G[N];
int dfn[N],dfc,low[N],stk[N],top,bel[N],sccn;
void Tarjan(int u) {
	dfn[u]=low[u]=++dfc;
	stk[++top]=u;
	for(auto v:G[u]) {
		if(!dfn[v]) Tarjan(v),low[u]=min(low[u],low[v]);
		else if(!bel[v]) low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u]) {
		++sccn;
		do bel[stk[top]]=sccn;
		while(stk[top--]^u);
	}
}
bool vis[N];
int siz[N];
int main() {
	cin>>n>>m>>h;
	fr(i,1,n) cin>>a[i];
	fr(i,1,m) {
		int u,v;
		cin>>u>>v;
		if((a[u]+1)%h==a[v]) G[u].push_back(v);
		if((a[v]+1)%h==a[u]) G[v].push_back(u);
	}
	fr(i,1,n) if(!dfn[i]) Tarjan(i);
	fr(u,1,n) {
		for(auto v:G[u]) if(bel[u]^bel[v]) vis[bel[u]]=1;
		++siz[bel[u]];
	}
	int ans=-1;
	fr(i,1,sccn) if(!vis[i]&&(ans==-1||siz[ans]>siz[i]))
		ans=i;
	cout<<siz[ans]<<endl;
	fr(i,1,n) if(bel[i]==ans) cout<<i<<' ';
	cout<<endl;
	return 0;
}

const int S=1<<21;
char p0[S],*p1,*p2;
#define getchar() (p2==p1&&(p2=(p1=p0)+fread(p0,1,S,stdin))==p1?EOF:*p1++)
inline int read() {
	static int x,c,f;x=0;f=1;
	do c=getchar(),c=='-'&&(f=-1); while(!isdigit(c));
	do x=x*10+(c&15),c=getchar(); while(isdigit(c));
	return x*f;
}