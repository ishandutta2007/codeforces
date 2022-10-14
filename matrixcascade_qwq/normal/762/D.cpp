//This code is made by Yiran Eaty.
//GrandMaster When??

//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")
#include <bits/stdc++.h>
#define int long long
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
int a[5][101010];
int dp[101010][10];
const int inf=-1e17;
int Max(int a=inf,int b=inf,int c=inf,int d=inf)
{
	return max(max(a,b),max(c,d));
}
signed main()
{	
	int T=1;
	while(T--)
	{
		/*
		1
		2
		3
		123
		321
		*/
		n=read();up(i,1,3)up(j,1,n)a[i][j]=read();
		dp[1][0]=a[1][1];
		dp[1][1]=a[1][1]+a[2][1];
		dp[1][2]=a[1][1]+a[2][1]+a[3][1];
		dp[1][3]=a[1][1]+a[2][1]+a[3][1];
		dp[1][4]=inf;
		if(n==1)
		{
			cout<<dp[1][3];
			continue;
		}
		up(i,2,n)
		{
			if(i==n)
			{
				dp[i][0]=Max(dp[i-1][0]+a[1][i]+a[2][i]+a[3][i],dp[i-1][1]+a[3][i]+a[2][i],dp[i-1][2]+a[3][i],dp[i-1][3]+a[1][i]+a[2][i]+a[3][i]);
				continue;
			}
			dp[i][0]=Max(dp[i-1][0]+a[1][i],dp[i-1][1]+a[1][i]+a[2][i],dp[i-1][2]+a[1][i]+a[2][i]+a[3][i],dp[i-1][4]+a[1][i]+a[2][i]+a[3][i]);
			dp[i][1]=Max(dp[i-1][0]+a[1][i]+a[2][i],dp[i-1][1]+a[2][i],dp[i-1][2]+a[2][i]+a[3][i]);
			dp[i][2]=Max(dp[i-1][0]+a[1][i]+a[2][i]+a[3][i],dp[i-1][1]+a[2][i]+a[3][i],dp[i-1][2]+a[3][i],dp[i-1][3]+a[1][i]+a[2][i]+a[3][i]);
			dp[i][3]=Max(dp[i-1][0],dp[i-1][3])+a[1][i]+a[2][i]+a[3][i];
			dp[i][4]=Max(dp[i-1][4],dp[i-1][2])+a[1][i]+a[2][i]+a[3][i];
		}
		cout<<dp[n][0];
	}
}
/*
	   - clear the a  rrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think coaletely.
	   - ...
*/