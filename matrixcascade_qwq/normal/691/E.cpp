//MatrixCascade AFO.
//qqqqqqqqqqqqqq

//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define int long long
#define YES puts("YES")
#define NO puts("NO")
#define Yes puts("Yes")
#define No puts("No")
#define edl puts("")
#define mc cerr<<"qwq\n"
#define error goto gg
#define def gg:
#define rd(x) x=read()
#define opl(x) printf("%lld",x)
#define opls(x) printf("%lld ",x)
#define opd(x) printf("%d",x)
#define opds(x) printf("%d ",x)
#define ver(x) for(int i=head[x];i;i=nxt[i])
#define up(i,x,y) for(int i=x,i##end=y;i<=i##end;++i)
#define pu(i,x,y) for(int i=x,i##end=y;i>=i##end;--i)
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
int f(int x)
{
	int ans=0;
	while(x)
	{
		if(x&1)ans++;
		x>>=1;
	}return ans%3;
}
const int mod=1e9+7;
struct node
{
	int mp[102][102];
	node()
	{
		memset(mp,0,sizeof(mp));
	}
	node operator *(const node &x)const
	{
		node c;
		up(i,1,n)
		{
			up(j,1,n)
			{
				up(k,1,n)
				{
					(c.mp[i][j]+=mp[i][k]*x.mp[k][j]%mod)%=mod;
				}
			}
		}
		return c;
	}
};

node qpow(node a,int b)
{
	node ans;
	up(i,1,n)ans.mp[i][i]=1;
	while(b)
	{
		if(b&1)	ans=ans*a;
		a=a*a;
		b>>=1;
	}
	return ans;
}
int a[101];
signed main()
{
	int T=1;
	while(T--)
	{
		n=read(),k=read();
		up(i,1,n)a[i]=read();
		node bas;
		up(i,1,n)
		{
			up(j,1,n)
			{
				if(f(a[i]^a[j])==0)
				{
					bas.mp[i][j]=1;
				}
			}
		}
		bas=qpow(bas,k-1);
		int ans=0;
		up(i,1,n)
		{
			up(j,1,n)
			{
				(ans+=bas.mp[i][j])%=mod;
			}
		}cout<<ans;
	}
}
/*
5 33
15 1 2 4 8
*/
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/