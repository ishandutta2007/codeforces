/*
FUCK YOU XJOI.
FUCK YOU XJOI.
FUCK YOU XJOI.
FUCK YOU XJOI.
And in that light,I find deliverance.
*/

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
int chk(int x)
{
	if(x==1)return 0;
	if(x==2)return 1;
	for(int i=2;i*i<=x;++i)if(x%i==0)return 0;
	return 1;
}
signed main()
{
	int T=1;
	while(T--)
	{
		n=read(),m=read();
		int nw=n-2;
		int pw=1;
		while(1)
		{
			if(chk(nw+pw))break;
			++pw;
		}
		cout<<pw+nw<<" "<<pw+nw<<'\n';
		up(i,1,n-2)
		{
			cout<<i<<" "<<i+1<<" "<<1<<'\n';
		}
		cout<<n-1<<" "<<n<<" "<<pw<<'\n';
		m-=n-1;
		up(i,1,n-2)
		{
			up(j,i+2,n)
			{
				if(m==0)return 0;
				cout<<i<<" "<<j<<" 1000000000"<<'\n';
				--m;
			}
		}
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/