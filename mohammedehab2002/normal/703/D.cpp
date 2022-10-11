#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
vector<pair<pair<int,int>,int> > qu;
int nxt[1000005],tree[4000005],ans[1000005],cum[1000005];
map<int,int> l;
void update(int node,int st,int en,int idx,int val)
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
		tree[node]=(tree[2*node]^tree[2*node+1]);
	}
}
int query(int node,int st,int en,int l,int r)
{
	if (en<l || st>r || r<l)
	return 0;
	if (l<=st && en<=r)
	return tree[node];
	int mid=(st+en)/2;
	return (query(2*node,st,mid,l,r)^query(2*node+1,mid+1,en,l,r));
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		cum[i]=(cum[i-1]^a);
		if (!l.count(a))
		update(1,1,n,i,a);
		else
		nxt[l[a]]=i;
		l[a]=i;
	}
	int q;
	scanf("%d",&q);
	for (int i=0;i<q;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		qu.push_back({{l,r},i});
	}
	sort(qu.begin(),qu.end());
	int cl=1;
	for (auto p:qu)
	{
		while (cl!=p.first.first)
		{
			if (nxt[cl])
			update(1,1,n,nxt[cl],query(1,1,n,cl,cl));
			update(1,1,n,cl,0);
			cl++;
		}
		ans[p.second]=(query(1,1,n,p.first.first,p.first.second)^cum[p.first.second]^cum[p.first.first-1]);
	}
	for (int i=0;i<q;i++)
	printf("%d\n",ans[i]);
}