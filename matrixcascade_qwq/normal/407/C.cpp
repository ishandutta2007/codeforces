//This code is made by Yiran Empty.
//GrandMaster When??
 
#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")
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
int c[105050][111];
int f[100505][111];
int a[105050];
const int mod=1e9+7;
signed main()
{
    int T=1;
    c[0][0]=1;
    up(i,1,100100)
    {
        c[i][0]=1;
        up(j,1,min(110ll,i))c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
    }
    while(T--)
    {
        n=read(),m=read();
        up(i,1,n)a[i]=read();
        up(i,1,m)
        {
            int l=read(),r=read(),k=read();
            up(j,0,k)(f[l][j]+=c[k][k-j])%=mod,(f[r+1][j]+=mod-c[k+r-l+1][k-j])%=mod;
        }
    }
    pu(j,107,0)
    {
        up(i,1,n)
        {
            f[i][j]+=f[i-1][j];f[i][j]+=f[i-1][j+1];
            f[i][j]%=mod;
        }
    }
    up(i,1,n)printf("%lld",(a[i]+f[i][0])%mod),cout<<" ";
}
/*
5 3
1 4 3
2 5 0
3 4 2
*/
/*
       - clear the arrays if a problem has many tasks.
       - pay attention to some special cases(n=0,1).
       - Don't code before think completely.
       - ...
*/