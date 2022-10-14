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
int a[maxn];
signed main()
{
	T=read();
	while(T--)
	{
		n=read();
		up(i,1,n)a[i]=read();
		int c0=0,c1=0,c2=0;
		up(i,1,n)
		{
			if(a[i]%3==0)++c0;
			else if(a[i]%3==1)++c1;
			else ++c2;
		}
		int w=n/3;
		int mx=max(c0,max(c1,c2));
		int ans=0;
		if(mx==c0)
		{
			int del=c0-w;
			ans+=del;
			c1+=del;
			if(c1>w)ans+=c1-w;
			else ans+=(w-c1)*2;
		}
		else if(mx==c1)
		{
			int del=c1-w;
			ans+=del;
			c2+=del;
			if(c2>w)ans+=c2-w;
			else ans+=(w-c2)*2;
		}else
		{
			int del=c2-w;
			ans+=del;
			c0+=del;
			if(c0>w)ans+=c0-w;
			else ans+=(w-c0)*2;
		}
		cout<<ans;
		puts("");
	}
}