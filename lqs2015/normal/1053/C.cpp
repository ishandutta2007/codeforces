#include<iostream>
#include<cstdio>
using namespace std;
long long n,q,a[222222],w[222222],t[222222],bit[888888],tree3[888888],tree1[888888],tree2[888888],sz,x,y,l,r,mid,f,ff,s[222222];
const long long mod=1e9+7;
void build(long long l,long long r,long long *a,long long *tree,long long node)
{
	if (l==r)
	{
		if (l<=n) tree[node]=a[l];
		else tree[node]=0;
		return;
	}
	long long mid=(l+r)/2;
	build(l,mid,a,tree,node*2);
	build(mid+1,r,a,tree,node*2+1);
	tree[node]=tree[node*2]+tree[node*2+1];
}
void update(long long x,long long l,long long r,long long node,long long del,long long *tree)
{
	tree[node]+=del;
	if (l==r) return;
	long long mid=(l+r)/2;
	if (x>mid) update(x,mid+1,r,node*2+1,del,tree);
	else update(x,l,mid,node*2,del,tree);
}
long long query(long long beg,long long en,long long l,long long r,long long node,long long *tree)
{
	if (l>en || r<beg) return 0;
	if (l>=beg && r<=en) return tree[node];
	long long mid=(l+r)/2;
	return query(beg,en,l,mid,node*2,tree)+query(beg,en,mid+1,r,node*2+1,tree);
}
void update(long long p,long long x)
{
	while(p<=sz)
	{
		bit[p]+=x;
		p+=p&(-p);
	}
}
long long sum(long long p)
{
	long long res=0;
	while(p>=1)
	{
		res+=bit[p];
		p-=p&(-p);
	}
	return res;
}
int main()
{
	scanf("%I64d%I64d",&n,&q);
	for (long long i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
	} 
	for (long long i=1;i<=n;i++)
	{
		scanf("%I64d",&w[i]);
		t[i]=w[i]*a[i]%mod;
		s[i]=w[i]*i%mod;
	}
	sz=1;
	while(sz<n) sz*=2;
	build(1,sz,t,tree1,1);
	build(1,sz,w,tree2,1);
	build(1,sz,s,tree3,1);
	for (int i=1;i<=n;i++)
	{
		update(i,w[i]);
	}
	while(q--)
	{
		scanf("%I64d%I64d",&x,&y);
		if (x<0)
		{
			x=-x;
			update(x,1,sz,1,y-w[x],tree2);
			update(x,1,sz,1,(y-w[x])*a[x]%mod,tree1);
			update(x,1,sz,1,(y-w[x])*x%mod,tree3);
			update(x,y-w[x]);
			w[x]=y;
		}
		else
		{
			l=x;r=y;
			f=query(x,y,1,sz,1,tree2);
			while(l<=r)
			{
				mid=(l+r)/2;
				ff=sum(mid)-sum(x-1);
				if (ff>=f-ff) r=mid-1;
				else l=mid+1;
			}	
			long long ans=(((a[l]-l)*(query(x,l-1,1,sz,1,tree2)%mod)%mod-query(x,l-1,1,sz,1,tree1)+query(x,l-1,1,sz,1,tree3)-query(l+1,y,1,sz,1,tree3)+query(l+1,y,1,sz,1,tree1)-((a[l]-l)*(query(l+1,y,1,sz,1,tree2)%mod)%mod))%mod+mod)%mod;
			printf("%I64d\n",ans);
		}
	}
	return 0;
}