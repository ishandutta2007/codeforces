#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include<cstdio>
#include<bitset>
using std::bitset;
const int N=1e5+5,M=5e7+5;
int prime[N],tot;
bitset<N> isprime;
inline void sieve(int n)
{
	register int i,j;
	isprime.set();
	isprime[1]=0;
	for(i=1;i<=n;i++)
	{
		if(isprime[i])
			prime[++tot]=i;
		for(j=1;j<=tot&&i*prime[j]<=n;j++)
		{
			isprime[i*prime[j]]=0;
			if(i%prime[j]==0)
				break;
		}
	}
	return;
}
unsigned a,b,c,d,ans;
bitset<M> isprime1,isprime5;
inline void extsieve(int n)
{
	unsigned x,tt,ttt;
	register int i,j;
	isprime1.set();
	isprime5.set();
	isprime1[0]=0;
	for(i=1;i<=tot;i++)
		for(j=prime[i]*2;j<=n;j+=prime[i])
			if(j%6==1)
				isprime1[(j-1)/6]=0;
			else if(j%6==5)
				isprime5[(j-5)/6]=0;
	x=2;tt=n;ttt=0;
	while(tt)
		tt/=x,ttt+=tt;
	ans+=ttt*(a*x*x*x+b*x*x+c*x+d);
	x=3;tt=n;ttt=0;
	while(tt)
		tt/=x,ttt+=tt;
	ans+=ttt*(a*x*x*x+b*x*x+c*x+d);
	for(i=0;i<=n/6;i++)
	{
		if(isprime1[i])
		{
			x=i*6+1;tt=n;ttt=0;
			while(tt)
				tt/=x,ttt+=tt;
			ans+=ttt*(a*x*x*x+b*x*x+c*x+d);
		}
		if(isprime5[i])
		{
			x=i*6+5;tt=n;ttt=0;
			while(tt)
				tt/=x,ttt+=tt;
			ans+=ttt*(a*x*x*x+b*x*x+c*x+d);
		}
	}
	return;
}
signed main()
{
	int n;
	scanf("%d%u%u%u%u",&n,&a,&b,&c,&d);
	sieve(100000);
	extsieve(n);
	printf("%u",ans);
	return 0;
}