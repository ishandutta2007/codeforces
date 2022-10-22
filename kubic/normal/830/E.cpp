#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define pb push_back
int T,n,m,ps,nw,fa[N],fa1[N],lst[N],ans[N];vector<int> z[3],e[N];
int findRt(int u) {return u==fa[u]?u:fa[u]=findRt(fa[u]);}
bool merge(int u,int v)
{u=findRt(u);v=findRt(v);if(u==v) return 0;fa[u]=v;return 1;}
void dfs(int u,int f) {fa1[u]=f;for(auto v:e[u]) if(v!=f) dfs(v,u);}
void dfs1(int u,int f)
{
	if(f) z[nw].pb(u);if(e[u].size()==1) ++nw;
	for(auto v:e[u]) if(v!=f) dfs1(v,u);
}
void slv()
{
	scanf("%d %d",&n,&m);ps=0;for(int i=1;i<=n;++i) fa[i]=i,e[i].clear();
	for(int i=1,u,v;i<=m;++i)
	{scanf("%d %d",&u,&v);e[u].pb(v);e[v].pb(u);if(!merge(u,v)) ps=u;}
	if(ps)
	{
		puts("YES");
		for(int i=1;i<=n;++i) printf("%d ",findRt(ps)==findRt(i));
		puts("");return;
	}ps=0;for(int i=1;i<=n;++i) if(e[i].size()>3) ps=i;
	if(ps)
	{
		puts("YES");
		for(int i=1;i<=n;++i) printf("%d ",ps==i?2:(findRt(ps)==findRt(i)));
		puts("");return;
	}for(int i=1;i<=n;++i) lst[i]=ans[i]=0;
	for(int i=1,t;i<=n;++i) if(e[i].size()>2)
	{
		t=findRt(i);if(!lst[t]) {lst[t]=i;continue;}
		dfs(i,0);for(int j=lst[t];j;j=fa1[j]) ans[j]=2;puts("YES");
		for(int j=1;j<=n;++j) printf("%d ",ans[j]?2:(findRt(i)==findRt(j)));
		puts("");return;
	}
	for(int i=1;i<=n;++i) if(e[i].size()>2)
	{
		nw=0;z[0].clear();z[1].clear();z[2].clear();dfs1(i,0);
		if(z[0].size()>z[1].size()) swap(z[0],z[1]);
		if(z[0].size()>z[2].size()) swap(z[0],z[2]);
		if(z[1].size()>z[2].size()) swap(z[1],z[2]);
		if(z[0].size()>1)
		{
			ans[i]=3;ans[z[0][0]]=ans[z[1][0]]=ans[z[2][0]]=2;
			ans[z[0][1]]=ans[z[1][1]]=ans[z[2][1]]=1;
			puts("YES");for(int j=1;j<=n;++j) printf("%d ",ans[j]);puts("");return;
		}
		if(z[1].size()>2)
		{
			ans[i]=4;ans[z[0][0]]=2;ans[z[1][0]]=ans[z[2][0]]=3;
			ans[z[1][1]]=ans[z[2][1]]=2;ans[z[1][2]]=ans[z[2][2]]=1;
			puts("YES");for(int j=1;j<=n;++j) printf("%d ",ans[j]);puts("");return;
		}if(z[1].size()<2) continue;
		if(z[2].size()>4)
		{
			ans[i]=6;ans[z[0][0]]=3;ans[z[1][0]]=4;ans[z[1][1]]=2;
			ans[z[2][0]]=5;ans[z[2][1]]=4;ans[z[2][2]]=3;ans[z[2][3]]=2;ans[z[2][4]]=1;
			puts("YES");for(int j=1;j<=n;++j) printf("%d ",ans[j]);puts("");return;
		}
	}puts("NO");
}
int main() {scanf("%d",&T);while(T--) slv();return 0;}