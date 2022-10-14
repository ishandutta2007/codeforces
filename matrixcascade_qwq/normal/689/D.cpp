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
int f[maxn][20],g[maxn][20],lg[maxn];
int qry1(int l,int r)
{
	int len=lg[r-l+1];
	return max(f[l][len],f[r-(1<<(len))+1][len]);
}
int qry2(int l,int r)
{
	int len=lg[r-l+1];
	return min(g[l][len],g[r-(1<<(len))+1][len]);
}
#define mid ((l+r)>>1)
signed main()
{
	int T=1;
	while(T--)
	{
		n=read();
		up(i,1,n)a[i]=read(),f[i][0]=a[i];
		lg[0]=-1;
		up(i,1,n)
		{
			g[i][0]=b[i]=read();
			lg[i]=lg[i/2]+1;
		}
		up(i,1,lg[n])
		{
			for(int j=1;j+(1<<i)-1<=n;++j)
			{
				f[j][i]=max(f[j][i-1],f[j+(1<<(i-1))][i-1]);
			}
		}
		up(i,1,lg[n])
		{
			for(int j=1;j+(1<<i)-1<=n;++j)
			{
				g[j][i]=min(g[j][i-1],g[j+(1<<(i-1))][i-1]);
			}
		}
		int ans=0;
		up(i,1,n)
		{
			int ql,qr;
			int l=i,r=n;
			while(l<=r)
			{
				if(qry1(i,mid)>=qry2(i,mid))
				{
					r=mid-1;
				}else l=mid+1;
			}
			ql=l;
			l=i;r=n;
			while(l<=r)
			{
				if(qry1(i,mid)>qry2(i,mid))
				{
					r=mid-1;
				}else l=mid+1;
			}
			qr=r;
			ans+=(qr-ql+1);
		}
//		cout<<qry2(1,1)<<" "<<g[1][0]<<'\n';
		cout<<ans;
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/