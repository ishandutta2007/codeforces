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
#define pb push_back
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
int f[555]={1,3,4,5,7,9,13,15,19,27,39,40,57,58,81,85,120,121,174,179,255,260,363,382,537,544,780,805,1146,1169,1632,1718,2415,2447,3507,3622,5154,5260,7341,7730,10866,11011,15780,16298,23190,23669,33033,34784,48894,49549,71007,73340,104352,106510,148647,156527,220020,222970,319530,330029,469581,479294,668910,704371,990087,1003364,1437882,1485130,2113113,2156822,3010092,3169669,4455390,4515137,6470466,6683084,9509007,9705698,13545411,14263510,20049252,20318116,29117094,30073877,42790530,43675640,60954348,64185794,90221631,91431521,131026920,135332446,192557382,196540379,274294563,288836072,405997338,411441844,589621137,608996006,866508216,884431705,1000000001};
int sg[555]={0,1,2,1,2,0,1,2,0,1,2,0,2,1,2,0,2,1,2,0,2,1,2,0,2,1,2,0,2,1,2,0,2,1,2,0,2,1,2,0,2,1,2,0,2,1,2,0,2,1,2,0,2,1,2,0,2,1,2,0,2,1,2,0,2,1,2,0,2,1,2,0,2,1,2,0,2,1,2,0,2,1,2,0,2,1,2,0,2,1,2,0,2,1,2,0,2,1,2,0,2,1};
const int mod=1e9+7;
int w[5],dp[1111][5];int p;
int get(int x,int y)
{
	return ((p-x+p-y)*(p-x-p+y+1)/2)%mod;
}
signed main()
{
	int T=1;
	while(T--)
	{
		rdn;rd(p);
		up(i,0,102)
		{
			if(f[i]>p)break;
			int l=f[i];
			int r=min(p,f[i+1]-1);
			w[sg[i]]+=get(l,r);
			w[sg[i]]%=mod;
		}
		dp[0][0]=1;
		upn
		{
			up(j,0,3)
			{
				up(t,0,2)
				{
					dp[i][j^t]+=dp[i-1][j]*w[t]%mod;
					dp[i][j^t]%=mod;
				}
			}
		}
		int ans=dp[n][3]+dp[n][1]+dp[n][2];
		ans%=mod;
		opl(ans);
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/