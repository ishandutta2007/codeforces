//This code is made by Yiran Empty.
//GrandMaster When??

//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")
#include <bits/stdc++.h>
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
const int maxn=1e6+10;
int dp[maxn][21][2];
int f(int x,int y)
{
	int nw=(1<<x);
	if(y)nw*=3;
	return n/nw;
}
const int mod=1e9+7;
signed main()
{
	int T=1;
	while(T--)
	{
		n=read();
		int lim=log2(n);
		dp[1][lim][0]=1;
		if(n==2)
		{
			cout<<1;
			return 0;
		}
		if((int)log2(n/3)==lim-1)dp[1][(int)log2(n/3)][1]=1;
		up(i,2,n)
		{
			up(j,0,lim)
			{
				dp[i][j][0]=1ll*dp[i-1][j][0]*(f(j,0)-(i-1)+mod)%mod;
				dp[i][j][0]+=1ll*dp[i-1][j+1][0]*(f(j,0)-f(j+1,0)+mod)%mod;
				dp[i][j][0]%=mod;
				dp[i][j][0]+=1ll*dp[i-1][j][1]*(f(j,0)-f(j,1)+mod)%mod;
				
				dp[i][j][1]=1ll*dp[i-1][j][1]*(f(j,1)-(i-1)+mod)%mod;
				dp[i][j][1]+=1ll*dp[i-1][j+1][1]*(f(j,1)-f(j+1,1)+mod)%mod;
				
				dp[i][j][0]%=mod;dp[i][j][1]%=mod;
			}
		}
		cout<<dp[n][0][0];
	}
}
/*
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/