#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
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
const int maxn=1e7+10;
int e[maxn],mu[maxn],pri[4040404],tot,a[maxn];
int b[maxn];
int f[maxn];
const int mod=1e9+7;
void sieve(int n)
{
	e[1]=mu[1]=1;
	up(i,2,n)
	{
		if(!e[i])
		{
			pri[++tot]=i;
			mu[i]=mod-1;
		}
		for(int j=1;j<=tot&&pri[j]*i<=n;++j)
		{
			e[i*pri[j]]=1;
			if(i%pri[j]==0)
			{
				mu[i*pri[j]]=0;
				break;
			}
			mu[i*pri[j]]=mod-mu[i];
		}
	}
}

signed main()
{
	sieve(maxn-5);
	n=read();
	up(i,1,n)
	{
		int x=read();
		b[x]++;
		m=max(m,x);
	}
	a[0]=1;
	up(i,1,m)
	{
		a[i]=(a[i-1]*2)%mod;
	}
	up(i,1,m)
	{
		int ans=0;
		for(int j=i;j<=m;j+=i)ans+=b[j];
		ans=(a[ans]-1);
		f[i]=ans;
	}
	down(i,m,1)
	{
		ll nw=f[i];
		for(int j=i+i;j<=m;j+=i)nw=(nw-f[j]+mod);
		nw%=mod;
		f[i]=nw;
	}
	ll sum=0;
	up(i,1,m)
	{
		if(mu[i])
		{
			ll ans1=0,ans2=0;
			for(int j=i;j<=m;j+=i)ans1+=f[j],ans2+=b[j],ans1%=mod,ans2%=mod;
			sum+=1ll*ans1*(n-ans2)%mod*(mod-mu[i])%mod;
			sum%=mod;
		}
	}
	cout<<sum;
}