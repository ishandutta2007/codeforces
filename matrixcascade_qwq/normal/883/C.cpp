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
signed main()
{
	int T=1;
	while(T--)
	{
		int f=read(),T=read(),t0=read();
		int a1=read(),t1=read(),p1=read();
		int a2=read(),t2=read(),p2=read();
		int mn=1e15;
		if(t1>t2)swap(a1,a2),swap(p1,p2),swap(t1,t2);
		for(int i=0;((i-1)*a1)<=f;++i)
		{
			int rf=f-i*a1,rt=T-min(i*a1,f)*t1;
			if(rf<0)rf=0;
			if(rf==0)
			{
				if(rt<0);
				else mn=min(mn,i*p1);break;
			}
			if(t0*rf>rt&&t2*rf>rt)continue;
			if(t0*rf<=rt)mn=min(mn,i*p1); 
			else
			{
				
				int tim=rt-t0*rf;
				tim/=(t2-t0);
				if((rt-t0*rf)%(t2-t0))++tim;
				int w=tim/a2;
				if(tim%a2)++w;
				mn=min(mn,i*p1+w*p2);
			}
		}
		if(mn==1e15)puts("-1");
		else cout<<mn;
	}
}
/*
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/