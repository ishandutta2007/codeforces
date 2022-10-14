//Author : MatrixCascade

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
#define L long double
int c[202];
double f[202][10101];
signed main()
{
	n=read();
	int x=read();
	double p=1.0*x/2;
	up(i,1,n)c[i]=read();
	up(i,1,n)
	{
		m+=c[i];
	}
	f[0][0]=1;
	double ans=0;
	up(i,1,n)
	{
		down(j,i,1)
		{
			up(k,c[i],m)
			{
				f[j][k]=f[j][k]+f[j-1][k-c[i]]*j/(1.0*(n-j+1));
			}
		}
	}
	up(i,1,n)
	{
		up(j,0,m)
		{
			ans+=f[i][j]*min((1.0*n/i+1)*p,1.0*j/i);
		}
	}
	printf("%.10lf",ans);
}