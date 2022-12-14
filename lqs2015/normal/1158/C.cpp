#include<bits/stdc++.h>
using namespace std;
int test,n,a[555555],tree[2222222],lazy[2222222],ct,ord[2222222];
vector<pair<int,int> > g[555555];
queue<int> q;
void pushup(int node)
{
	tree[node]=min(tree[node<<1],tree[(node<<1)|1]);
}
void push(int node,int x)
{
	tree[node]+=x;lazy[node]+=x;
}
void pushdown(int node)
{
	if (lazy[node])
	{
		push(node<<1,lazy[node]);
		push((node<<1)|1,lazy[node]);
		lazy[node]=0;
	}
}
void update(int beg,int en,int l,int r,int node,int x)
{
	if (l>en || r<beg) return;
	if (l>=beg && r<=en) 
	{
		push(node,x);
		return;
	}
	int mid=(l+r)>>1;
	pushdown(node);
	update(beg,en,l,mid,node<<1,x);
	update(beg,en,mid+1,r,(node<<1)|1,x);
	pushup(node);
}
void upd(int x,int l,int r,int node,int y)
{
	if (l==r) 
	{
		tree[node]+=y;
		return;
	}
	int mid=(l+r)>>1;
	pushdown(node);
	if (x>mid) upd(x,mid+1,r,(node<<1)|1,y);
	else upd(x,l,mid,node<<1,y);
	pushup(node);
}
void find(int l,int r,int node)
{
	if (tree[node]>0) return;
	if (l==r)
	{
		tree[node]=1e9;
		q.push(l);
		return;
	}
	int mid=(l+r)>>1;
	pushdown(node);
	find(l,mid,node<<1);
	find(mid+1,r,(node<<1)|1);
	pushup(node);
}
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		for (int i=1;i<=4*n+200;i++) tree[i]=lazy[i]=0;
		for (int i=1;i<=n;i++) g[i].clear();
		for (int i=1;i<=n;i++)
		{
			if (a[i]!=-1)
			{
				update(i+1,a[i]-1,1,n,1,1);
				g[i].push_back(make_pair(i+1,a[i]-1));
				if (a[i]<=n) 
				{
					g[a[i]].push_back(make_pair(i,i));
					update(i,i,1,n,1,1);
				}
			}
		}
		find(1,n,1);
		ct=0;
		while(!q.empty())
		{
			int x=q.front();q.pop();
			ord[x]=++ct;
			for (int i=0;i<g[x].size();i++)
			{
				update(g[x][i].first,g[x][i].second,1,n,1,-1);
			}
			find(1,n,1);
		}
		if (ct!=n)
		{
			printf("-1\n");
			continue;
		}
		for (int i=1;i<=n;i++) printf("%d ",n-ord[i]+1);
		printf("\n");
	}
	return 0;
}