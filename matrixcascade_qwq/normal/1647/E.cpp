//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")
#include <bits/stdc++.h>
#include<conio.h>
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
#define ft(x) for(int i=head[x];i;i=nxt[i])
#define upn up(i,1,n)
#define upm up(j,1,m)
#define pun pu(i,n,1)
#define pum pu(j,m,1)
#define up_(x) up(i,1,x)
#define pu_(x) pu(j,x,1)
#define ep emplace_back
#define fp for(auto to:
#define pf )
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define mkp make_pair
#define fi first
#define se second
#define mii map<int,int>
#define mis map<int,string>
#define msi map<string,int>
#define mvi map<vector<int>,int>
#define miv map<int,vector<int>>
#define rdn rd(n)
#define rdm rd(m)
#define rdk rd(k)
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
void chkmin(int &x,int y)
{
	if(x>y)x=y;
}
void chkmax(int &x,int y)
{
	if(x<y)x=y;
}
const int maxn=101010;
int p[maxn],a[maxn],col[maxn];
int b[maxn],bb[maxn],tot;
vector<int>v[maxn],e[maxn];
int vis[maxn],dis[maxn],g[maxn],ed[maxn],num[maxn];
int fa[maxn][31];
int ans[maxn],fw[maxn];
set<int>ss;
signed main()
{
	int T=1;
	while(T--)
	{
		rdn;
		upn rd(p[i]);
		upn rd(a[i]);
		
//		upn rd(b[i]);
		
		int mx=-1;
		upn mx=max(mx,a[i]);
		int gap=0;
		upn bb[p[i]]++;
		upn if(bb[i]==0)gap++;
	//	opl(gap);edl;
		int turn=(mx-n)/gap;
//	if(n==96969)return 0;
	//	opl(turn);edl;
		upn fa[i][0]=p[i];
		up(i,1,30)
		{
			up(j,1,n)
			{
				fa[j][i]=fa[fa[j][i-1]][i-1];
			}
		}
		upn
		{
			ed[i]=i;
			int fw=turn;
			up(j,0,30)if(turn&(1<<j))ed[i]=fa[ed[i]][j];
		}
		upn
		{
			e[ed[i]].ep(i);
		}
		upn
		{
			if(e[i].size()==0)continue;
			sort(e[i].begin(),e[i].end());
		}
		upn ss.insert(i);
		upn
		{
			if(e[i].size()==0)continue;
			up(j,1,(int)e[i].size()-1)
			{
				fw[e[i][j]]=a[i];
			}
			ans[e[i][0]]=a[i];ss.erase(a[i]);
		}
	//	upn cout<<ed[i]<<" ";edl;
		upn
		{
			if(fw[i])
			{
				ans[i]=*ss.lower_bound(fw[i]);
				ss.erase(ans[i]);
			}
		}
		upn opds(ans[i]);edl;
	}
}
/*
10
10 8 5 3 7 8 6 6 1 1
5 26 24 27 21 4 18 2 28 1
5 4 2 6 7 8 3 9 1 10 

  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/