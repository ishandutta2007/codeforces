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
const int maxn=10101;
bool e[maxn];
int p[maxn],tot,mu[maxn];
void mobius(int n)
{
	e[1]=1,mu[1]=1;
	up(i,2,n)
	{
		if(!e[i])
		{
			mu[i]=-1;
			p[++tot]=i;
		}
		up(j,1,tot)
		{
			if(p[j]*i>n)break;
			mu[p[j]*i]=i%p[j]==0?0:-mu[i];
			e[p[j]*i]=1;
			if(i%p[j]==0)break;
		}
	}
	int k=0;
}
bitset<7070>g[7070],f[100070],muu[7070];
signed main()
{
	mobius(10000);
	int mx=7000;
	up(i,1,mx)
	{
		for(int j=i;j<=mx;j+=i)
		{
			g[j][i]=1;
			muu[i][j]=(mu[j/i]==0?0:1);
		}
	}
	int T=1;
	while(T--)
	{
		n=read();int q=read();
		while(q--)
		{
			int opt=read(),x=read(),y=read(),z;
			if(opt==2||opt==3)z=read();
			if(opt==1)f[x]=g[y];
			else if(opt==2)f[x]=(f[y]^f[z]);
			else if(opt==3)f[x]=(f[y]&f[z]);
			else if(opt==4)printf("%d",(f[x]&muu[y]).count()%2);
		}
	}
}
/*
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/