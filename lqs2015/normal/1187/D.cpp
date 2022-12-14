#include<bits/stdc++.h>
using namespace std;
int t,n,tree[2222222],nxt[333333],cur[333333],a[333333],b[333333];
bool f;
void build(int l,int r,int node)
{
	if (l==r)
	{
		tree[node]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,node<<1);
	build(mid+1,r,(node<<1)|1);
	tree[node]=min(tree[node<<1],tree[(node<<1)|1]);
}
int query(int beg,int en,int l,int r,int node)
{
	if (l>en || r<beg) return 1e9;
	if (l>=beg && r<=en) return tree[node];
	int mid=(l+r)>>1;
	return min(query(beg,en,l,mid,node<<1),query(beg,en,mid+1,r,(node<<1)|1));
}
void upd(int x,int l,int r,int node)
{
	if (l==r) 
	{
		tree[node]=1e9;
		return;
	}
	int mid=(l+r)>>1;
	if (x>mid) upd(x,mid+1,r,(node<<1)|1);
	else upd(x,l,mid,node<<1);
	tree[node]=min(tree[node<<1],tree[(node<<1)|1]);
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		for (int i=1;i<=n;i++) scanf("%d",&b[i]);
		build(1,n,1);
		for (int i=1;i<=n;i++) cur[i]=n+1;
		for (int i=n;i>=1;i--)
		{
			nxt[i]=cur[a[i]];
			cur[a[i]]=i;
		}
		f=0;
		for (int i=1;i<=n;i++)
		{
			if (cur[b[i]]>n) 
			{
				f=1;
				printf("nO\n");
				break;
			}
			if (query(1,cur[b[i]],1,n,1)<b[i]) 
			{
				f=1;
				printf("nO\n");
				break;
			}
			upd(cur[b[i]],1,n,1);cur[b[i]]=nxt[cur[b[i]]];
		}
		if (!f) printf("yEs\n");
	}
	return 0;
}