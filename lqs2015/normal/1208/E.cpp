#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,w,x,a[1111111],pre[1111111],suf[1111111],mtree[4444444];
long long tree[4444444];
void update(int beg,int en,int l,int r,int node,int x)
{
	if (beg>en || beg<=0 || en<=0) return;
	if (l>en || r<beg) return;
	if (l>=beg && r<=en)
	{
		tree[node]+=x;
		return;
	}
	int mid=(l+r)>>1;
	update(beg,en,l,mid,node<<1,x);
	update(beg,en,mid+1,r,(node<<1)|1,x);
}
long long query(int x,int l,int r,int node)
{
	if (l==r) return tree[node];
	int mid=(l+r)>>1;
	if (x>mid) return query(x,mid+1,r,(node<<1)|1)+tree[node];
	return query(x,l,mid,node<<1)+tree[node];
}
void build(int l,int r,int node)
{
	if (l==r) 
	{
		mtree[node]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,node<<1);
	build(mid+1,r,(node<<1)|1);
	mtree[node]=max(mtree[node<<1],mtree[(node<<1)|1]);
}
int qmx(int beg,int en,int l,int r,int node)
{
	if (l>en || r<beg) return -2e9;
	if (l>=beg && r<=en) return mtree[node];
	int mid=(l+r)>>1;
	return max(qmx(beg,en,l,mid,node<<1),qmx(beg,en,mid+1,r,(node<<1)|1));
}
int main()
{
	scanf("%d%d",&n,&w);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		for (int j=1;j<=x;j++) scanf("%d",&a[j]);
		pre[0]=suf[x+1]=-2e9;
		for (int j=1;j<=x;j++) pre[j]=max(pre[j-1],a[j]);
		for (int j=x;j>=1;j--) suf[j]=max(suf[j+1],a[j]);
		build(1,x,1);
		if (w>2*x)
		{
			for (int j=1;j<=x;j++) update(j,j,1,w,1,max(pre[j],0));
			for (int j=1;j<=x;j++) update(w-j+1,w-j+1,1,w,1,max(suf[x-j+1],0));
			update(x+1,w-x,1,w,1,max(pre[x],0)); 
		}
		else
		{
			for (int j=1;j<=w;j++) 
			{
				if (j>x || j+x-1<w) update(j,j,1,w,1,max(0,qmx(max(1,x-(w-j)),min(x,j),1,x,1)));
				else update(j,j,1,w,1,qmx(max(1,x-(w-j)),min(x,j),1,x,1));
			}
		}
	}
	for (int i=1;i<=w;i++) printf("%lld ",query(i,1,w,1));
	printf("\n");
	return Accepted;
}