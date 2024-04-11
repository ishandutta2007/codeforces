//MatrixCascade AFO.
//qqqqqqqqqqqqqq

#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")
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
ll n, m, k;
ll read()
{
    ll s = 0, f = 1;
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
int head[maxn],to[maxn],nxt[maxn];
ll val[maxn];int tot;
ll g[maxn];
int ch[maxn][2],q[maxn];
ll s[maxn],vl[maxn];
void add(int x,ll y,int z)
{
	to[++tot]=z;
	nxt[tot]=head[x];
	val[tot]=y;
	head[x]=tot;
}
void dfs(int x,ll nw)
{
	g[x]=nw;
	for(int i=head[x];i;i=nxt[i])
	{
		int v=to[i];
		dfs(v,nw^val[i]);
	}
}
int cnt=0;
int f(int x,int y)
{
	if(ch[x][y])return ch[x][y];
	return ch[x][y]=++cnt;
}
signed main()
{
	int T=1;
	while(T--)
	{
		n=read(),k=read();
		up(i,2,n)
		{
			int x=read();
			ll y=read();
			add(x,y,i);
		}
		dfs(1,0);
		ll w=0;
		pu(i,61,0)
		{
			cnt=0;
			memset(ch,0,sizeof(ch));memset(s,0,sizeof(s));
			up(j,1,n)
			{
				q[j]=f(q[j],!!(g[j]&(1ll<<i)));++s[q[j]];
			}
			ll tott=0;
			up(j,1,n)tott+=s[ch[vl[j]][!!(g[j]&(1ll<<i))]];
			up(j,1,n)vl[j]=ch[vl[j]][((!!(g[j]&(1ll<<i)))+(tott<k))%2];
			if(tott<k)
			{
				k-=tott;w+=(1ll<<i);
			}
		}//
		cout<<w;
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/