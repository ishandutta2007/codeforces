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
const int maxn=2e5+10;
int a[maxn];
int b[10000];
int isp(int x)
{
	
	if(x==2)return 1;
	up(i,2,sqrt(x))
	{
		if(x%i==0)return 0;
	}
	return 1;
}
int f[maxn][25];
unordered_map<int,int> cnt;
int dp[maxn][25];

signed main()
{
	int num=0;
	up(i,2,10000)if(isp(i))b[++num]=i;
	int T=read();
	while(T--)
	{
		rdn;rdk;
		upn
		{
			rd(a[i]);
			up(j,1,num)
			{
				while(a[i]%(b[j]*b[j])==0)a[i]/=(b[j]*b[j]);
			}
		}
		
	//	upn opls(a[i]);edl;
		up(i,0,n)
		{
			up(j,0,20)dp[i][j]=100000000ll;
		}
	
		up(t,0,k)
		{
			int l=1;
			int nw=0;
			upn
			{
				cnt[a[i]]++;
				if(cnt[a[i]]>1)++nw;
				if(nw<=t)
				{
					f[i][t]=l;continue;
				}
				while(nw>t&&l<=n)
				{
					cnt[a[l]]--;
					if(cnt[a[l]]>=1)--nw;
					++l;
				}
				f[i][t]=l;
			}
			
			upn cnt[a[i]]=0;
		}
	//	if(n==200000&&k==20)return 0;
	//	memset(dp,0x3f,sizeof(dp));
		up(i,0,k)dp[0][i]=0;
		up(i,1,n)
		{
			up(j,0,k)
			{
				up(t,0,j)
				{
					chkmin(dp[i][j],dp[f[i][t]-1][j-t]+1);
				}
			}
		}
		int ans=1e9;
		up(i,0,k)chkmin(ans,dp[n][i]);
		opd(ans);edl;
	}
}
/*
1
11 4
6 2 2 8 9 1 3 6 3 9 7
*/
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/