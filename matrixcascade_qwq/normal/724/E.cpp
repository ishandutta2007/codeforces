//MatrixCascade

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
int a[10100],b[10010];
signed main()
{
	int ans=0,tot=0;;
	n=read();m=read();
	up(i,1,n)a[i]=read(),ans+=a[i];up(i,1,n)b[i]=read();
	up(i,1,n)
	{
		b[i]=m*(n-i)+b[i]-a[i];
	}
	sort(b+1,b+n+1);
	tot=ans;
	up(i,1,n)
	{
		tot=min(tot,ans+=b[i]-m*(i-1));
	}	
	cout<<tot;
}