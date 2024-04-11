#include <iostream>
#include <string.h>
using namespace std;
int tree[26][400005],lazy[26][400005];
void update(int node,int st,int en,int l,int r,int val,int i)
{
	if (lazy[i][node]!=-1)
	{
		tree[i][node]=lazy[i][node]*(en-st+1);
		if (st!=en)
		{
			lazy[i][2*node]=lazy[i][node];
			lazy[i][2*node+1]=lazy[i][node];
		}
		lazy[i][node]=-1;
	}
	if (st>r || en<l || l>r)
	return;
	if (l<=st && en<=r)
	{
		tree[i][node]=val*(en-st+1);
		if (st!=en)
		{
			lazy[i][2*node]=val;
			lazy[i][2*node+1]=val;
		}
		return;
	}
	int mid=(st+en)/2;
	update(2*node,st,mid,l,r,val,i);
	update(2*node+1,mid+1,en,l,r,val,i);
	tree[i][node]=tree[i][2*node]+tree[i][2*node+1];
}
int query(int node,int st,int en,int l,int r,int i)
{
	if (lazy[i][node]!=-1)
	{
		tree[i][node]=lazy[i][node]*(en-st+1);
		if (st!=en)
		{
			lazy[i][2*node]=lazy[i][node];
			lazy[i][2*node+1]=lazy[i][node];
		}
		lazy[i][node]=-1;
	}
	if (st>r || en<l || l>r)
	return 0;
	if (l<=st && en<=r)
	return tree[i][node];
	int mid=(st+en)/2;
	int p1=query(2*node,st,mid,l,r,i);
	int p2=query(2*node+1,mid+1,en,l,r,i);
	return p1+p2;
}
int main()
{
	int n,q;
	string s;
	cin >> n >> q >> s;
	memset(lazy,-1,sizeof(lazy));
	for (int i=0;i<n;i++)
	update(1,0,n-1,i,i,1,s[i]-'a');
	while (q--)
	{
		int l,r,k;
		cin >> l >> r >> k;
		l--;
		r--;
		int cur=l;
		if (!k)
		cur=r;
		for (int i=0;i<26;i++)
		{
			int cnt=query(1,0,n-1,l,r,i);
			if (!cnt)
			continue;
			update(1,0,n-1,l,r,0,i);
			int lu=cur,ru=cur+cnt-1;
			if (k)
			{
				update(1,0,n-1,cur,cur+cnt-1,1,i);
				cur+=cnt;
			}
			else
			{
				update(1,0,n-1,cur-cnt+1,cur,1,i);
				cur-=cnt;
			}
		}
	}
	for (int i=0;i<n;i++)
	{
		for (int x=0;x<26;x++)
		{
			if (query(1,0,n-1,i,i,x)==1)
			cout << (char)(x+'a');
		}
	}
}