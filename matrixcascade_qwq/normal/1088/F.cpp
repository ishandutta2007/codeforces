//This code is made by Yiran Empty.
//GrandMaster When??

//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")
#include <bits/stdc++.h>
#define int long long
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
vector<int>v[505050];
int ans=0;int root=1;
int w[505050],f[505050][20];
void dfs(int x,int fa)
{
	f[x][0]=fa;
	int nw=w[fa];
	up(i,1,20)
	{
		f[x][i]=f[f[x][i-1]][i-1];
		if(!f[x][i])
		{
			nw=min(nw,(i+1)*w[root]);
			break;
		}
		nw=min(nw,(i+1)*w[f[x][i]]);
	}
	if(x!=root)ans+=nw,ans+=w[x];
	for(auto to:v[x])
	{
		if(to==fa)continue;
		dfs(to,x);
	}
}
signed main()
{
	int T=1;
	while(T--)
	{
		n=read();
		up(i,1,n)w[i]=read();
		up(i,1,n-1)
		{
			int x=read(),y=read();
			v[x].emplace_back(y);v[y].emplace_back(x);
		}
		
		up(i,2,n)if(w[i]<w[root])root=i;
		dfs(root,0);
		cout<<ans;
	}
}
/*
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/