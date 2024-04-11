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
#define rd(x) x=read()
#define op(x) printf("%lld",x)
#define ops(x) printf("%lld ",x)
#define ver(x) for(int i=head[x];i;i=nxt[i])
#define up(i,x,y) for(int i=x,i##end=y;i<=i##end;++i)
#define down(i,x,y) for(int i=x,i##end=y;i>=i##end;--i)
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
signed main()
{
int T;rd(T);
	while(T--)
	{
		rd(n);rd(m);m++;
		if(n>m)puts("0");
		else
		{
			int nw=0;
			down(i,29,0)
			{
				if((n&(1<<i))&&!(m&(1<<i)))
				{
					cout<<nw<<'\n';
					goto gg;
				}
				if(!(n&(1<<i))&&(m&(1<<i)))
				{
					nw|=(1<<i);
				}
			}
			cout<<nw<<'\n';
			gg:;
		}
	}
}