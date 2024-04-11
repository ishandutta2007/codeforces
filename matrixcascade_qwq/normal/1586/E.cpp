//MatrixCascade AFO.
//GrandMaster When??

//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
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
const int maxn=6e5+10;
int head[maxn],to[maxn],nxt[maxn],tot,vis[maxn];
int c[maxn],dep[maxn];
int f[303030][20];
vector<int>v[maxn];
void add(int a,int b)
{
	to[++tot]=b;
	nxt[tot]=head[a];
	head[a]=tot;
}
void add2(int a,int b)
{
	v[a].emplace_back(b);v[b].emplace_back(a);
}
void dfs(int x)
{
	vis[x]=1;
	for(int i=head[x];i;i=nxt[i])
	{
		int vv=to[i];
		
		if(vis[vv])continue;
//		cout<<x<<" qwq "<<vv<<endl;
		add2(x,vv);
		dfs(vv);
	}
}
void dfs2(int x,int fa)
{
	f[x][0]=fa;
	dep[x]=dep[fa]+1;
	up(i,1,19)f[x][i]=f[f[x][i-1]][i-1];
	for(auto vv:v[x])
	{
		if(vv==fa)continue;
		dfs2(vv,x);
	}
}
void dfs3(int x,int fa)
{
//	cout<<x<<" 1111\n";
	for(auto vv:v[x])
	{
		if(vv==fa)continue;
		dfs3(vv,x);
		c[x]+=c[vv];
//		c[x]%=2;
	}
}
int lca(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	pu(i,19,0)if(dep[f[x][i]]>=dep[y])x=f[x][i];
	if(x==y)return x;
	pu(i,19,0)if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
	return f[x][0];
}vector<int>ans[303030];
int qwq[303030];
signed main()
{
	int T=1;
	while(T--)
	{
		n=read(),m=read();
		up(i,1,m)
		{
			int x=read(),y=read();
			add(x,y);add(y,x);
		}
		dfs(1);
		dfs2(1,0);
		int q=read();
		int nw=1;
		int qq=q;
		while(q--)
		{
			int x=read(),y=read();
			//int la=lca(x,y);
			++c[x];++c[y];//--c[la];--c[la];
			int la=lca(x,y);
			int p1=x;
			while(1)
			{
				if(p1==la)break;
				ans[nw].emplace_back(p1);
				p1=f[p1][0];
			}
			vector<int>g;
			int p2=y;
	//		++c[la];
			while(1)
			{
				if(p2==la)break;
				g.emplace_back(p2);
				p2=f[p2][0];
			}
	//		cout<<la<<endl;
			reverse(g.begin(),g.end());
			ans[nw].emplace_back(la);
			for(auto to:g)
			{
				ans[nw].emplace_back(to);
			}
			++nw;
		}
	//	dfs3(1,0);
		int w=0;
		up(i,1,n)
		{
		//	c[i]%=2;
		//	cout<<c[i]<<" qwq \n";
			if(c[i]%2==1)++w;
		}
		if(w>0)
		{
			NO;
			cout<<w/2;
		}
		else
		{
			YES;
			up(i,1,qq)
			{
				printf("%d\n",ans[i].size());
				for(auto to:ans[i])
				{
					printf("%d ",to);
				}
				puts("");
			}
		}
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/