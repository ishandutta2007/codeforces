//Author : MatrixCascade

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
int f[303030],w[101010],sum;
const int mod=998244353;
int qpow(int a,int b)
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
int inv(int x)
{
	return qpow(x,mod-2);
}
signed main()
{
	n=read();
	up(i,1,n)w[i]=read(),m+=w[i];
	f[0]=f[1]=1;
	up(a,1,m)
	{
		f[a+1]=f[a]*((m*(n-1)%mod*inv(m-a)%mod-n+2+mod))%mod-a*(n-1)%mod*inv(m-a)%mod*(f[a-1]+1)%mod;
		f[a+1]+=mod;
		f[a+1]%=mod;
	}
	int ans=0;
	up(i,1,n)ans+=f[w[i]],ans%=mod;
	ans-=f[m];
	ans-=(n-1)*f[0];
	ans+=mod;
	ans%=mod;
	cout<<ans;
}