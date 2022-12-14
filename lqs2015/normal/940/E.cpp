#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const long long sz=1<<17;
long long a[111111],n,c,dp[111111],sum;
long long atree[444444],dptree[444444];
void build(long long l,long long r,long long node)
{
	if (l==r)
	{
		if (l>n) atree[node]=1e18;
		else atree[node]=a[l];
		return;
	}
	long long mid=(l+r)/2;
	build(l,mid,node*2);
	build(mid+1,r,node*2+1);
	atree[node]=min(atree[node*2],atree[node*2+1]);	
}
void update(long long x,long long p)	
{
	long long pos=sz+x-1;
	dptree[pos]=p;pos/=2;
	while(pos)
	{
		dptree[pos]=max(dptree[pos*2],dptree[pos*2+1]);
		pos/=2;
	}
}
long long querya(long long beg,long long en,long long l,long long r,long long node)
{
	if (l>en || r<beg) return 1e18;
	if (l>=beg && r<=en) return atree[node];
	long long mid=(l+r)/2;
	return min(querya(beg,en,l,mid,node*2),querya(beg,en,mid+1,r,node*2+1));
}
long long querydp(long long beg,long long en,long long l,long long r,long long node)
{
	if (l>en || r<beg) return 0;
	if (l>=beg && r<=en) return dptree[node];
	long long mid=(l+r)/2;
	return max(querydp(beg,en,l,mid,node*2),querydp(beg,en,mid+1,r,node*2+1));
}
int main()
{
	scanf("%I64d%I64d",&n,&c);
	for (long long i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
		sum+=a[i];
	}
	if (c==1) 
	{
		printf("0\n");
		return 0;
	}
	build(1,sz,1);
	for (long long i=c;i<=n;i++)
	{
		dp[i]=max(querydp(i-c+1,i-1,1,sz,1),dp[i-c]+querya(i-c+1,i,1,sz,1));
		update(i,dp[i]);
	}
	printf("%I64d\n",sum-dp[n]);
	return 0;
}