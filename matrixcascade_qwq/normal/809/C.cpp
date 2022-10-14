//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")
#include <bits/stdc++.h>
#define ll long long
#define int long long
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
const int mod=1e9+7;
void add(int &x,int y)
{
	x+=y;if(x>=mod)x-=mod;
}
void sub(int &x,int y)
{
	x-=y;if(x<0)x+=mod;
}
int dp[34][2][2][2],f[34][2][2][2];
int dpdp(int x,int y,int k)
{
	if(x<0||y<0)return 0;
//	cout<<x<<" "<<y;edl;
	memset(dp,0,sizeof(dp));memset(f,0,sizeof(f));
	dp[0][0][0][0]=1;
	up(i,1,32)
	{
		int id=i-1;
		int rx=(x>>id)&1,ry=(y>>id)&1,rk=(k>>id)&1;
		up(px,0,1)
		{
			up(py,0,1)
			{
				up(pk,0,1)
				{
					if(!dp[i-1][px][py][pk]&&!f[i-1][px][py][pk])continue;
					up(nx,0,1)
					{
						up(ny,0,1)
						{
							int nk=nx^ny;
							int tx,ty,tk;
							tx=ty=tk=0;
							if(px==0)
							{
								if(nx>rx)tx=1;
								else tx=0;
							}
							else
							{
								if(nx<rx)tx=0;
								else tx=1;
							}///qwqwqwqwq
							if(py==0)
							{
								if(ny>ry)ty=1;
								else ty=0;
							}
							else
							{
								if(ny<ry)ty=0;
								else ty=1;
							}///qwqwqwqwq
							if(pk==0)
							{
								if(nk>rk)tk=1;
								else tk=0;
							}
							else
							{
								if(nk<rk)tk=0;
								else tk=1;
							}
							if(i==3)
							{
								if(tx==0&&ty==0&&tk==0)
								{
//									mc;
//									cout<<nx<<" "<<ny<<" "<<nk;edl;
//									cout<<rx<<" "<<ry<<" "<<rk;edl;
//									cout<<px<<" "<<py<<" "<<pk;edl;
								}
							}
							add(dp[i][tx][ty][tk],dp[i-1][px][py][pk]);
							add(f[i][tx][ty][tk],f[i-1][px][py][pk]);
							add(f[i][tx][ty][tk],nk*(1<<id)*dp[i-1][px][py][pk]%mod);
						}
					} 
				}
			}
		}
	}
//	cout<<dp[4][0][0][0];edl;
	int ans=dp[32][0][0][0];
	add(ans,f[32][0][0][0]);
	return ans;
}
int solve(int l1,int r1,int l2,int r2,int k)
{
	int ans=0;add(ans,dpdp(l2,r2,k));
	add(ans,dpdp(l1-1,r1-1,k));
	sub(ans,dpdp(l1-1,r2,k));
	sub(ans,dpdp(l2,r1-1,k));
	return ans;
}
signed main()
{
	int T=read();
	while(T--)
	{
		int xl,yl,xr,yr;
		rd(xl);rd(yl);rd(xr);rd(yr);rdk;
		--xl;--yl;--xr;--yr;--k;
		int anss=solve(xl,yl,xr,yr,k);
		opl(anss);edl;
	}
}
/*
1
1 4 2 5 2
*/
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/