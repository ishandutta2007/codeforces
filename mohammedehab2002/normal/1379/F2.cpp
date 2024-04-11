#include <bits/stdc++.h>
using namespace std;
bool ans[200005];
map<pair<int,int>,int> ex;
vector<pair<int,int> > a[800005];
vector<pair<pair<int,int>,int> > upd;
int tree[2][800005],n,m,q;
void add(int node,int st,int en,int l,int r,pair<int,int> c)
{
	if (l<=st && en<=r)
	a[node].push_back(c);
	if (en<l || st>r || r<l || (l<=st && en<=r))
	return;
	int mid=(st+en)/2;
	add(2*node,st,mid,l,r,c);
	add(2*node+1,mid+1,en,l,r,c);
}
void update(int node,int st,int en,int idx,int val,int t)
{
	upd.push_back({{t,node},tree[t][node]});
	if (st==en)
	tree[t][node]=min(tree[t][node],val);
	else
	{
		int mid=(st+en)/2;
		if (st<=idx && idx<=mid)
		update(2*node,st,mid,idx,val,t);
		else
		update(2*node+1,mid+1,en,idx,val,t);
		tree[t][node]=min(tree[t][2*node],tree[t][2*node+1]);
	}
}
int query(int node,int st,int en,int l,int r,int t)
{
	if (en<l || st>r || r<l)
	return m;
	if (l<=st && en<=r)
	return tree[t][node];
	int mid=(st+en)/2;
	return min(query(2*node,st,mid,l,r,t),query(2*node+1,mid+1,en,l,r,t));
}
void solve(int node,int st,int en,bool yes)
{
	int sz=upd.size();
	for (auto p:a[node])
	{
		if (p.first%2)
		{
			yes&=(p.second/2+query(1,1,n,p.first/2+1,n,1)>=m);
			update(1,1,n,p.first/2+1,p.second/2,0);
		}
		else
		{
			yes&=(query(1,1,n,1,p.first/2,0)>=p.second/2);
			update(1,1,n,p.first/2,m-p.second/2,1);
		}
	}
	if (st==en)
	ans[st]=yes;
	else
	{
		int mid=(st+en)/2;
		solve(2*node,st,mid,yes);
		solve(2*node+1,mid+1,en,yes);
	}
	while (upd.size()!=sz)
	{
		tree[upd.back().first.first][upd.back().first.second]=upd.back().second;
		upd.pop_back();
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<=q;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if (ex[{a,b}])
		{
			add(1,1,q,ex[{a,b}],i-1,{a,b});
			ex[{a,b}]=0;
		}
		else
		ex[{a,b}]=i;
	}
	for (auto p:ex)
	{
		if (p.second)
		add(1,1,q,p.second,q,p.first);
	}
	for (int i=1;i<=4*n;i++)
	tree[0][i]=tree[1][i]=m;
	solve(1,1,q,1);
	for (int i=1;i<=q;i++)
	puts(ans[i]? "YES":"NO");
}