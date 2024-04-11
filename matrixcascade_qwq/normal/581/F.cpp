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
vector<int>v[5050];
int dp[5050][5050][2],pre[5050][2];
int siz[5050],b[5050];
void dfs(int x,int fa)
{
	if(v[x].size()==1)
	{
		siz[x]=1;b[x]=1;
		dp[x][0][0]=dp[x][1][1]=0;
		return;
	}
	
	int w=0;
	fp v[x] pf
	{
		if(to==fa)continue;
		dfs(to,x);
		siz[x]+=siz[to];
		if(!w)
		{
			up(i,0,siz[to])
			{
				dp[x][i][0]=min(dp[to][i][0],dp[to][i][1]+1);
				dp[x][i][1]=min(dp[to][i][0]+1,dp[to][i][1]);
			}
		}
		else
		{
			pu(i,siz[x],0)
			{
				pre[i][0]=dp[x][i][0];
				pre[i][1]=dp[x][i][1];
				dp[x][i][0]=dp[x][i][1]=1e10;
			}
			
			pu(i,siz[x],0)
			{
				up(j,0,min(i,siz[to]))
				{
					dp[x][i][0]=Min(dp[x][i][0],pre[i-j][0]+dp[to][j][0],pre[i-j][0]+dp[to][j][1]+1);
					dp[x][i][1]=Min(dp[x][i][1],pre[i-j][1]+dp[to][j][0]+1,pre[i-j][1]+dp[to][j][1]);
				}
			}
		}
		
		w=1;
	}
}
signed main()
{
	int T=1;
	while(T--)
	{
		rdn;
		up_(n-1)
		{
			int x,y;rd(x);rd(y);
			v[x].ep(y);v[y].ep(x);
		}
		memset(dp,0x3f,sizeof(dp));
		int rt=1;
		while(v[rt].size()==1)++rt;
		assert(rt<=n);
		dfs(rt,0);
	//	opl(siz[rt]);edl;
	//	opl(siz[5]);edl;
	//	opl(dp[5][3][0]);edl;
		opl(min(dp[rt][siz[rt]/2][0],dp[rt][siz[rt]/2][1]));
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/