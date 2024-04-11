#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long bit1[444444],bit2[444444],n,p[444444],bit3[444444],cnt,ans,x,y,sz;
bool used[444444];
long long binpow(long long a,long long t)
{
	long long res=1,p=a;
	for (long long i=t;i;i>>=1)
	{
		if (i&1) res=res*p%mod;
		p=p*p%mod;
	}
	return res;
}
void upd(long long bit[],long long p)
{
	while(p<=sz)
	{
		bit[p]++;
		p+=p&(-p);
	}
}
long long query(long long bit[],long long p)
{
	long long res=0;
	while(p>=1)
	{
		res+=bit[p];
		p-=p&(-p);
	}
	return res;
}
int main()
{
	scanf("%lld",&n);
	sz=1;
	while(sz<n) sz*=2;
	for (long long i=1;i<=n;i++)
	{
		scanf("%lld",&p[i]);
	}
	for (long long i=1;i<=n;i++)
	{
		if (p[i]==-1)
		{
			cnt++;
			upd(bit1,i);
		}
		else used[p[i]]=1;
	}
	for (long long i=1;i<=n;i++)
	{
		if (!used[i]) upd(bit2,i);
	}
	for (long long i=1;i<=n;i++)
	{
		if (p[i]==-1) continue;
		ans=(ans+query(bit3,sz-p[i]))%mod;
		upd(bit3,sz-p[i]+1);
	}
	ans=(ans+(cnt*(cnt-1)/2%mod)*(mod+1)/2)%mod;
	long long inv=binpow(cnt,mod-2);
	for (long long i=1;i<=n;i++)
	{
		if (p[i]==-1) continue;
		x=query(bit1,i);y=query(bit2,p[i]);
		ans=(ans+x*(cnt-y)%mod*inv)%mod;
		ans=(ans+(cnt-x)*y%mod*inv)%mod;
	}
	printf("%lld\n",ans);
	return 0;
}