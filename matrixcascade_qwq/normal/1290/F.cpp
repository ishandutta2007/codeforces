//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")
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
const int mod=998244353;
int x[10],y[10];
int dp[32][25][25][25][25][2][2];
// p x  xxx  xy... f1 p >m or <=mf2 
int dfs(int p,int xx,int xy,int yx,int yy,int f1,int f2)
{
//	cout<<p;edl;
	if(p==30)
	{
	//	cout<<xx<<" "<<xy<<" "<<yx<<" "<<yy;edl;
		if(xx==0&&xy==0&&yx==0&&yy==0&&f1==0&&f2==0)
		{
			return 1;
		}
		return 0;
	}
	if(dp[p][xx][xy][yx][yy][f1][f2]!=-1)return dp[p][xx][xy][yx][yy][f1][f2];
	int &w=dp[p][xx][xy][yx][yy][f1][f2];
	dp[p][xx][xy][yx][yy][f1][f2]=0; 
	w=0;
	up(i,0,(1<<n)-1)
	{
		int X1=xx,X2=xy,Y1=yx,Y2=yy;
		up(j,0,n-1)
		{
			if(!(i&(1<<j)))continue;
			if(x[j]<0)
			{
				X2-=x[j];
			}
			else X1+=x[j];
			if(y[j]<0)
			{
				Y2-=y[j];
			}
			else Y1+=y[j];
		}
	//	assert(X1>=0);assert(X2>=0);assert(Y1>=0);assert(Y2>=0);
		int ff1=0,ff2;
		if(((X1&1)!=(X2&1))||((Y1&1)!=(Y2&1)))continue;
		if(m&(1ll<<p))
		{
			if(f1)
			{
				if(X1&1)
				{
					ff1=1;
				}
				else ff1=0;
			}
			else
			{
				ff2=0;
			}
			if(f2)
			{
				if(Y1&1)
				{
					ff2=1;
				}
				else ff2=0;
			}
			else
			{
				ff2=0;
			}
		}
		else
		{
			if(f1)
			{
				ff1=1;
			}
			else
			{
				if(X1&1)
				{
					ff1=1;
				}
				else
				{
					ff1=0;
				}
			}
			if(f2)
			{
				ff2=1;
			}
			else
			{
				if(Y1&1)
				{
					ff2=1;
				}
				else
				{
					ff2=0;
				}
			}
		}
		
		dp[p][xx][xy][yx][yy][f1][f2]+=dfs(p+1,X1/2,X2/2,Y1/2,Y2/2,ff1,ff2);w%=mod;
	}
	return dp[p][xx][xy][yx][yy][f1][f2];
}
signed main()
{
	int T=1;
	while(T--)
	{
		rdn;rdm;
		up(i,0,n-1)rd(x[i]),rd(y[i]);
		memset(dp,-1,sizeof(dp));
		int ans=dfs(0,0,0,0,0,0,0);
		ans--;ans+=mod;ans%=mod;
		opd(ans);
	}
}
/*
4 1000000000
-2 4
2 -3
0 -4
-1 -3
1 3 
*/
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/