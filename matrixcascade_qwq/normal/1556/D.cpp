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
int f[202020];
int g[202020];
signed main()
{
	int T=1;
	while(T--)
	{
		n=read(),k=read();
		up(i,2,n)
		{
			cout<<"or 1 "<<i<<endl;
			fflush(stdout);
			f[i]+=read();
			cout<<"and 1 "<<i<<endl;
			fflush(stdout);
			f[i]+=read();
		}
		cout<<"or 2 3"<<endl;
		fflush(stdout);
		f[0]+=read();
		cout<<"and 2 3"<<endl;
		f[0]+=read();
		g[1]=(f[2]+f[3]-f[0])/2;
		up(i,2,n)g[i]=f[i]-g[1];
		sort(g+1,g+n+1);
		cout<<"finish "<<g[k]<<endl;
		fflush(stdout);
	}
}
/*
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/