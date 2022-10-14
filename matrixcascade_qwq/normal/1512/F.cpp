//Author:MatrixCascade

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define clr(f, n) memset(f, 0, sizeof(int) * (n))
#define cpy(f, g, n) memcpy(f, g, sizeof(int) * (n))
#define rev(f, n) reverse(f, f + n)
#define pir pair<int, int>
#define mkp make_pair
#define fst it->first
#define sec it->second
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
inline void print(int *f, int len)
{
    for (int i = 0; i < len; i++)
        printf("%lld ", f[i]);
    puts("");
}
int T;
int a[202020],b[202020];
int f[202020],g[202020];
signed main()
{
	int T=read();
	while(T--)
	{
		int c;
		n=read(),c=read();
		up(i,1,n)a[i]=read();
		up(i,1,n-1)b[i]=read();
		int ans=1e15;
		f[0]=0;
		up(i,1,n)
		{
			f[i]=f[i-1];
			g[i]=g[i-1];
			if(g[i-1]<b[i])
			{
				int ze=(b[i]-g[i-1]-1)/a[i]+1;
				f[i]+=ze;
				g[i]+=ze*a[i];
			}
			f[i]++;
			g[i]-=b[i];
		}
		up(i,1,n)
		{
			//cout<<f[i]<<endl;
			int nw=g[i-1];
			int del=c-nw;
			int anss;
			if(del<=0)anss=f[i-1];
			else anss=f[i-1]+(del-1)/a[i]+1;
			ans=min(ans,anss);
		}
		cout<<ans<<endl;
	}
}