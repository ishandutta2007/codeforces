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
const int maxn=4040;
int a[maxn],dp[maxn][maxn],g[maxn][maxn];
void solve(int l,int r)
{
	if(l>r)return;
	int pos=l;
	up(i,l+1,r)if(a[i]<a[pos])pos=i;
	g[l][r]=pos;
	solve(l,pos-1);solve(pos+1,r);
	int L=g[l][pos-1],R=g[pos+1][r];
	up(i,0,n)dp[pos][i]=-1000000000;
	up(i,0,pos-l)
	{
		up(j,0,r-pos)
		{
			dp[pos][i+j+1]=max(dp[pos][i+j+1],dp[L][i]+dp[R][j]-a[pos]*(i*j*2+2*i+2*j-m+1));
			dp[pos][i+j]=max(dp[pos][i+j],dp[L][i]+dp[R][j]-a[pos]*i*j*2);
		}
	}
}
signed main()
{
	int T=1;
	while(T--)
	{
		n=read(),m=read();
		up(i,1,n) a[i]=read();
		solve(1,n);
		cout<<dp[g[1][n]][m];
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/