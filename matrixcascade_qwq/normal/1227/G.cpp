//This code is made by Yiran Empty.
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
int mp[1111][1111];
struct node
{
	int p,val;
}a[1010];
int cmp(node a,node b)
{
	return a.val<b.val;
}
signed main()
{
	int T=1;
	srand(124203);
	while(T--)
	{
		n=read();up(i,1,n)a[i].val=read(),a[i].p=i;
		sort(a+1,a+n+1,cmp);
		reverse(a+1,a+n+1);
		up(i,1,n)
		{
			int nw=i;
			up(j,1,a[i].val)
			{
				mp[nw][a[i].p]=1;
				nw++;
				if(nw==n+2)nw=1;
			}
		}
		cout<<n+1<<endl;
		up(i,1,n+1)
		{
			up(j,1,n)printf("%d",mp[i][j]);puts("");
		}
	}
}
/*
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/