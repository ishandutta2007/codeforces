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
int a[maxn],dp[maxn];
void dfs(int l,int r,int dep)
{
	if(l>r)return;
	if(l==r)
	{
		dp[l]=dep;
		return;
	}
	int pos=l;
	up(i,l,r)
	{
		if(a[i]>a[pos])pos=i;
	}
	dp[pos]=dep;
	dfs(l,pos-1,dep+1),dfs(pos+1,r,dep+1);
}
signed main()
{
	T=read();
	while(T--)
	{
		n=read();
		up(i,1,n)a[i]=read();
		dfs(1,n,0);
		up(i,1,n)cout<<dp[i]<<" ";
		cout<<endl;
	}
}