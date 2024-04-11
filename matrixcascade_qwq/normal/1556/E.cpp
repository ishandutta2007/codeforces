//This code is made by Yiran Empty.
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
const int maxn=2e5+10;
int a[maxn],b[maxn];
int f[maxn],g[maxn];
int st1[maxn][20],st2[maxn][20];
int lg[maxn];
int qry1(int l,int r)
{
	int len=(r-l+1);
	int t=lg[len];
	return max(st1[l][t],st1[r-(1<<t)+1][t])-(g[l-1]-f[l-1]);
}
int qry2(int l,int r)
{
	int len=(r-l+1);
	int t=lg[len];
	return min(st2[l][t],st2[r-(1<<t)+1][t])-(g[l-1]-f[l-1]);
}
signed main()
{
	int T=1;
	while(T--)
	{
		n=read();
		int q=read();
		lg[0]=-1;
		up(i,1,n)lg[i]=(lg[i/2])+1;
		up(i,1,n)
		{
			a[i]=read();
			f[i]=f[i-1]+a[i];
		}
		up(i,1,n)
		{
			b[i]=read();
			g[i]=g[i-1]+b[i];
		}
		up(i,1,n)
		{
			st1[i][0]=st2[i][0]=g[i]-f[i];
		}
		up(j,1,20)
		{
			up(i,1,n-(1<<(j))+1)
			{
				st1[i][j]=max(st1[i][j-1],st1[i+(1<<(j-1))][j-1]);
			}
		}
		up(j,1,20)
		{
			up(i,1,n-(1<<(j))+1)
			{
				st2[i][j]=min(st1[i][j-1],st2[i+(1<<(j-1))][j-1]);
			}
		}
		up(i,1,q)
		{
			int l=read(),r=read();
			if(qry2(l,r)<0||f[r]-f[l-1]!=g[r]-g[l-1])
			{
				puts("-1");
			}
			else
			{
				printf("%lld\n",qry1(l,r));
			}
		}
	}
}
/*
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/