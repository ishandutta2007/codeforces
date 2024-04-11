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
#define int unsigned int
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
int f[1010001],a[1000001];
signed main()
{
	int p,q;
	cin>>n>>p>>q;
	if(n-1<p)p=n-1;
	f[0]=1;
	up(i,1,p)
	{
		a[i]=n-i+1;
		int nw=i;
		up(j,1,i)
		{
			int pw=__gcd(nw,a[j]);
			nw/=pw;
			a[j]/=pw;
		}
		f[i]=1;
		up(j,1,i)f[i]*=a[j];
	}
	int ans=0;
	up(i,1,q)
	{
		int nw=1,sum=0;
		for(int j=0;j<=p;++j,nw*=i)sum+=f[j]*nw;
		ans^=(sum*i);
	}
	cout<<ans;
}