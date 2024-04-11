//This code is made by Yiran Empty.
//GrandMaster When??

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
const int maxn=1e6+10;
vector<int>v[maxn];
int dep[maxn],f[maxn][21];
void dfs(int x,int fa)
{
	f[x][0]=fa;dep[x]=dep[fa]+1;
	up(i,1,20)f[x][i]=f[f[x][i-1]][i-1];
	for(auto to:v[x])if(to!=fa)dfs(to,x);
}
int vis[maxn];
int jump(int x)
{
	int nw=x;
	pu(i,20,0)if(!vis[f[nw][i]])nw=f[nw][i];
	return dep[x]-dep[nw]+1;
}
signed main()
{std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int T=1;
	while(T--)
	{
		cin>>n>>k;
		up(i,1,n-1)
		{
			int x,y;cin>>x>>y;v[x].emplace_back(y);v[y].emplace_back(x);
		}
		dfs(n,0);vis[0]=1;vis[n]=1;
		k=n-k-1;
		pu(i,n-1,1)
		{
			if(vis[i])continue;
			int ff=jump(i);
			if(k>=ff)
			{
				k-=ff;
				int nw=i;
				while(vis[nw]==0)
				{
					vis[nw]=1;
					nw=f[nw][0];
				}
			}
		}
		up(i,1,n)if(!vis[i])cout<<i<<" ";
	}
}
/*
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/