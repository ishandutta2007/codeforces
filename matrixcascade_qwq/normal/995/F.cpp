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

int d;
const int maxm=6e3+10;
int head[maxm],to[maxm],nxt[maxm],fa[maxm];
const int mod=1e9+7;
int qpow(int a,int b=mod-2)
{
	int ans=1;
	while(b)
	{
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
const int dXnmsl=3333;
int f[dXnmsl][dXnmsl];
signed main()
{
	n=read(),d=read();
	up(i,2,n)
	{
		int x=read();
		fa[i]=x;
	}
	up(i,1,n)
	{
		up(j,1,n+1)f[i][j]=1;
	}
	down(i,n,1)
	{
		up(j,2,n+1)f[i][j]+=f[i][j-1],f[i][j]%=mod;
		if(i!=1)
		{
			up(j,1,n+1)f[fa[i]][j]*=f[i][j],f[fa[i]][j]%=mod;
		}
	}
	up(i,2,n+1)
	{
		up(j,1,n+2-i)
		{
			f[i][j]=f[i-1][j+1]-f[i-1][j]+mod,f[i][j]%=mod;
		}
	}
	int ans=0;
	int nw=1;
	up(i,1,min(n+1,d))
	{
		ans+=nw*f[i][1]%mod;
		ans%=mod;
		nw*=(d-i);
		nw%=mod;
		nw*=qpow(i);
		nw%=mod;
	}
	cout<<ans;	
}