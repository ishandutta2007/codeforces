#include <iostream>
#include <string.h>
#include <vector>
#include <set>
using namespace std;
#define sz 5000005
int n,tree[sz],lc[sz],rc[sz],root[200005],cn;
void build(int node,int st,int en)
{
	if (st!=en)
	{
		lc[node]=++cn;
		rc[node]=++cn;
		int mid=(st+en)/2;
		build(lc[node],st,mid);
		build(rc[node],mid+1,en);
	}
}
void update(int node,int node2,int st,int en,int idx,int val)
{
	tree[node]=tree[node2];
	if (st==en)
	tree[node]+=val;
	else
	{
		int mid=(st+en)/2;
		if (st<=idx && idx<=mid)
		{
			lc[node]=++cn;
			rc[node]=rc[node2];
			update(lc[node],lc[node2],st,mid,idx,val);
		}
		else
		{
			rc[node]=++cn;
			lc[node]=lc[node2];
			update(rc[node],rc[node2],mid+1,en,idx,val);
		}
		tree[node]=tree[lc[node]]+tree[rc[node]];
	}
}
int query(int node,int st,int en,int l,int r)
{
	if (st>r || en<l || r<l)
	return 0;
	if (l<=st && en<=r)
	return tree[node];
	int mid=(st+en)/2;
	return query(lc[node],st,mid,l,r)+query(rc[node],mid+1,en,l,r);
}
void recalc(vector<int> a)
{
	memset(tree,0,sizeof(tree));
	memset(lc,0,sizeof(lc));
	memset(rc,0,sizeof(rc));
	cn=0;
	root[0]=++cn;
	build(root[0],1,n);
	for (int i=0;i<n;i++)
	{
		root[i+1]=++cn;
		update(root[i+1],root[i],1,n,a[i],1);
	}
}
int main()
{
	int q;
	scanf("%d%d",&n,&q);
	vector<int> a,lv;
	for (int i=0;i<n;i++)
	a.push_back(i+1);
	set<int> upd;
	long long ans=0;
	for (int i=0;i<q;i++)
	{
		if (i%1900==0)
		{
			lv=a;
			upd.clear();
			recalc(a);
		}
		int l,r;
		scanf("%d%d",&l,&r);
		if (l>r)
		swap(l,r);
		if (l!=r)
		{
			l--;
			r--;
			int f=min(a[l],a[r]),s=max(a[l],a[r]);
			int tmp=query(root[r],1,n,f,s)-query(root[l+1],1,n,f,s);
			for (int j:upd)
			{
				if (j>l && j<r)
				{
					tmp-=(f<=lv[j] && lv[j]<=s);
					tmp+=(f<=a[j] && a[j]<=s);
				}
			}
			if (a[r]>a[l])
			ans+=2*tmp+1;
			else
			ans-=2*tmp+1;
			upd.insert(l);
			upd.insert(r);
			swap(a[l],a[r]);
		}
		printf("%I64d\n",ans);
	}
}