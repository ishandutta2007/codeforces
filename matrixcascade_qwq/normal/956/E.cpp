//This code is made by Yiran Empty.
//GrandMaster When??

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
	int v,id;
}a[10101];
int cmp(node a,node b)
{
	return a.id==b.id?a.v>b.v:a.id<b.id;
}
int dp[101010];
signed main()
{
	int T=1;
	while(T--)
	{
		n=read();int l=read(),r=read();
		int f=0;
		up(i,1,n)a[i].v=read(),f+=a[i].v;
		up(i,1,n)a[i].id=read();
		sort(a+1,a+n+1,cmp);
		up(i,0,f)dp[i]=-1e9;
		dp[f]=0;
		up(i,1,n)
		{
			up(j,0,f-a[i].v)
			{
				dp[j]=max(dp[j],dp[j+a[i].v]+((a[i].id==1)&(j>=l)&(j<=r)));
			}
		}
		int ans=-1e9;
		up(i,0,f)
		{
			ans=max(ans,dp[i]);
		}
		cout<<ans;
	}
}
/*
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/