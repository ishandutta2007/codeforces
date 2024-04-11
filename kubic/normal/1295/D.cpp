#include <bits/stdc++.h>
using namespace std;
#define N 100005 
#define ll long long
int T,p[N];bool vs[N];ll n,m,d,st[N];
ll gcd(ll x,ll y) {return y?gcd(y,x%y):x;}
void sieve(int n)
{
	p[0]=0;vs[1]=1;
	for(int i=2;i<=n;++i)
	{
		if(!vs[i]) p[++p[0]]=i;
		for(int j=1;i*p[j]<=n;++j)
		{
			vs[i*p[j]]=1;
			if(!(i%p[j])) break;
		}
	}
}
void div(ll x)
{
	ll t=x;st[0]=0;
	for(int i=1;i<=p[0] && 1ll*p[i]*p[i]<=x;++i)
		if(!(t%p[i]))
		{
			st[++st[0]]=p[i];
			while(!(t%p[i])) t/=p[i];
		}if(t>1) st[++st[0]]=t;
}
ll slv(ll x)
{
	ll res=0,t;
	for(int i=1,cnt;i<(1<<st[0]);++i)
	{
		cnt=0;t=1;
		for(int j=1;j<=st[0];++j) if(i&(1<<j-1))
			++cnt,t*=st[j];
		if(cnt&1) res+=x/t;else res-=x/t;
	}return x-res;
}
int main()
{
	sieve(1e5);scanf("%d",&T);
	while(T--)
	{
		scanf("%lld %lld",&n,&m);d=gcd(n,m);
		n/=d;m/=d;div(m);
		printf("%lld\n",slv(n+m-1)-slv(n-1));
	}return 0;
}