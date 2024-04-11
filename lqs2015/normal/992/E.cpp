#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
set<long long> s[33];
long long n,q,a[222222],bit[444444],sz,mx[33],mxx[33],pre[222222],pw[33],x,y,idx,idy,ans;
set<long long>::iterator it;
void update(long long p,long long x)
{
	while(p<=sz)
	{
		bit[p]+=x;
		p+=p&(-p);
	}
}
long long sum(long long p)
{
	long long res=0;
	while(p>=1)
	{
		res+=bit[p];
		p-=p&(-p);
	}
	return res;
}
long long fdpos(long long k)
{
	if (!k) return 0;
	for (long long i=1;i<=30;i++)
	{
		if (pw[i]>k) return i;
	}
}
void go(long long i)
{
	if (s[i].empty())
	{
		mx[i]=mxx[i]=0;
		return;
	}
	if (s[i].size()==1)
	{
		mx[i]=*s[i].begin();mxx[i]=0;
		return;
	}
	it=s[i].begin();
	mx[i]=*it;
	it++;
	mxx[i]=*it;
}
void upd(long long id)
{
	if (!id) return;
	pre[id]=a[id]-sum(id-1);
}
int main()
{
	scanf("%I64d%I64d",&n,&q);
	sz=1;
	while(sz<n) sz*=2;
	pw[0]=1;
	for (long long i=1;i<=30;i++) pw[i]=pw[i-1]*2;
	for (long long i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
		update(i,a[i]);
		pre[i]=a[i]-sum(i-1);
		s[fdpos(a[i])].insert(i); 
	}
	for (long long i=0;i<=30;i++) go(i);
	for (long long i=1;i<=q;i++)
	{
		scanf("%I64d%I64d",&x,&y);
		idx=fdpos(a[x]);idy=fdpos(y);
		s[idx].erase(s[idx].find(x));s[idy].insert(x); 
		go(idx);go(idy);
		for (long long j=0;j<=30;j++) 
		{
			if (mx[j]) 
			{
				if (mx[j]>x) pre[mx[j]]-=(y-a[x]);
			}
			if (mxx[j]) 
			{
				if (mxx[j]>x) pre[mxx[j]]-=(y-a[x]);
			}
		}
		update(x,y-a[x]);
		a[x]=y;
		upd(mx[idx]);upd(mxx[idx]);upd(mx[idy]);upd(mxx[idy]);
		ans=-1;
		for (long long j=0;j<=30;j++)
		{
			if (mx[j]) 
			{
				if (!pre[mx[j]]) ans=mx[j];
			}
			if (mxx[j]) 
			{
				if (!pre[mxx[j]]) ans=mxx[j];
			}
		}
		printf("%I64d\n",ans);
	}
	return 0;
}