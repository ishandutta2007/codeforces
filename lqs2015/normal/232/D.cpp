#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[111111],s[222222],k,sa[222222],rnk[222222],tmp[222222],lcp[222222],sz,x,y,l,r,mid,m,len,lb,rb,ans,sn;
struct hjt
{
	int rt[222222],l[11111111],r[11111111],tree[11111111],szz;
	int build(int lp,int rp)
	{
		int pos=++szz;
		if (lp==rp) return pos;
		int mid=(lp+rp)/2;
		l[pos]=build(lp,mid);
		r[pos]=build(mid+1,rp);
		return pos;
	}
	int update(int x,int lp,int rp,int pre)
	{
		if (lp==rp)
		{
			szz++;
			tree[szz]=tree[pre]+1;
			return szz;
		}
		int pos=++szz,mid=(lp+rp)/2;
		l[pos]=l[pre];r[pos]=r[pre];
		if (x>mid) r[pos]=update(x,mid+1,rp,r[pre]);
		else l[pos]=update(x,lp,mid,l[pre]);
		tree[pos]=tree[l[pos]]+tree[r[pos]];
		return pos;
	}
	int query(int beg,int en,int lp,int rp,int nw,int pre)
	{
		if (lp>en || rp<beg) return 0;
		if (lp>=beg && rp<=en) return tree[nw]-tree[pre];
		int mid=(lp+rp)/2;
		return query(beg,en,lp,mid,l[nw],l[pre])+query(beg,en,mid+1,rp,r[nw],r[pre]);
	}
}tree;
struct segtree
{
	int tree[888888];
	void build(int l,int r,int node)
	{
		if (l==r)
		{
			if (l<=n) tree[node]=lcp[l];
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
}stree;
bool cmp(int i,int j)
{
	if (rnk[i]!=rnk[j]) return rnk[i]<rnk[j];
	int ri=i+k<=n ? rnk[i+k] : -2e9;
	int rj=j+k<=n ? rnk[j+k] : -2e9;
	return ri<rj;
}
void make_sa()
{
	for (int i=1;i<=n;i++)
	{
		sa[i]=i;
		rnk[i]=s[i];
	}
	for (k=1;k<=n;k*=2)
	{
		sort(sa+1,sa+n+1,cmp);
		tmp[sa[1]]=1;
		for (int i=2;i<=n;i++)
		{
			if (cmp(sa[i-1],sa[i])) tmp[sa[i]]=tmp[sa[i-1]]+1;
			else tmp[sa[i]]=tmp[sa[i-1]];
		}
		for (int i=1;i<=n;i++) rnk[i]=tmp[i];
	}
}
void make_lcp()
{
	int h=0;
	for (int i=1;i<=n;i++) rnk[sa[i]]=i;
	for (int i=1;i<=n;i++)
	{
		int j=sa[rnk[i]-1];
		if (h>0) h--;
		for (;i+h<=n && j+h<=n;h++)
		{
			if (s[i+h]!=s[j+h]) break;
		}
		lcp[rnk[i]-1]=h;
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<n;i++) s[i]=a[i+1]-a[i];
	for (int i=n;i<n+n-1;i++) s[i]=a[i-n+1]-a[i-n+2];
	sn=n;
	n=n+n-2;
	sz=1;
	while(sz<=n) sz*=2;
	make_sa();
	make_lcp();
	stree.build(1,sz,1);
	tree.rt[0]=tree.build(1,sz);
	for (int i=1;i<=n;i++)
	{
		tree.rt[i]=tree.update(sa[i],1,sz,tree.rt[i-1]); 
	}
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d%d",&x,&y);
		if (y==x)
		{
			printf("%d\n",n/2);
			continue;
		}
		len=y-x;
		l=1;r=rnk[x];
		while(l<=r)
		{
			mid=(l+r)/2;
			if (stree.query(mid,rnk[x]-1,1,sz,1)>=len) r=mid-1;
			else l=mid+1;
		}
		lb=l;
		l=rnk[x];r=n;
		while(l<=r)
		{
			mid=(l+r)/2;
			if (stree.query(rnk[x],mid-1,1,sz,1)>=len) l=mid+1;
			else r=mid-1;
		}
		rb=r;
		ans=tree.query(sn,sn-1+x-len-1,1,sz,tree.rt[rb],tree.rt[lb-1])+tree.query(sn-1+x+len+1,n,1,sz,tree.rt[rb],tree.rt[lb-1]);
		printf("%d\n",ans);
	}
	return 0;
}