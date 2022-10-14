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
int a[505050];
const int mod=998244353;
int dp[505050];
int sta[505050],val[505050],top;
signed main()
{
	int T=1;
	while(T--)
	{
		rd(n);upn rd(a[i]);
		dp[0]=1;
		int f=1;
		int w=0;
		upn
		{
			int nw=0;
			while(top&&sta[top]>=a[i])
			{
				w-=sta[top]*val[top]%mod;
				w+=mod;
				w%=mod;
				nw+=val[top];
				--top;
			}
			sta[++top]=a[i];
			int vv=nw;
			if(f==1)
			{
				vv+=dp[i-1]; 
			}
			else vv-=dp[i-1];
			vv+=mod;vv%=mod;
			w+=sta[top]*vv%mod;
			w%=mod;
			if(f==1)
			{
				dp[i]+=w;dp[i]%=mod;
			}
			else
			{
				dp[i]-=w;dp[i]+=mod;dp[i]%=mod;
			}
			f=1-f;val[top]=vv;
		}opl(dp[n]);
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/