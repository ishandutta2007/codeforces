#include <iostream>
#include <vector>
using namespace std;
vector<pair<int,int> > v[1000005];
pair<long long,long long> tree[4000005];
pair<long long,long long> merge(pair<long long,long long> a,pair<long long,long long> b)
{
	a.first+=b.first;
	a.second+=b.second;
	return a;
}
void update(int node,int st,int en,pair<int,int> p)
{
	if (st==en)
	tree[node]=merge(tree[node],{p.second,(long long)p.first*p.second});
	else
	{
		int mid=(st+en)/2;
		if (st<=p.first && p.first<=mid)
		update(2*node,st,mid,p);
		else
		update(2*node+1,mid+1,en,p);
		tree[node]=merge(tree[2*node],tree[2*node+1]);
	}
}
long long query(int node,int st,int en,int k)
{
	if (st==en)
	return min((long long)k,tree[node].first)*st;
	int mid=(st+en)/2;
	if (tree[2*node].first<=k)
	return query(2*node+1,mid+1,en,k-tree[2*node].first)+tree[2*node].second;
	return query(2*node,st,mid,k);
}
int main()
{
	int n,k,m;
	scanf("%d%d%d",&n,&k,&m);
	while (m--)
	{
		int l,r,c,p;
		scanf("%d%d%d%d",&l,&r,&c,&p);
		v[l].push_back({p,c});
		v[r+1].push_back({p,-c});
	}
	long long sum=0;
	for (int i=1;i<=n;i++)
	{
		for (auto p:v[i])
		update(1,0,1000000,p);
		sum+=query(1,0,1000000,k);
	}
	printf("%I64d",sum);
}