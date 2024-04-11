#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,q,w[222222],pre[222222],iv,sum[222222],ans,f[222222],x;
set<int> s;
set<int>::iterator it,itt;
int binpow(int a,int t)
{
	int res=1,p=a;
	for (int i=t;i;i>>=1)
	{
		if (i&1) res=1ll*res*p%mod;
		p=1ll*p*p%mod;
	}
	return res;
}
int calc(int a,int b)
{
	if (a==1) return 1ll*sum[b-1]*binpow(pre[b],mod-2)%mod;
	return 1ll*(sum[b-1]-sum[a-2])*binpow(pre[b],mod-2)%mod;
}
void era(int x)
{
	it=s.lower_bound(x);itt=it;
	it++;itt--;
	ans=(ans-calc(*itt,x-1))%mod;ans=(ans-calc(x,(*it)-1))%mod;
	ans=(ans+calc(*itt,(*it)-1))%mod;
	s.erase(s.find(x));
}
void ins(int x)
{
	it=s.lower_bound(x);itt=it;itt--;
	ans=(ans-calc(*itt,(*it)-1))%mod;
	ans=(ans+calc(*itt,x-1))%mod;ans=(ans+calc(x,(*it)-1))%mod;
	s.insert(x);
}
int main()
{
	iv=binpow(100,mod-2);
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&w[i]);
		w[i]=1ll*w[i]*iv%mod;
	}
	pre[0]=1;
	for (int i=1;i<=n;i++) pre[i]=1ll*pre[i-1]*w[i]%mod;
	sum[0]=1;
	for (int i=1;i<=n;i++) sum[i]=(sum[i-1]+pre[i])%mod;
	s.insert(1);s.insert(n+1);ans=calc(1,n);
	for (int i=1;i<=q;i++)
	{
		scanf("%d",&x);
		if (f[x]==1)
		{
			f[x]=0;
			era(x);
		}
		else 
		{
			f[x]=1;
			ins(x);
		}
		printf("%d\n",(ans+mod)%mod);
	}
	return 0;
}