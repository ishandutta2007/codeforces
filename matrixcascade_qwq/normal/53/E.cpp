


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
const int maxn=(1<<10)+10;
int dp[maxn][maxn];
int mp[22][22];
int f[maxn];
signed main()
{
//	freopen("A_data.in","r",stdin);
	int T=1;
	while(T--)
	{
		rdn;rdm;rdk;
		up_(m)
		{
			int x=read(),y=read();--x;--y;mp[x][y]=1;mp[y][x]=1;
		//	opls(x);opls(y);edl;
			dp[(1<<x)^(1<<y)][(1<<x)^(1<<y)]=1;
		}
		int msk=(1<<n)-1;
		up(i,1,msk)
		{
			for(int j=i;j;j=(j-1)&i)
			{
				if(!dp[i][j])continue;
				up(t,0,n-1)
				{
					if(i&(1<<t))
					{
					//	if(i==3)cout<<t,edl;
						up(x,0,n-1)
						{
							if(!mp[t][x])continue;
							if(i&(1<<x))continue;
							int to;
							if(j&(1<<t))
							{
							//	dp[i^(1<<x)][j^(1<<t)^(1<<x)]+=dp[i][j];
								to=j^(1<<t)^(1<<x);
							}
							else 
							{
							//	dp[i^(1<<x)][j^(1<<t)]+=dp[i][j];
								to=j^(1<<x);
							} 
						//	cout<<x<<" "<<to<<" "<<((to>>x)),edl;
							if(!((to>>x)^1))dp[i^(1<<x)][to]+=dp[i][j];
						}
					//	break;
					//	continue;
					}
				}
			}
		}
		up(i,1,msk)
		{
			f[i]=f[i>>1]+(i&1);
		}
		int ans=0;
		up(i,1,msk)
		{
			if(f[i]==k)ans+=dp[msk][i];
		}
		opl(ans);edl;
	}
}
/*
4 3 2
1 2
2 3
3 4
*/
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/