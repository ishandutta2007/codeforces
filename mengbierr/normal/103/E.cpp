#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<vector>
#include<cmath>
#include<queue>
#define LL long long
#define inf (1ll<<30)
#define free(a) freopen(a".in","r",stdin),freopen(a".out","w",stdout)
using namespace std;

const int maxn=500;
int head[maxn],cnt=1,ans,clk,S,T,n,a[maxn],vis[maxn],p[maxn];
vector<int> v[maxn];
struct edge {int to,next,w;}e[maxn*maxn*2];

namespace Dinic {
	int d[maxn];
	void link(int u,int v,int w) {
		e[++cnt]=(edge){v,head[u],w};head[u]=cnt;
		e[++cnt]=(edge){u,head[v],0};head[v]=cnt;
	}
	bool bfs() {
		for (int i=S;i<=T;i++) d[i]=-1;
		queue<int> q;q.push(S);d[S]=0;
		while (!q.empty()) {
			int x=q.front();q.pop();
			for (int i=head[x];i;i=e[i].next)
				if (e[i].w && d[e[i].to]<0) d[e[i].to]=d[x]+1,q.push(e[i].to);
		}
		return d[T]>0;
	}
	int dfs(int x,int f) {
		if (f==0 || x==T) return f;
		int w,used=0;
		for (int i=head[x];i;i=e[i].next) if (e[i].w && d[e[i].to]==d[x]+1) {
				w=dfs(e[i].to,min(e[i].w,f-used));
				used+=w,e[i].w-=w,e[i^1].w+=w;
				if (used==f) return used;
			}
		if (!used) d[x]=-1;
		return used;
	}
	int main() {
		int flow=0;
		while (bfs()) flow+=dfs(S,inf);
		return flow;
	}
}
using namespace Dinic;

bool match(int x) {
	for (int i=0,j=v[x].size();i<j;i++) {
		if (vis[v[x][i]]==clk) continue;
		vis[v[x][i]]=clk;
		if (!p[v[x][i]] || match(p[v[x][i]])) {p[v[x][i]]=x;return 1;}
	}
	return 0;
}
int main() {
	scanf("%d",&n);
	for (int x,y,i=1;i<=n;i++) {
		scanf("%d",&y);
		for (int j=1;j<=y;j++) scanf("%d",&x),v[i].push_back(x);
	}
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) ++clk,match(i);
	S=0,T=n+1;
	for (int i=1;i<=n;i++)
		for (int j=0,k=v[i].size();j<k;j++) link(i,p[v[i][j]],inf);
	for (int i=1;i<=n;i++) {
		if (a[i]<0) link(S,i,-a[i]),ans-=a[i];
		else link(i,T,a[i]);
	}
	ans-=Dinic::main();
	printf("%d",-ans);
	return 0;
}