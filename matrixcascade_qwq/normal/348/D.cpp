//MatrixCascade AFO.
//GrandMaster When??

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
const int mod=1e9+7;
const int maxn=3030;
char c[maxn][maxn];
int a[maxn][maxn],dp[maxn][maxn];
int f(int x1,int y1,int x2,int y2)
{
	int ans=0;
	memset(dp,0,sizeof(dp));
	if(a[x1][y1])dp[x1][y1]=1;
	up(i,x1,x2)
	{
		up(j,y1,y2)
		{
			if(a[i][j])(dp[i][j]+=(dp[i-1][j]+dp[i][j-1])%mod)%=mod;
		}
	}
	return dp[x2][y2];
}
signed main()
{
	int T=1;
	while(T--)
	{
		n=read(),m=read();
		up(i,1,n)
		{
			scanf("%s",c[i]+1);
			up(j,1,m)
			{
				if(c[i][j]=='.')a[i][j]=1;
			}
		}
		int ans1=f(1,2,n-1,m)*f(2,1,n,m-1)%mod;
		int ans2=f(1,2,n,m-1)*f(2,1,n-1,m)%mod;
		cout<<(ans1-ans2+mod)%mod;
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/