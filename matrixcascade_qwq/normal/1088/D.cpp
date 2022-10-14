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
int f=0;
void ask(int x,int y)
{
	cout<<"? "<<x<<" "<<y<<endl;cin>>f;return;
}
signed main()
{
	int T=1;
	ask(0,0);
	int q=f;
	while(T--)
	{
		int x=0,y=0;
		pu(i,29,0)
		{
			ask(x^(1<<i),y^(1<<i));
			if(f==q)
			{
				ask(x^(1<<i),y);
				if(f==-1)x^=(1<<i),y^=(1<<i);
			}
			else
			{
				if(q==1)x^=(1<<i);
				else y^=(1<<i);
				ask(x,y);
				q=f;
			}
		}
		cout<<"! "<<x<<" "<<y<<endl;
	}
}
/*
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/