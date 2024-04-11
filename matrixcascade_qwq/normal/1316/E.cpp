//This code is made by Yiran Empty.
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
struct node
{
	int val,id,b[10];
}a[101010];
int cmp(node a,node b)
{
	return a.val>b.val;
}
int dp[101010][(1<<7)+1];
int cnt[1010];
signed main()
{
	int T=1;
	while(T--)
	{
		n=read();
		int p=read(),k=read();
		up(i,1,n)
		{
			a[i].val=read();a[i].id=i;
		}
		up(i,1,n)
		{
			up(j,0,p-1)a[i].b[j]=read();
		}
		m=(1<<p)-1;
		up(i,0,n)up(j,0,m)dp[i][j]=-101010101;
		sort(a+1,a+n+1,cmp);
		up(i,0,1010)cnt[i]=cnt[i>>1]+(i&1);
		up(j,0,m)dp[0][j]=0;
		up(i,1,n)
		{
			up(j,0,m)
			{
				int q1=cnt[j];
				if(q1>i-1)continue;
				int res=i-q1-1;
				if(res>=k)dp[i][j]=dp[i-1][j];
				else dp[i][j]=dp[i-1][j]+a[i].val;
			}
			up(j,0,m)
			{
				up(t,0,p-1)
				{
					if(j&(1<<t))dp[i][j]=max(dp[i][j],dp[i-1][j^(1<<t)]+a[i].b[t]);
				}
			}
			
		}cout<<dp[n][m];
	}
	
}
/*
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/