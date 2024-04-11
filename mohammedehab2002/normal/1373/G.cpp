#include <bits/stdc++.h>
using namespace std;
map<pair<int,int>,bool> ex;
int tree[1600005],lazy[1600005];
void push(int node,int st,int en)
{
	tree[node]+=lazy[node];
	if (st!=en)
	{
		lazy[2*node]+=lazy[node];
		lazy[2*node+1]+=lazy[node];
	}
	lazy[node]=0;
}
void update(int node,int st,int en,int l,int r,int val)
{
	if (l<=st && en<=r)
	lazy[node]+=val;
	push(node,st,en);
	if (en<l || st>r || r<l || (l<=st && en<=r))
	return;
	int mid=(st+en)/2;
	update(2*node,st,mid,l,r,val);
	update(2*node+1,mid+1,en,l,r,val);
	tree[node]=max(tree[2*node],tree[2*node+1]);
}
int query(int node,int st,int en,int l,int r)
{
	push(node,st,en);
	if (en<l || st>r || r<l)
	return 0;
	if (l<=st && en<=r)
	return tree[node];
	int mid=(st+en)/2;
	return max(query(2*node,st,mid,l,r),query(2*node+1,mid+1,en,l,r));
}
int main()
{
	int n,k,m;
	scanf("%d%d%d",&n,&k,&m);
	for (int i=1;i<=2*n;i++)
	update(1,1,2*n,i,i,i);
	multiset<int,greater<int> > s;
	while (m--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int a=abs(x-k)+y;
		if (ex[{x,y}])
		{
			ex[{x,y}]=0;
			s.erase(s.find(a));
			update(1,1,2*n,1,a,-1);
		}
		else
		{
			ex[{x,y}]=1;
			s.insert(a);
			update(1,1,2*n,1,a,1);
		}
		printf("%d\n",max(0,query(1,1,2*n,1,*s.begin())-n-1));
	}
}