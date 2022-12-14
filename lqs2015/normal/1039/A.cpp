#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
bool used[222222];
pair<long long,long long> a[222222];
long long n,k,x[222222],val[222222],y,tree0[888888],tree1[888888],lazy0[888888],lazy1[888888],ans[222222],sz;
void pushdown0(long long node)
{
	if (lazy0[node])
	{
		lazy0[node*2]=lazy0[node*2+1]=1;
		tree0[node*2]=tree0[node*2+1]=1;
		lazy0[node]=0;
	}
}
void update0(long long beg,long long en,long long l,long long r,long long node)
{
	if (l>en || r<beg) return;
	if (l>=beg && r<=en) 
	{
		tree0[node]=1;
		lazy0[node]=1;
		return;
	}
	pushdown0(node);
	long long mid=(l+r)/2;
	update0(beg,en,l,mid,node*2);
	update0(beg,en,mid+1,r,node*2+1);
	tree0[node]=tree0[node*2+1]|tree0[node*2];
}
long long query0(long long beg,long long en,long long l,long long r,long long node)
{
	if (l>en || r<beg) return 0;
	if (l>=beg && r<=en) return tree0[node];
	pushdown0(node);
	long long mid=(l+r)/2;
	return query0(beg,en,l,mid,node*2)|query0(beg,en,mid+1,r,node*2+1);
}
void pushdown1(long long node)
{
	if (lazy1[node])
	{
		lazy1[node*2]=lazy1[node*2+1]=1;
		tree1[node*2]=tree1[node*2+1]=1;
		lazy1[node]=0;
	}
}
void update1(long long beg,long long en,long long l,long long r,long long node)
{
	if (l>en || r<beg) return;
	if (l>=beg && r<=en) 
	{
		tree1[node]=1;
		lazy1[node]=1;
		return;
	}
	pushdown1(node);
	long long mid=(l+r)/2;
	update1(beg,en,l,mid,node*2);
	update1(beg,en,mid+1,r,node*2+1);
	tree1[node]=tree1[node*2+1]|tree1[node*2];
}
long long query1(long long beg,long long en,long long l,long long r,long long node)
{
	if (l>en || r<beg) return 0;
	if (l>=beg && r<=en) return tree1[node];
	pushdown1(node);
	long long mid=(l+r)/2;
	return query1(beg,en,l,mid,node*2)|query1(beg,en,mid+1,r,node*2+1);
}
int main()
{
	scanf("%I64d%I64d",&n,&k);
	for (long long i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i].first);
		a[i].second=i;
	}
	sort(a+1,a+n+1);
	for (long long i=1;i<=n;i++)
	{
		val[a[i].second]=i;
	}
	for (long long i=1;i<=n;i++) scanf("%I64d",&x[i]);
	sz=1;
	while(sz<n) sz*=2;
	for (long long i=1;i<=n;i++)
	{
		y=x[a[i].second];
		if (val[y]<i) 
		{
			printf("No\n");
			return 0;
		}
		if (query0(i+1,val[y],1,sz,1)>0) 
		{
			printf("No\n");
			return 0;
		}
		update1(i+1,val[y],1,sz,1);
		if (val[y]<n)
		{
			if (query1(val[y]+1,val[y]+1,1,sz,1)>0) 
			{
				printf("No\n");
				return 0;
			}
			update0(val[y]+1,val[y]+1,1,sz,1);
		}
	}
	for (long long i=1;i<=n;i++) used[i]=query1(i,i,1,sz,1);
	for (long long i=1;i<=n;i++)
	{
		if (used[i+1]) 
		{
			ans[i]=a[i+1].first+k;	
			while(ans[i]<=ans[i-1]) ans[i]++;
		}
		else 
		{
			ans[i]=a[i].first+k;
			while(ans[i]<=ans[i-1]) ans[i]++;
			if (i<n && ans[i]>=a[i+1].first+k) 
			{
				printf("No\n");
				return 0;
			}
		}
	}
	printf("Yes\n");
	for (long long i=1;i<=n;i++) printf("%I64d ",ans[val[i]]);
	return 0;
}