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
const int maxn=2e5+10;
int a[maxn],lsh[maxn],b[maxn],c[maxn],d[maxn],e[maxn];
int q[maxn],tot;
signed main()
{
	T=read();
	while(T--)
	{
		n=read();
		tot=0;
		up(i,1,n)a[i]=read(),lsh[i]=a[i],b[i]=c[i]=d[i]=e[i]=0;
		sort(a+1,a+n+1);
		int nw=unique(a+1,a+n+1)-a-1;
		up(i,1,n)
		{
			lsh[i]=lower_bound(a+1,a+nw+1,lsh[i])-a;
		}
		up(i,1,n)
		{
			a[i]=lsh[i];
		}
		up(i,1,n)b[a[i]]++;
		up(i,1,n)c[b[i]]++;
		up(i,1,n)
		{
			while(c[i])
			{
				--c[i];
				q[++tot]=i;
			}
		}
		sort(q+1,q+tot+1);
		int x=0,y=n,mn=1010010;
		up(i,1,tot)
		{
			mn=min(mn,x+y-(tot-i+1)*q[i]);
			x+=q[i];
			y-=q[i];
		}
		cout<<mn<<endl;
	}
}