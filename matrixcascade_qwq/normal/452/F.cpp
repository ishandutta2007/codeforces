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
int a[501010];
int p[505050];
signed main()
{
	int T=1;
	while(T--)
	{
		n=read();
		int f=0;
		up(i,1,n)a[i]=read(),p[a[i]]=i;
		up(i,1,n)
		{
			up(j,i+1,min(n,i+10))
			{
				int ps=2*a[j]-a[i];
				if(ps>=1&&ps<=n&&p[ps]>j)f=1;
			}
			down(j,i-1,max(1ll,i-10))
			{
				int ps=2*a[j]-a[i];
				if(ps>=1&&ps<=n&&p[ps]<j)f=1;
			}
			if(f)break;
		}
		if(f)puts("YES");
		else puts("NO");
	}
}