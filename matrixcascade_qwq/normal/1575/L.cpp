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
struct node
{
	int p,q;
}a[202020];
int dp[202020];
int cmp(node a,node b)
{
	return a.p<b.p?a.p<b.p:(a.p==b.p&&a.q>b.q);
}
signed main()
{
	int T=1;
	while(T--)
	{
		n=read();
		memset(dp,63,sizeof(dp));
		up(i,1,n)
		{
			int nw=read();
			a[i]=(node){nw,i-nw};
		}
		sort(a+1,a+n+1,cmp);
		up(i,1,n)
		{
			if(a[i].q<0)continue;
			int pos=upper_bound(dp+1,dp+n+1,a[i].q)-dp;
			dp[pos]=a[i].q;
		}
		int w=0;
		up(i,1,n)if(dp[i]!=dp[202019])w=i;cout<<w;
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/