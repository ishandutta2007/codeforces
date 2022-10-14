//MatrixCascade AFO.
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
void print(int t,int x)
{
	up(i,1,x)cout<<t<<" ";
}
int a[2020];
signed main()
{
	int T=1;
	while(T--)
	{
		n=read();
		int pos=1;
		up(i,2,n)
		{
			cout<<"? ";
			print(1,n-1);
			cout<<i<<" ";
			cout<<endl;
			k=read();
			if(k==0)
			{
				continue;
			}
			pos=i;
		}
		a[n]=n-pos+1;
		up(i,1,n)
		{
			if(i==n-pos+1)continue;
			cout<<"? ";
			print(n-pos+1,n-1);
			cout<<i<<endl;
			k=read();
			a[k]=i;
		}
		cout<<"! ";
		up(i,1,n)
		{
			cout<<a[i]<<" ";
			cout<<endl;
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