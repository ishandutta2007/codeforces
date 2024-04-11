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
#define pii pair<int,int>
#define mkp make_pair
const int maxn=202020;
int w;
vector<pii>v[maxn];
int in[maxn],d[maxn];
void dfs(int x,int fa,int p,int q)
{
	d[p]=q;
	for(auto to:v[x])
	{
		if(to.first==fa)continue;
		q%=w;q++;
		dfs(to.first,x,to.second,q);
	}
}
signed main()
{
	int T=1;
	while(T--)
	{
		n=read(),k=read();
		up(i,1,n-1)
		{
			 int x=read(),y=read();
			 v[x].emplace_back(mkp(y,i));
			 v[y].emplace_back(mkp(x,i));
			 ++in[x];++in[y];
		}
		sort(in+1,in+n+1);
		w=in[n-k];
		dfs(1,0,0,0);
		cout<<w<<endl;
		up(i,1,n-1)
		{
			cout<<d[i]<<" ";
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