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
const int maxn=5050;
int f[maxn][maxn],b[maxn];char c[maxn];
signed main()
{
	int T=1;
	while(T--)
	{
		cin>>c+1;n=strlen(c+1);
		pu(i,n,1)
		{
			up(j,i,n)
			{
				if(i==j)f[i][j]=1;
				else if(j==i+1)f[i][j]=(c[i]==c[j]?2:0);
				else if(f[i+1][j-1]!=0&&c[i]==c[j])f[i][j]=f[i][i+(j-i+1)/2-1]+1;
			}
		}
		up(i,1,n)
		{
			up(j,i,n)
			{
				b[f[i][j]]++;
			}
		}
		pu(i,n-1,0)b[i]+=b[i+1];up(i,1,n)cout<<b[i]<<" ";
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/