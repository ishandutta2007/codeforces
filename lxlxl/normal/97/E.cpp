#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

inline void down(int &a,const int &b){if(a>b)a=b;}
const int maxd = 20;
const int maxn = 210000;

int n,m;
int e[maxn][2];
struct edge{int y,i,nex;}a[maxn<<1]; int len,fir[maxn];
inline void ins(const int x,const int y,const int i){a[++len]=(edge){y,i,fir[x]};fir[x]=len;}

int vis[maxn],vi;
int dfn[maxn],low[maxn],dfi;
int t[maxn],tp;
int fa[maxn][maxd],dep[maxn],s[maxn];
void dfs(const int x)
{
	vis[x]=vi;
	dfn[x]=low[x]=++dfi;
	for(int i=1;i<maxd;i++) fa[x][i]=fa[fa[x][i-1]][i-1];
	
	for(int k=fir[x],y=a[k].y;k;k=a[k].nex,y=a[k].y) if(y!=fa[x][0])
	{
		if(!dfn[y])
		{
			t[++tp]=a[k].i;
			dep[y]=dep[x]+1,fa[y][0]=x;
			dfs(y);
			down(low[x],low[y]);
			if(low[y]>=dfn[x])
			{
				int fl=0;
				for(int i=tp;t[i]!=a[k].i&&!fl;i--) fl|=(dep[e[t[i]][0]]&1)==(dep[e[t[i]][1]]&1);
				while(1)
				{
					if(e[t[tp]][0]!=x) s[e[t[tp]][0]]=fl;
					if(e[t[tp]][1]!=x) s[e[t[tp]][1]]=fl;
					if(t[tp--]==a[k].i) break;
				}
			}
		}
		else if(dfn[y]<dfn[x]) t[++tp]=a[k].i,down(low[x],dfn[y]);
	}
}
void dfs2(const int x)
{
	for(int k=fir[x],y=a[k].y;k;k=a[k].nex,y=a[k].y) if(fa[y][0]==x)
		s[y]+=s[x],dfs2(y);
}
int LCA(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=maxd-1;i>=0;i--) if(dep[fa[x][i]]>=dep[y]) x=fa[x][i];
	if(x==y) return x;
	for(int i=maxd-1;i>=0;i--) if(fa[x][i]!=fa[y][i])
		x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}

int main()
{
	//freopen("tmp.in","r",stdin);
	//freopen("tmp.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y; scanf("%d%d",&x,&y);
		e[i][0]=x,e[i][1]=y;
		ins(x,y,i),ins(y,x,i);
	}
	for(int i=1;i<=n;i++) if(!dfn[i]) dep[i]=1,++vi,dfs(i);
	for(int i=1;i<=n;i++) if(!fa[i][0]) dfs2(i);
	
	int q; scanf("%d",&q);
	while(q--)
	{
		int x,y; scanf("%d%d",&x,&y);
		if(vis[x]!=vis[y]) { puts("No");continue; }
		if(((dep[x]&1)^(dep[y]&1))||s[x]+s[y]-2*s[LCA(x,y)]>0) puts("Yes");
		else puts("No");
	}
	
	return 0;
}