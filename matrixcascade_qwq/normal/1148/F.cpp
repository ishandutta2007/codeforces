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
int n, k;
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
int v[303030],m[303030];
int b[303030];
signed main()
{
	int sum=0;
	n=read();
	up(i,1,n)
	{
		v[i]=read();
		m[i]=read();
		sum+=v[i];
	}
	if(sum<0)
	{
		up(i,1,n)v[i]*=-1;
	}
	up(i,1,n)
	{
		for(int j=m[i];j;j>>=1)++b[i];
	}
	int ans=0;
	up(i,0,62)
	{
		int sum=0;
		up(j,1,n)if(b[j]==i+1)sum+=v[j];
		if(sum>0)
		{
			ans|=1ll<<i;up(j,1,n)if((m[j]>>i)&1)v[j]*=-1;
		}
	}
	cout<<ans;
	
}