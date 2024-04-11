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
vector<int>v[202002];
const int maxn=2e5+10;
int cnt,dfn[maxn],siz[maxn],dep[maxn],f[maxn],mx[maxn];
int son[maxn],t[maxn];
int p,q;
int d;
void dfs1(int x,int fa)
{
	dfn[x]=++cnt;
	siz[x]=1;
	dep[x]=mx[x]=dep[fa]+1;
	f[x]=fa;
	for(auto to:v[x])
	{
		if(to==fa)continue;
		dfs1(to,x);
		siz[x]+=siz[to];
		mx[x]=max(mx[x],mx[to]);if(siz[to]>siz[son[x]]&&mx[to]>=d)son[x]=to;
	}
}
void ask1(int x)
{
	cout<<"d "<<x<<endl;
	cin>>p;
}
void ask2(int x)
{
	cout<<"s "<<x<<endl;
	cin>>q;
}
signed main()
{
	int T=1;
	while(T--)
	{
		n=read();
		up(i,1,n-1)
		{
			int x=read(),y=read();
			v[x].emplace_back(y);v[y].emplace_back(x);
		}
		ask1(1);
		d=p+1;
		dfs1(1,0);
		int nw=1;
		while("SyadouHayaminz")
		{
			if(dep[nw]!=d)
			{
				t[dep[nw]]=nw;
				nw=son[nw];
				continue;
			}
			ask1(nw);
			if(p==0)
			{
				cout<<"! "<<nw<<endl;
				return 0;
			}
			nw=t[dep[nw]-(p/2)];
			ask2(nw);
			nw=q;
			if(dep[nw]==d)
			{
				cout<<"! "<<nw<<endl;
				t[dep[nw]]=nw;
				nw=son[nw];
				return 0;
			}
		}
	}
}
/*
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/