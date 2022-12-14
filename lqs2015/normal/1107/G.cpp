#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
long long n,a,d[333333],c[333333],b[333333],L[333333],R[333333],ans,Ls,Rs,sm;
deque<pair<long long,long long> > q;
pair<long long,long long> add;
struct node
{
	long long sum,mx,ls,rs;
}tree[1555555];
void pushup(long long node)
{
	tree[node].sum=tree[node<<1].sum+tree[(node<<1)|1].sum;
	tree[node].mx=max(tree[node<<1].mx,tree[(node<<1)|1].mx);
	tree[node].mx=max(tree[node].mx,tree[node<<1].rs+tree[(node<<1)|1].ls);
	tree[node].ls=max(tree[node<<1].ls,tree[node<<1].sum+tree[(node<<1)|1].ls);
	tree[node].rs=max(tree[(node<<1)|1].rs,tree[(node<<1)|1].sum+tree[node<<1].rs);
}
void build(long long l,long long r,long long node)
{
	if (l==r)
	{
		tree[node].sum=c[l];
		tree[node].mx=max(0ll,c[l]);
		tree[node].ls=max(0ll,c[l]);
		tree[node].rs=max(0ll,c[l]);
		return;
	}
	long long mid=(l+r)>>1;
	build(l,mid,node<<1);
	build(mid+1,r,(node<<1)|1);
	pushup(node);
}
long long queryl(long long beg,long long en,long long l,long long r,long long node)
{
	if (beg>en) return -1e18;
	if (l>en || r<beg) return -1e18;
	if (l>=beg && r<=en) 
	{
		long long res=tree[node].ls+sm;
		sm+=tree[node].sum;
		return res;
	}
	long long mid=(l+r)>>1;
	long long lp=queryl(beg,en,l,mid,node<<1),rp=queryl(beg,en,mid+1,r,(node<<1)|1);
	return max(lp,rp);
}
long long queryr(long long beg,long long en,long long l,long long r,long long node)
{
	if (beg>en) return -1e18;
	if (l>en || r<beg) return -1e18;
	if (l>=beg && r<=en) 
	{
		long long res=tree[node].rs+sm;
		sm+=tree[node].sum;
		return res;
	}
	long long mid=(l+r)>>1;
	long long lp=queryr(beg,en,mid+1,r,(node<<1)|1),rp=queryr(beg,en,l,mid,node<<1);
	return max(lp,rp);
}
long long query(long long beg,long long en,long long l,long long r,long long node)
{
	if (l>en || r<beg) return -1e18;
	if (l>=beg && r<=en) return tree[node].mx;
	long long mid=(l+r)>>1,res=-1e18,ls,rs;
	res=max(res,query(beg,en,l,mid,node<<1));
	res=max(res,query(beg,en,mid+1,r,(node<<1)|1));
	sm=0;ls=queryr(beg,mid,l,mid,(node<<1));
	sm=0;rs=queryl(mid+1,en,mid+1,r,(node<<1)|1);
	res=max(res,ls+rs);
	return res;
}
int main()
{
	scanf("%lld%lld",&n,&a);
	for (long long i=1;i<=n;i++)
	{
		scanf("%lld%lld",&d[i],&c[i]);
	}
	for (long long i=1;i<=n;i++) c[i]=a-c[i];
	build(1,n,1);
	for (long long i=1;i<n;i++) b[i]=(d[i+1]-d[i])*(d[i+1]-d[i]);
	for (long long i=1;i<n;i++)
	{
		add=make_pair(b[i],i);
		while(!q.empty() && q.back().first<=add.first) q.pop_back();
		if (q.empty()) L[i]=1;
		else L[i]=q.back().second+1;
		q.push_back(add); 
	}
	q.clear();
	for (long long i=n-1;i>=1;i--)
	{
		add=make_pair(b[i],i);
		while(!q.empty() && q.back().first<=add.first) q.pop_back();
		if (q.empty()) R[i]=n-1;
		else R[i]=q.back().second-1;
		q.push_back(add); 
	}
	for (long long i=1;i<=n-1;i++) R[i]++;
	for (long long i=1;i<=n;i++) ans=max(ans,c[i]);
	for (long long i=1;i<n;i++)
	{
		sm=0;
		ans=max(ans,query(L[i],R[i],1,n,1)-b[i]);
	}
	printf("%lld\n",ans);
	return Accepted;
}