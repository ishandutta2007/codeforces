//Author : MatrixCascade

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define clr(f, n) memset(f, 0, sizeof(int) * (n))
#define cpy(f, g, n) memcpy(f, g, sizeof(int) * (n))
#define rev(f, n) reverse(f, f + n)
#define pir pair<int, int>
#define mkp make_pair
#define fst it->first
#define sec it->second
#define int long long
#define up(i,x,y) for(int i=x,i##end=y;i<=i##end;++i)
#define down(i,x,y) for(int i=x,i##end=y;i>=i##end;--i)
using namespace std;
int n, m, k;
int read()
{
    int s = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        s = s * 10 + ch - '0';
        ch = getchar();
    }
    return s * f;
}
inline void print(int *f, int len)
{
    for (int i = 0; i < len; i++)
        printf("%lld ", f[i]);
    puts("");
}
const int maxn=2e5+10,maxm=4e5+10;
int head[maxn],to[maxm],nxt[maxm],tot;
int fa[maxn][21],ft[maxn][21];
int dfn[maxn],siz[maxn],dep[maxn],tott;
vector<int>R[maxn];
int c[maxm];
vector<int>f[maxn];
struct node
{
	int a;
	int b;
};
vector<node>q[maxn];
int lowbit(int x)
{
	return x&(-x);
}
void upt(int x)
{
	for(;x<=n;x+=lowbit(x))c[x]++;
}
int qry(int x)
{
	int ans=0;
	for(;x;x-=lowbit(x))ans+=c[x];
	return ans;
}
void add(int a,int b)
{
	to[++tot]=b;
	nxt[tot]=head[a];
	head[a]=tot;
}
void dfs(int x,int depp)
{
	dep[x]=depp;
	siz[x]=1;
	dfn[x]=++tott;
	for(int i=head[x];i;i=nxt[i])
	{
		int v=to[i];
		if(v==fa[x][0])continue;
		dfs(v,depp+1);
		siz[x]+=siz[v];
	}
}
int g[maxn];
int lca(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	down(i,20,0)if(dep[fa[x][i]]>=dep[y])x=fa[x][i];
	if(x==y)return x;
	down(i,20,0)if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
void dfs2(int x)
{
	g[x]=x;
	for(int i=0;i<f[x].size();++i)
	{
		if(dep[f[x][i]]<dep[g[x]])g[x]=f[x][i];
	}
	for(int i=head[x];i;i=nxt[i])
	{
		int v=to[i];
		if(v==fa[x][0])continue;
		dfs2(v);
		if(dep[g[v]]<dep[g[x]])g[x]=g[v];
	}
	ft[x][0]=g[x];
}
node qry2(int x,int lca)
{
	if(x==lca)return (node){x,0};
	int anss=0;
	down(i,20,0)if(dep[ft[x][i]]>dep[lca])x=ft[x][i],anss+=(1<<i);
	if(ft[x][0]==x)return (node){x,-1};
	else return (node){x,anss};
}
int ans2[maxn];
int ans[maxn];
signed main()
{
	n=read();
	up(i,2,n)
	{
		fa[i][0]=read();
		add(i,fa[i][0]);
		add(fa[i][0],i);
	}
	dfs(1,1);
	up(j,1,20)up(i,1,n)fa[i][j]=fa[fa[i][j-1]][j-1];
	m=read();
	up(i,1,m)
	{
		int x=read(),y=read();
		int qwq=lca(x,y);
		if(dfn[x]>dfn[y])swap(x,y);
		R[dfn[x]].push_back(dfn[y]);
		if(dep[qwq]<dep[x])f[x].push_back(qwq);
		if(dep[qwq]<dep[y])f[y].push_back(qwq);
	}
	dfs2(1);
	up(j,1,20)up(i,1,n)ft[i][j]=ft[ft[i][j-1]][j-1];
	int T=read();
	up(i,1,T)
	{
		int x,y;
		x=read(),y=read();
		int qwq=lca(x,y);
		node X=qry2(x,qwq);
		node Y=qry2(y,qwq);
		if(X.b==-1||Y.b==-1)
		{
			ans[i]=-1;
			continue;
		}
		if(x==qwq||y==qwq)
		{
			ans[i]=X.b+Y.b+1;
			continue;
		}
		ans[i]=X.b+Y.b+2;
		x=X.a;
        y=Y.a;
        if(dfn[x]>dfn[y])swap(x,y);
        q[dfn[x]-1].push_back((node){y,-i});
        q[dfn[x]-1+siz[x]].push_back((node){y,i});
	}
	
	
	
// ans (ans2[i]>0) 
	
	
	
	up(i,1,n)
	{
		for(int j=0;j<R[i].size();++j)
		{
			upt(R[i][j]);
		}
		for(int j=0;j<q[i].size();++j)
		{
			int nw=(q[i][j].b>0?1:-1);
			int s=q[i][j].a,t=q[i][j].b*nw;
			ans2[t]+=-1*nw*(qry(dfn[s]-1)-qry(dfn[s]-1+siz[s]));
		}
	}
	up(i,1,T)
	{
		printf("%d\n",ans[i]-(ans2[i]>0));
	}
}