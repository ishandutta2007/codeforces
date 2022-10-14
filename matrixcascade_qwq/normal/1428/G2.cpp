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
const int maxn=1e6+10;
inline void print(int *f, int len)
{
    for (int i = 0; i < len; i++)
        printf("%lld ", f[i]);
    puts("");
}
int f[10];
int dp[maxn];
void psh(int a,int b)
{
	down(i,1e6,a)dp[i]=max(dp[i],dp[i-a]+b); 
}
void solve(int a,int b)
{
	int nw=min(k,(maxn-10)/a);
	for(int i=1;i<nw;i<<=1)nw-=i,psh(a*i,b*i);
	psh(a*nw,b*nw);
}
signed main()
{
	k=read();up(i,0,5)f[i]=read();
	k=(k-1)*3;
	up(i,1,maxn-9)
	{
		int nw=0,p=i;
		while(p)
		{
			if((p%10)%3==0)dp[i]+=f[nw]*((p%10)/3);
			++nw,p/=10;
		}
	}
	int nw=1;
	up(i,0,5)
	{
		solve(nw*3,f[i]),nw*=10;
	}
	int Q=read();
	while(Q--)
	{
		int u=read();
		printf("%lld\n",dp[u]);
	}
}