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
const int maxn=2e5+10;
pair<int,int>p[maxn];
int f[maxn],c[maxn];
int dfs(int x,int y)
{
	if(c[x])return c[x];
	c[x]=y;
	dfs(f[x<<1]>>1,(f[x<<1]&1^y^1));
	dfs(f[x<<1|1]>>1,(f[x<<1|1]&1^y));
	return y;
}
signed main()
{
	n=read();
	up(i,0,n-1)
	{
		int a,b;
		cin>>a>>b;
		p[i<<1]=make_pair(a,i<<1);
		p[i<<1|1]=make_pair(b+1,i<<1|1);
	}
	sort(p,p+n+n);
	up(i,0,n-1)
	{
		int a=p[i<<1].second,b=p[i<<1|1].second;
		f[a]=b,f[b]=a;
	}
	up(i,0,n-1)
	{
		cout<<(dfs(i,2)^2)<<" ";
	}
}