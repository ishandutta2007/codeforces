//This code is made by Yiran Empty.
//GrandMaster When??

//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")
#include <bits/stdc++.h>
#define int long long
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
struct node
{
	int v,id;
}a[101010];
int cmp(node a,node b)
{
	return a.v<b.v;
}
int f[101001],g[101000];
signed main()
{
	int T=1;
	while(T--)
	{
		n=read();up(i,1,n)a[i].v=read(),a[i].id=i;
		sort(a+1,a+n+1,cmp);
		int r=(n%3==0)?n/3:n/3+1;
		up(i,1,r)f[a[i].id]=i-1,g[a[i].id]=a[i].v-f[a[i].id],swap(f[a[i].id],g[a[i].id]);
		up(i,r+1,n-r)f[a[i].id]=i-1,g[a[i].id]=a[i].v-f[a[i].id];
		up(i,n-r+1,n)f[a[i].id]=n-i,g[a[i].id]=a[i].v-f[a[i].id];
		YES;
		up(i,1,n)
		{
			printf("%lld ",f[i]);
		}
		puts("");
		up(i,1,n)printf("%lld ",g[i]);
	}
}
/*
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/