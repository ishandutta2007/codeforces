#include <bits/stdc++.h>
using namespace std;
int tree[2000005],lazy[2000005];
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
void update(int node,int st,int en,int l,int r)
{
	if (l<=st && en<=r)
	lazy[node]++;
	push(node,st,en);
	if (en<l || st>r || r<l || (l<=st && en<=r))
	return;
	int mid=(st+en)/2;
	update(2*node,st,mid,l,r);
	update(2*node+1,mid+1,en,l,r);
	tree[node]=tree[2*node];
}
int query(int node,int st,int en,int idx)
{
	push(node,st,en);
	if (st==en)
	return tree[node];
	else
	{
		int mid=(st+en)/2;
		if (idx<=mid)
		return query(2*node,st,mid,idx);
		else
		return query(2*node+1,mid+1,en,idx);
	}
}
int find(int node,int st,int en,int val)
{
	push(node,st,en);
	if (st==en)
	return st;
	int mid=(st+en)/2;
	push(2*node,st,mid);
	push(2*node+1,mid+1,en);
	if (tree[2*node+1]<=val)
	return find(2*node+1,mid+1,en,val);
	return find(2*node,st,mid,val);
}
int main()
{
	int n;
	string s;
	cin >> n >> s;
	int nex=n;
	long long sum=0,ans=0;
	for (int i=n-1;i>=0;i--)
	{
		if (s[i]=='1')
		{
			int val=query(1,0,n-1,nex-1),idx=find(1,0,n-1,val);
			update(1,0,n-1,i,idx);
			sum+=idx-i+1;
		}
		else
		nex=i;
		ans+=sum;
	}
	cout << ans;
}