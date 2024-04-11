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
#define graph(i,x) for(int i=head[x];i;i=nxt[i])
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
int w[1010];
signed main()
{
	n=read();
	up(i,1,n)w[i]=read();
	int ans=10100101000001010;
	up(i,2,n)
	{
		int nw=w[i-1]-1,nww=nw;
		int p=0;
		up(j,i,n)
		{
			int t=nw/w[j];
			p+=t;
			nw-=w[j]*t;
			int sum=0;
			int x=nww-nw+w[j];
			up(k,1,n)
			{
				int del=x/w[k];
				sum+=del;
				x-=w[k]*del;
			}
			if(p+1<sum)ans=min(ans,nww-nw+w[j]);
		}
	}
	if(ans==10100101000001010)puts("-1");
	else cout<<ans;
}