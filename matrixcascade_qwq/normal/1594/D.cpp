//MatrixCascade AFO.
//GrandMaster When??

//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define int long long
#define YES puts("YES")
#define NO puts("NO")
#define Yes puts("Yes")
#define No puts("No")
#define edl puts("")
#define mc cerr<<"qwq\n"
#define error goto gg
#define def gg:
#define rd(x) x=read()
#define opl(x) printf("%lld",x)
#define opls(x) printf("%lld ",x)
#define opd(x) printf("%d",x)
#define opds(x) printf("%d ",x)
#define ver(x) for(int i=head[x];i;i=nxt[i])
#define up(i,x,y) for(int i=x,i##end=y;i<=i##end;++i)
#define pu(i,x,y) for(int i=x,i##end=y;i>=i##end;--i)
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
char c[101];
int fa[202020],siz[202020];
int de[202020];
int find(int x)
{
	return fa[x]==x?fa[x]:fa[x]=find(fa[x]);
}
#define pii pair<int,int>
#define mkp make_pair
int vis[202020],col[202020];
int ff=1;
int b[2];vector<int>g[202020];
void dfs(int x,int c)
{
	vis[x]=1;
	col[x]=c;
	b[col[x]]+=siz[x];
	for(auto to:g[x])
	{
		if(vis[to])
		{
			if(col[to]+col[x]!=1)
			{
				ff=0;
			}
		}
		else
		{
			dfs(to,c^1);
		}
	}
}

signed main()
{
	int T=read();
	while(T--)
	{
		ff=1;
		n=read(),m=read();
		vector<pii>v;
		map<pii,int>mp;
		up(i,1,n)fa[i]=i,siz[i]=1,de[i]=0,g[i].clear(),vis[i]=col[i]=0;
		up(i,1,m)
		{
			int x=read(),y=read();
			scanf("%s",c+1);
			if(c[1]=='i')
			{
				v.emplace_back(mkp(x,y));
			}
			else
			{
				int fx=find(x),fy=find(y);
				if(fx!=fy)
				{
					fa[fx]=fy;
					
					siz[fy]+=siz[fx];
					siz[fx]=0;
				}
			}
		}
		int f=1;
		for(auto x:v)
		{
			int p=x.first,q=x.second;
			p=find(p),q=find(q);
			g[p].emplace_back(q);g[q].emplace_back(p);
		}
		int ans=0;
		up(i,1,n)
		{
			if(fa[i]!=i)continue;
			if(vis[i])continue;
			b[0]=b[1]=0;
			dfs(i,0);
			ans+=max(b[0],b[1]);
		}
		if(ff)printf("%lld\n",ans);
		else puts("-1");	
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/