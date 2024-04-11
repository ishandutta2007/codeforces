#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define int long long
#define up(i,x,y) for(int i=x,i##end=y;i<=i##end;++i)
#define down(i,x,y) for(int i=x,i##end=y;i>=i##end;--i)
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
int a[303003];
int b[303030];
int l[303030],r[303030];
signed main()
{
	int T=read();
	while(T--)
	{
		n=read(),k=read();
		up(i,1,k)a[i]=read();up(i,1,n)l[i]=r[i]=b[i]=(1ll<<40);
		up(i,1,k)b[a[i]]=read();
		
		up(i,1,n)l[i]=(i==1?min(l[i],b[i]):min(l[i-1]+1,b[i]));
		down(i,n,1)r[i]=(i==n?min(r[i],b[i]):min(r[i+1]+1,b[i]));
		up(i,1,n)printf("%lld ",min(l[i],r[i]));
	}
}