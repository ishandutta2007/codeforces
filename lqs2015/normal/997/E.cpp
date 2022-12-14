#include<bits/stdc++.h>
using namespace std;
int n,a[155555],q,x,y,pos[155555];
long long ans[155555];
vector<pair<int,int> > v[155555];
struct treenode
{
	int mn,cnt,lazy1;
	long long ans,lazy2;
	treenode()
	{
		mn=cnt=lazy1=lazy2=ans=0;
	}
}tree[666666];
void pushup(int node)
{
	tree[node].mn=min(tree[(node<<1)|1].mn,tree[node<<1].mn);
	tree[node].cnt=0;
	if (tree[node<<1].mn==tree[node].mn) tree[node].cnt+=tree[node<<1].cnt;
	if (tree[(node<<1)|1].mn==tree[node].mn) tree[node].cnt+=tree[(node<<1)|1].cnt;
	tree[node].ans=tree[node<<1].ans+tree[(node<<1)|1].ans;
}
void push1(int node,int x)
{
	tree[node].mn+=x;tree[node].lazy1+=x;
}
void push2(int node,int x)
{
	tree[node].ans+=x;tree[node].lazy2+=x;
}
void pushdown(int node)
{
	if (tree[node].lazy1)
	{
		push1(node<<1,tree[node].lazy1);
		push1((node<<1)|1,tree[node].lazy1);
		tree[node].lazy1=0;
	}
	if (tree[node].lazy2)
	{
		if (tree[node<<1].mn==tree[node].mn) push2(node<<1,tree[node].lazy2/tree[node].cnt*tree[node<<1].cnt);
		if (tree[(node<<1)|1].mn==tree[node].mn) push2((node<<1)|1,tree[node].lazy2/tree[node].cnt*tree[(node<<1)|1].cnt);
		tree[node].lazy2=0;
	}
} 
void update(int beg,int en,int l,int r,int node,int x)
{
	if (l>en || r<beg) return;
	if (l>=beg && r<=en)
	{
		push1(node,x);
		if (tree[node].mn==1) push2(node,tree[node].cnt);
		return;
	}
	pushdown(node);
	int mid=(l+r)>>1;
	update(beg,en,l,mid,node<<1,x);
	update(beg,en,mid+1,r,(node<<1)|1,x);
	pushup(node);
}
long long query(int beg,int en,int l,int r,int node)
{
	if (l>en || r<beg) return 0;
	if (l>=beg && r<=en) return tree[node].ans;
	pushdown(node);
	int mid=(l+r)>>1;
	return query(beg,en,l,mid,node<<1)+query(beg,en,mid+1,r,(node<<1)|1);
}
void build(int l,int r,int node)
{
	tree[node].cnt=r-l+1;
	if (l==r) return;
	int mid=(l+r)>>1;
	build(l,mid,node<<1);
	build(mid+1,r,(node<<1)|1);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d",&q);
	for (int i=1;i<=q;i++)
	{
		scanf("%d%d",&x,&y);
		v[y].push_back(make_pair(x,i));
	}
	for (int i=1;i<=n;i++) pos[a[i]]=i;
	build(1,n,1);
	for (int i=1;i<=n;i++) 
	{
		update(1,i,1,n,1,1);
		if (a[i]>1 && pos[a[i]-1]<i) update(1,pos[a[i]-1],1,n,1,-1);
		if (a[i]<n && pos[a[i]+1]<i) update(1,pos[a[i]+1],1,n,1,-1);
		for (int j=0;j<v[i].size();j++)
		{
			ans[v[i][j].second]=query(v[i][j].first,i,1,n,1);
		}
	}
	for (int i=1;i<=q;i++)
	{
		printf("%lld\n",ans[i]);
	}
	return 0;
}