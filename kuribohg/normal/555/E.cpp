#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=400010;
int n,m,x,y,Q_num;
pair<int,int> Edge[MAXN],Q[MAXN];
int head[MAXN],to[MAXN],next[MAXN],cnt=1;
inline void adde(int f,int t)
{
	cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt;
	cnt++,to[cnt]=f,next[cnt]=head[t],head[t]=cnt;
}
int dfn[MAXN],low[MAXN],dfs_clock;
bool is_bridge[MAXN];
void Tarjan(int x,int father)
{
	dfn[x]=low[x]=++dfs_clock;
	for(int i=head[x];i;i=next[i])
	{
		if(!dfn[to[i]]) Tarjan(to[i],i),low[x]=min(low[x],low[to[i]]);
		else if((i^father)!=1) low[x]=min(low[x],dfn[to[i]]);
		if(low[to[i]]>dfn[x]) is_bridge[i]=is_bridge[i^1]=true;
	}
}
int bccno[MAXN],bcc_tot;
void DFS_bcc(int x,int col)
{
	bccno[x]=col;
	for(int i=head[x];i;i=next[i])
		if(!is_bridge[i]&&!bccno[to[i]]) DFS_bcc(to[i],col);
}
int dep[MAXN],Log[MAXN],anc[MAXN][20],col[MAXN],col_tot;
void DFS(int x,int fa,int c)
{
	col[x]=c;
	for(int i=head[x];i;i=next[i])
		if(to[i]!=fa)
		{
			dep[to[i]]=dep[x]+1;
			anc[to[i]][0]=x;
			DFS(to[i],x,c);
		}
}
int LCA(int p,int q)
{
	if(dep[p]<dep[q]) swap(p,q);
	int d=dep[p]-dep[q];
	for(int i=Log[d];i>=0;i--)
		if(d&(1<<i)) p=anc[p][i];
	for(int i=Log[n];i>=0;i--)
		if(anc[p][i]!=anc[q][i]) p=anc[p][i],q=anc[q][i];
	if(p!=q) return anc[p][0];
	else return p;
}
int D[MAXN],up[MAXN],down[MAXN];
void DP(int x,int fa,int f[])
{
	f[x]=D[x];
	for(int i=head[x];i;i=next[i])
		if(to[i]!=fa)
		{
			DP(to[i],x,f);
			f[x]+=f[to[i]];
		}
}
int main()
{
	scanf("%d%d%d",&n,&m,&Q_num);
	for(int i=1;i<=m;i++) scanf("%d%d",&x,&y),adde(x,y),Edge[i]=make_pair(x,y);
	for(int i=1;i<=n;i++) if(!dfn[i]) Tarjan(i,0);
	for(int i=1;i<=n;i++) if(!bccno[i]) DFS_bcc(i,++bcc_tot);
	cnt=1;
	for(int i=1;i<=n;i++) head[i]=0;
	for(int i=1;i<=m;i++)
		if(bccno[Edge[i].first]!=bccno[Edge[i].second])
			adde(bccno[Edge[i].first],bccno[Edge[i].second]);
	n=bcc_tot;
	for(int i=1;i<=n;i++) if(!anc[i][0]) DFS(i,-1,++col_tot);
	Log[0]=-1;
	for(int i=1;i<=n;i++) Log[i]=Log[i>>1]+1;
	for(int i=1;i<=Log[n];i++)
		for(int j=1;j<=n;j++)
			anc[j][i]=anc[anc[j][i-1]][i-1];
	for(int i=1;i<=Q_num;i++) scanf("%d%d",&x,&y),Q[i]=make_pair(x,y);
	for(int i=1;i<=Q_num;i++) Q[i].first=bccno[Q[i].first],Q[i].second=bccno[Q[i].second];
	for(int i=1;i<=Q_num;i++)
		if(col[Q[i].first]!=col[Q[i].second]) {puts("No");return 0;}
	for(int i=1;i<=Q_num;i++)
	{
		int lca=LCA(Q[i].first,Q[i].second);
		D[lca]--,D[Q[i].first]++;
	}
	DP(1,-1,up);
	for(int i=1;i<=n;i++) D[i]=0;
	for(int i=1;i<=Q_num;i++)
	{
		int lca=LCA(Q[i].first,Q[i].second);
		D[lca]--,D[Q[i].second]++;
	}
	DP(1,-1,down);
	for(int i=2;i<=n;i++) if(up[i]&&down[i]) {puts("No");return 0;}
	puts("Yes");
	return 0;
}