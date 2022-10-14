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
signed main()
{
	int T=read();
	while(T--)
	{
		n=read();
		string s;cin>>s;s=' '+s;
		up(i,1,n)
		{
			if(s[i]=='0')
			{
				if(n%2==1&&i==n/2+1)continue;
				if(i<=n/2)
				{
					printf("%lld %lld %lld %lld\n",i,n,i+1,n);
					error;
				}
				else
				{
					printf("%lld %lld %lld %lld\n",1,i,1,i-1);
					error;
				}
			}
		}
		if(n%2==1)
		{
			if(s[n/2+1]=='0')
			{
				printf("%lld %lld %lld %lld\n",1ll,n/2+1,n/2+1,n);
			}
			else
			{
				printf("%lld %lld %lld %lld\n",1ll,n-1,2ll,n);
			}
		}
		else
		{
			printf("%lld %lld %lld %lld\n",1ll,n-1,2ll,n);
		}
		def;
	}
}
/*
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/