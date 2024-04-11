#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MX 500000
int arr[MX+5],ans[MX+5];
vector<int> v[MX+5];
vector<pair<int,int> > qu[MX+5];
pair<int,int> tree[4*MX+5];
void update(int node,int st,int en,int idx,int val)
{
	if (st==en)
	tree[node]={val,st};
	else
	{
		int mid=(st+en)/2;
		if (st<=idx && idx<=mid)
		update(2*node,st,mid,idx,val);
		else
		update(2*node+1,mid+1,en,idx,val);
		tree[node]=max(tree[2*node],tree[2*node+1]);
	}
}
pair<int,int> query(int node,int st,int en,int l,int r)
{
	if (en<l || st>r || r<l)
	return {0,0};
	if (l<=st && en<=r)
	return tree[node];
	int mid=(st+en)/2;
	return max(query(2*node,st,mid,l,r),query(2*node+1,mid+1,en,l,r));
}
int main()
{
	int n,q;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		v[arr[i]].push_back(i);
	}
	for (int i=1;i<=MX;i++)
	{
		v[i].push_back(n);
		if (v[i].size()>1)
		update(1,0,n-1,v[i][0],v[i][1]);
		reverse(v[i].begin(),v[i].end());
	}
	scanf("%d",&q);
	for (int i=0;i<q;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		qu[l-1].push_back({r-1,i});
	}
	for (int i=0;i<n;i++)
	{
		for (auto p:qu[i])
		{
			auto tmp=query(1,0,n-1,i,p.first);
			if (tmp.first>p.first)
			ans[p.second]=arr[tmp.second];
		}
		v[arr[i]].pop_back();
		if (v[arr[i]].size()>1)
		update(1,0,n-1,v[arr[i]].back(),v[arr[i]][v[arr[i]].size()-2]);
	}
	for (int i=0;i<q;i++)
	printf("%d\n",ans[i]);
}