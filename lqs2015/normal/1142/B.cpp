#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,m,q,tree[888888],p[222222],nxt[222222],nt[222222][22],a[222222],b[222222],arr[222222],pos,l,r;
void build(int l,int r,int node)
{
	if (l==r)
	{
		tree[node]=arr[l];
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,node<<1);
	build(mid+1,r,(node<<1)|1);
	tree[node]=min(tree[(node<<1)|1],tree[node<<1]);
}
int query(int beg,int en,int l,int r,int node)
{
	if (l>en || r<beg) return 1e9;
	if (l>=beg && r<=en) return tree[node];
	int mid=(l+r)>>1;
	return min(query(beg,en,l,mid,node<<1),query(beg,en,mid+1,r,(node<<1)|1));
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<=n;i++) 
	{
		scanf("%d",&p[i]);
	}
	for (int i=1;i<=n;i++)
	{
		if (i==n) nxt[p[i]]=p[1];
		else nxt[p[i]]=p[i+1];
	}
	for (int i=n;i>=1;i--)
	{
		a[i]=m+1;
	}
	for (int i=1;i<=m;i++) scanf("%d",&b[i]);
	for (int i=0;i<=18;i++) nt[m+1][i]=m+1;
	for (int i=m;i>=1;i--)
	{
		nt[i][0]=a[nxt[b[i]]];
		a[b[i]]=i;
	}
	for (int i=1;i<=18;i++)
	{
		for (int j=1;j<=m;j++)
		nt[j][i]=nt[nt[j][i-1]][i-1];
	}
	for (int i=1;i<=m;i++)
	{
		pos=i;
		for (int j=0;j<=18;j++)
		{
			if ((n-1)&(1<<j)) pos=nt[pos][j];
		}
		arr[i]=pos;
	}
	build(1,m,1);
	while(q--)
	{
		scanf("%d%d",&l,&r);
		if (query(l,r,1,m,1)<=r) printf("1");
		else printf("0");
	}
	printf("\n");
	return Accepted;
}