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
int a[500];
int tot=0;
signed main()
{
	int T;rd(T);
	while(T--)
	{
		rd(n);
		if(n==1)
		{
			up(i,1,n)printf("a");
		}
		else if(n&1)
		{
			up(i,1,(n-2)/2)printf("a");
			printf("bc");
			up(i,1,(n-1)/2)printf("a");
		}
		else
		{
			up(i,1,(n-1)/2)printf("a");
			printf("ba");
			up(i,1,(n-1)/2)printf("a");
		}
		puts("");
	}
}