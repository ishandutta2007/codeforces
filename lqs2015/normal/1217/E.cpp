#include<bits/stdc++.h>
using namespace std;
int n,m,a[222222],tp,x,y,cur;
struct tnode
{
	int mn1[10],mn2[10];
	tnode()
	{
		for (int i=0;i<10;i++) mn1[i]=mn2[i]=1e9+10;
	}
}tree[888888];
void merge(tnode a,tnode b,tnode &c)
{
	c=tnode();
	for (int i=0;i<10;i++)
	{
		if (a.mn1[i]<c.mn1[i]) 
		{
			c.mn2[i]=c.mn1[i];
			c.mn1[i]=a.mn1[i];
		}
		else if (a.mn1[i]<c.mn2[i])
		{
			c.mn2[i]=a.mn1[i];
		}
		if (a.mn2[i]<c.mn1[i]) 
		{
			c.mn2[i]=c.mn1[i];
			c.mn1[i]=a.mn2[i];
		}
		else if (a.mn2[i]<c.mn2[i])
		{
			c.mn2[i]=a.mn2[i];
		}
		if (b.mn1[i]<c.mn1[i]) 
		{
			c.mn2[i]=c.mn1[i];
			c.mn1[i]=b.mn1[i];
		}
		else if (b.mn1[i]<c.mn2[i])
		{
			c.mn2[i]=b.mn1[i];
		}
		if (b.mn2[i]<c.mn1[i]) 
		{
			c.mn2[i]=c.mn1[i];
			c.mn1[i]=b.mn2[i];
		}
		else if (b.mn2[i]<c.mn2[i])
		{
			c.mn2[i]=b.mn2[i];
		}
	}
	
}
void build(int l,int r,int node)
{
	if (l==r)
	{
		int tt=a[l];
		for (int i=0;i<10;i++)
		{
			if (tt%10) tree[node].mn1[i]=a[l];
			tt/=10;
		}
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,node<<1);
	build(mid+1,r,(node<<1)|1);
	merge(tree[node<<1],tree[(node<<1)|1],tree[node]);
}
void update(int x,int l,int r,int node,int y)
{
	if (l==r)
	{
		int tt=y;
		for (int i=0;i<10;i++)
		{
			if (tt%10) tree[node].mn1[i]=y;
			else tree[node].mn1[i]=1e9+10;
			tt/=10;
		}
		return;
	}
	int mid=(l+r)>>1;
	if (x>mid) update(x,mid+1,r,(node<<1)|1,y);
	else update(x,l,mid,node<<1,y);
	merge(tree[node<<1],tree[(node<<1)|1],tree[node]);
}
tnode query(int beg,int en,int l,int r,int node)
{
	if (l>en || r<beg) return tnode();
	if (l>=beg && r<=en) return tree[node];
	int mid=(l+r)>>1;
	tnode ans=query(beg,en,l,mid,node<<1);
	merge(ans,query(beg,en,mid+1,r,(node<<1)|1),ans);
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	build(1,n,1);
	while(m--)
	{
		scanf("%d%d%d",&tp,&x,&y);
		if (tp==1)
		{
			update(x,1,n,1,y);
		}
		else
		{
			tnode ans=query(x,y,1,n,1);
			cur=2e9+100;
			for (int i=0;i<10;i++)
			{
				if (cur>ans.mn1[i]+ans.mn2[i] && ans.mn1[i]<=1e9 && ans.mn2[i]<=1e9) cur=ans.mn1[i]+ans.mn2[i];
			}
			if (cur>2e9) printf("-1\n");
			else printf("%d\n",cur);
		}
	}
	return 0;
}