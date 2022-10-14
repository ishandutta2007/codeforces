//MatrixCascade AFO.
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
string s[1010100];
int b[1010010];
signed main()
{
	int T=1;
	while(T--)
	{
		n=read(),m=read();
		up(i,1,n)
		{
			cin>>s[i];
			s[i]=" "+s[i];
		}
		up(i,2,n)
		{
			up(j,1,m)
			{
				if(s[i-1][j]=='X'&&s[i][j-1]=='X')b[j]=1;
			}
		}
		up(i,2,m)
		{
			b[i]+=b[i-1];
		}
		int q=read();
		while(q--)
		{
			int l=read(),r=read();;
			int w=b[r]-b[l];
			if(w)NO;
			else YES;
		}
	}
}
/*
?X
X?
*/
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/