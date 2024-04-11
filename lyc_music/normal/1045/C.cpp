#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define SF scanf
#define PF printf
#define MAXN 400010
using namespace std;
struct node{
	int u,v;
	node () {}
	node (int u1,int v1):u(u1),v(v1) {}	
}Edge[MAXN];
vector<int> a[MAXN];
int dfn[MAXN],low[MAXN],cnt;
int stk[MAXN],tp,n2,ncnt;
void dfs(int x,int fa=0){
	dfn[x]=low[x]=++cnt;
	stk[++tp]=x;
	int flg=0;
	for(int i=0;i<int(a[x].size());i++){
		int u=a[x][i];
		if(u==fa){
			flg++;
			if(flg==1)
				continue;
		}
		if(dfn[u]==0){
			dfs(u,x);
			low[x]=min(low[x],low[u]);
			if(low[u]>=dfn[x]){
				n2++;
				Edge[++ncnt]=node(n2,x);
				while(1){
					Edge[++ncnt]=node(stk[tp],n2);
					if(stk[tp--]==u)
						break;
				}
			}
		}
		else
			low[x]=min(low[x],dfn[u]);
	}	
}
int f[MAXN][20];
int dep[MAXN];
void prepare(int x,int fa=0){
	f[x][0]=fa;
	dep[x]=dep[fa]+1;
	for(int i=1;i<20;i++)
		f[x][i]=f[f[x][i-1]][i-1];
	for(int i=0;i<int(a[x].size());i++){
		int u=a[x][i];
		if(u==fa)
			continue;
		prepare(u,x);	
	}
}
int lca(int u,int v){
	if(dep[u]<dep[v])
		swap(u,v);
	for(int i=19;i>=0;i--)
		if(dep[f[u][i]]>=dep[v])
			u=f[u][i];
	if(u==v)
		return u;
	for(int i=19;i>=0;i--)
		if(f[u][i]!=f[v][i]){
			u=f[u][i];
			v=f[v][i];	
		}
	return f[u][0];
}
int add[MAXN];
void get_ans(int x,int fa=0){
	for(int i=0;i<int(a[x].size());i++){
		int u=a[x][i];
		if(u==fa)
			continue;
		get_ans(u,x);
		add[x]+=add[u];
	}
}
int main(){
	int n,m,q,u,v;
	SF("%d%d%d",&n,&m,&q);
	for(int i=1;i<=m;i++){
		SF("%d%d",&u,&v);
		a[u].push_back(v);	
		a[v].push_back(u);
	}
	n2=n;
	dfs(1);
	for(int i=1;i<=n;i++)
		a[i].clear();
	for(int i=1;i<=ncnt;i++){
		a[Edge[i].u].push_back(Edge[i].v);
		a[Edge[i].v].push_back(Edge[i].u);	
	}
	prepare(1);
	while (q--)
	{
		SF("%d%d",&u,&v);
		PF("%d\n",(dep[u]+dep[v]-dep[lca(u,v)]*2)/2);
	}
}
/*
5 7 2
1 2
1 3
1 4
2 3
2 4
3 4
1 5
1 4
2 5
*/