#include<bits/stdc++.h>
using namespace std;
const long long maxn=(1ll<<60)-1;
const int mod=998244353,iv=(mod+1)/2;
struct segt
{
	int sz,ls[55555],rs[55555],dep[55555],rt,head[111],nxt[55555];
	bool f[55555];
	long long msk[55555];
	void update(long long beg,long long en,long long l,long long r,int &nw,int deep,long long mk)
	{
		if (l>en || r<beg) return;
		if (!nw)
		{
			nw=++sz;
			dep[nw]=deep;msk[nw]=mk;
			nxt[sz]=head[dep[nw]];head[dep[nw]]=sz;
		}
		if (f[nw]) return;
		if (l>=beg && r<=en) 
		{
			f[nw]=1;
			return;
		}
		long long mid=(l+r)>>1;
		update(beg,en,l,mid,ls[nw],deep+1,mk);
		update(beg,en,mid+1,r,rs[nw],deep+1,mk|(1ll<<deep));
	}
}a,b;
int sum(long long l,long long r)
{
	l%=mod;r%=mod;
	int res=1ll*(l+r)*(r-l+1)%mod*iv%mod;
	if (res<0) res+=mod;
	return res;
}
struct segt2
{
	int rt,sz,ls[11111111],rs[11111111],tree[11111111];
	bool f[11111111];
	void update(int mdep,int dep,long long msk,long long l,long long r,int &nw)
	{
		if (!nw)
		{
			nw=++sz;
		}
		if (dep==mdep) 
		{
			f[nw]=1;
			return;
		}
		long long mid=(l+r)>>1;
		if (msk&(1ll<<dep)) update(mdep,dep+1,msk,mid+1,r,rs[nw]);
		else update(mdep,dep+1,msk,l,mid,ls[nw]);
	}
	int query(int nw,long long l,long long r)
	{
		if (!nw) return 0;
		if (f[nw]) return sum(l,r);
		long long mid=(l+r)>>1;
		return (query(ls[nw],l,mid)+query(rs[nw],mid+1,r))%mod;
	}
}tr;
int na,nb;
long long l,r;
int main()
{
	scanf("%d",&na);
	for (int i=1;i<=na;i++)
	{
		scanf("%lld%lld",&l,&r);
		a.update(l,r,0,maxn,a.rt,0,0);
	}
	scanf("%d",&nb);
	for (int i=1;i<=nb;i++)
	{
		scanf("%lld%lld",&l,&r);
		b.update(l,r,0,maxn,b.rt,0,0);
	}
	for (int i=1;i<=a.sz;i++)
	{
		if (a.f[i])
		{
			for (int j=b.head[a.dep[i]];j;j=b.nxt[j])
			{
				tr.update(a.dep[i],0,a.msk[i]^b.msk[j],0,maxn,tr.rt);
			}
		}
	}
	for (int i=1;i<=b.sz;i++)
	{
		if (b.f[i])
		{
			for (int j=a.head[b.dep[i]];j;j=a.nxt[j])
			{
				if (!a.f[j]) tr.update(a.dep[j],0,a.msk[j]^b.msk[i],0,maxn,tr.rt);
			}
		}
	}
	printf("%d\n",tr.query(tr.rt,0,maxn)%mod);
	return 0;
}