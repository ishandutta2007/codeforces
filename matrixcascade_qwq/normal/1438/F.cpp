//MatrixCascade AFO.
//qqqqqqqqqqqqqq

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
map<int,int>mp;
signed main()
{
	srand(time(0));
	int T=1;
	while(T--)
	{
		k=read();
		n=(1<<k)-1;
		up(i,1,420)
		{
			int x,y,z;
			x=rand()%n+1;
			y=rand()%n+1;
			while(y==x)y=rand()%n+1;
			z=rand()%n+1;
			while(z==x||z==y)z=rand()%n+1;
			cout<<"? "<<x<<" "<<y<<" "<<z<<'\n';
			fflush(stdout);
			int la;
			cin>>la;
			mp[la]++;
		}
		int p1=0,p2=0;
		up(i,1,n)
		{
			if(mp[i]>mp[p1])p2=p1,p1=i;
			else if(mp[i]>mp[p2])p2=i;
		}
		up(i,1,n)
		{
			if(i==p1||i==p2)continue;
			cout<<"? "<<p1<<" "<<p2<<" "<<i<<endl;
			int la;
			cin>>la;
			if(la==i)
			{
				cout<<"! "<<i<<endl;
				return 0;
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