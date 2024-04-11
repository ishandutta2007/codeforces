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
int a[1010100];
int b[1010000];
int c[1010001];
signed main()
{
	int T=1;
	while(T--)
	{
		int t=read();
		int mx=-1;
		up(i,1,t)a[i]=read(),b[a[i]]++,mx=max(mx,a[i]);
		if(t==1)
		{
			if(a[1]==0)
			{
				cout<<"1 1\n1 1";
			}
			else puts("-1");
			continue;
		}
		sort(a+1,a+t+1);
		int x=0,y;
		up(i,1,t)
		{
			if(b[i]<i*4)
			{
				x=i;
				break;
			}
		}
		up(i,1,t)
		{
			if(t%i==0)
			{
				n=i,m=t/i;
				y=n+m-x-mx;
				memset(c,0,sizeof(c));
				if(abs(n-x)+abs(y-m)!=mx)continue;
				up(j,1,n)up(k,1,m)c[abs(x-j)+abs(y-k)]++;
				int flag=1;
				up(j,0,t)
				{
					if(c[j]!=b[j])
					{
						flag=0;break;
					}
				}
				if(flag)
				{
					cout<<n<<" "<<m<<endl<<x<<" "<<y;
					goto gg;
				}
			}
		}puts("-1");
		gg:;
		//n+m-x-y=mx
	}
}
/*
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/