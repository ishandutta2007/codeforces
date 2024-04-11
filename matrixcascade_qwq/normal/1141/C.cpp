//MatrixCascade AFO.
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
int a[201010];
int b[202020];
signed main()
{
	int T=1;
	while(T--)
	{
		n=read();
		up(i,1,n-1)a[i]=read();
		int nw=0,pos=1,mx=0;
		up(i,1,n-1)
		{
			nw+=a[i];
			if(nw<mx)
			{
				mx=nw;pos=i+1;
			}
		}
		b[pos]=1;
		pu(i,pos-1,1)b[i]=b[i+1]-a[i];
		up(i,pos+1,n)b[i]=b[i-1]+a[i-1];
		map<int,int>mp;
		up(i,1,n)
		{
			++mp[b[i]];if(mp[b[i]]==2||b[i]>n||b[i]<1)
			{
				cout<<"-1";return 0;
			}
		}
		up(i,1,n)
		{
			cout<<b[i]<<" ";
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