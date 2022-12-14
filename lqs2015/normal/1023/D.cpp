#include<iostream>
#include<cstdio>
using namespace std;
int n,q,a[222222],b[222222],mx,tree[888888],fst[222222],sz;
bool f;
void build(int l,int r,int node)
{
	if (l==r)
	{
		if (l<=n) tree[node]=b[l];
		else tree[node]=1e9;
		return;
	}
	int mid=(l+r)/2;
	build(l,mid,node*2);
	build(mid+1,r,node*2+1);
	tree[node]=min(tree[node*2],tree[node*2+1]);
}
int query(int beg,int en,int l,int r,int node)
{
	if (l>en || r<beg) return 1e9;
	if (l>=beg && r<=en) return tree[node];
	int mid=(l+r)/2;
	return min(query(beg,en,l,mid,node*2),query(beg,en,mid+1,r,node*2+1));
}
int main()
{
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for (int i=1;i<=n;i++)
	{
		if (!a[i]) 
		{
			if (i==1) b[i]=1;
			else b[i]=b[i-1];
			continue;
		}
		b[i]=a[i];
	}
	for (int i=1;i<=n;i++) 
	{
		if (!fst[b[i]]) fst[b[i]]=i;
	}
	sz=1;
	while(sz<n) sz*=2;
	build(1,sz,1);
	for (int i=1;i<=n;i++)
	{
		if (query(fst[b[i]],i,1,sz,1)<b[i]) 
		{
			printf("NO\n");
			return 0;
		}
	}
	f=0;
	for (int i=1;i<=n;i++)
	{
		if (b[i]==q) f=1;
	}
	if (f)
	{
		printf("YES\n");
		for (int i=1;i<=n;i++) printf("%d ",b[i]);
	}
	else
	{
		f=0;
		for (int i=1;i<=n;i++)
		{
			if (!a[i])
			{
				b[i]=q;
				f=1;
				break;
			}
		}
		if (f)
		{
			printf("YES\n");
			for (int i=1;i<=n;i++) printf("%d ",b[i]);
		}
		else printf("NO\n");
	}
	return 0;
}