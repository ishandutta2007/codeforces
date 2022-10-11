#include <iostream>
using namespace std;
int n;
long long t,ans;
pair<long long,int> tree[800005];
pair<long long,int> merge(pair<long long,int> a,pair<long long,int> b)
{
	a.first+=b.first;
	a.second+=b.second;
	return a;
}
void update(int node,int st,int en,int idx,pair<long long,int> val)
{
	if (st==en)
	tree[node]=val;
	else
	{
		int mid=(st+en)/2;
		if (st<=idx && idx<=mid)
		update(2*node,st,mid,idx,val);
		else
		update(2*node+1,mid+1,en,idx,val);
		tree[node]=merge(tree[2*node],tree[2*node+1]);
	}
}
pair<long long,int> query(int node,int st,int en,int l,int r)
{
	if (en<l || st>r || r<l)
	return {0,0};
	if (l<=st && en<=r)
	return tree[node];
	int mid=(st+en)/2;
	return merge(query(2*node,st,mid,l,r),query(2*node+1,mid+1,en,l,r));
}
void go()
{
	int cur=0;
	while (cur!=n+1)
	{
		int st=cur,en=n;
		while (st!=en)
		{
			int mid=(st+en)/2;
			if (query(1,0,n-1,cur,mid).first>t)
			en=mid;
			else
			st=mid+1;
		}
		if (st!=n)
		update(1,0,n-1,st,{0,0});
		auto q=query(1,0,n-1,cur,st-1);
		t-=q.first;
		ans+=q.second;
		cur=st+1;
	}
}
int main()
{
	scanf("%d%I64d",&n,&t);
	for (int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		update(1,0,n-1,i,{a,1});
	}
	while (1)
	{
		auto tmp=tree[1];
		if (!tmp.first)
		break;
		if (t<tmp.first)
		go();
		else
		{
			ans+=(t/tmp.first)*tmp.second;
			t%=tmp.first;
		}
	}
	printf("%I64d",ans);
}