/*
qwq
*/


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
#define upn up(i,1,n)
#define upm up(j,1,m)
#define pun pu(i,n,1)
#define pum pu(j,m,1)
#define up_(x) up(i,1,x)
#define pu_(x) pu(j,x,1)
#define ep emplace_back
#define fr for(auto to:
#define rf )
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
#define inf 1000000000000000000ll
ll Max(ll a=-inf,ll b=-inf,ll c=-inf,ll d=-inf,ll e=-inf,ll f=-inf,ll g=-inf,ll h=-inf)
{
	return max(max(max(a,b),max(c,d)),max(max(e,f),max(g,h)));
}
ll Min(ll a=inf,ll b=inf,ll c=inf,ll d=inf,ll e=inf,ll f=inf,ll g=inf,ll h=inf)
{
	return min(min(min(a,b),min(c,d)),min(min(e,f),min(g,h)));
}
#undef inf
const int maxn=2e5+10;
vector<int>v[maxn];
int dep[maxn];
void dfs(int x,int fa)
{
//	cout<<x<<" qwq\n";
	dep[x]=dep[fa]+1;
	for(auto to:v[x])
	{
		if(to==fa)continue;
		dfs(to,x);
	}
}
int b[maxn],tot;
int c[maxn],l,vis[maxn],ans[maxn];
signed main()
{
	int T=read();
	while(T--)
	{
		rd(n);
		upn v[i].clear(),ans[i]=vis[i]=dep[i]=0;
		up_(n-1)
		{
			int x,y;rd(x);rd(y);
			v[x].ep(y);v[y].ep(x);
			
		}
		dfs(1,0);
		vector<int>v1,v2;
		upn
		{
			if(dep[i]%2==0)v1.ep(i);
			else v2.ep(i);
		}
		if(v1.size()>v2.size())swap(v1,v2);
		int qw=v1.size();
		tot=0;
		int nw=1;
		int q=n;
		while(1)
		{
			if(q>=nw)
			{
				b[++tot]=nw;
				q-=nw;
			}
			else break;
			nw*=2;
		}
		vector<int>v3,v4;
		pu(i,tot,1)
		{
			if(qw>=b[i])
			{
				qw-=b[i];
				up(j,b[i],b[i]*2-1)
				{
					v3.ep(j);
					vis[j]=1;
				}
			}
		}
		upn
		{
			if(!vis[i])v4.ep(i);
		}
	//	assert(v1.size()==v3.size());
	//	assert(v2.size()==v4.size());
		up(i,0,v1.size()-1)
		{
			ans[v1[i]]=v3[i];
		}
		up(i,0,v2.size()-1)
		{
			ans[v2[i]]=v4[i];
		}
		upn opls(ans[i]);
		edl;
	}
}
/*
1
10
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
*/
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/