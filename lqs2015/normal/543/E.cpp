#include<bits/stdc++.h>
using namespace std;
const unsigned long long N=8e6,T=200000;
struct hjt
{
	unsigned long long msk[8050000],sum;
	int rt[200002],sz;
	unsigned long long code(int lp,int rp,int val,int lazy)
	{
		return (1ull*lp*N*T+1ull*rp*T+1ull*val+1ull*lazy);
	}
	void decode(unsigned long long mskk,int &lp,int &rp,int &val,int &lazy,int l,int r,int mid)
	{
		lp=mskk/N/T;rp=(mskk/T)%N;
		sum=mskk%T;
		val=max((l==mid ? lp : msk[lp]%T),(mid+1==r ? rp : msk[rp]%T));
		lazy=sum-val;
	}
	int update(int pre,int beg,int en,int lp,int rp)
	{
		if (lp>en || rp<beg) return pre;
		if (lp==rp) return pre+1;
		int pos=++sz;
		if (lp>=beg && rp<=en)
		{
			msk[pos]=msk[pre]+1;
			return pos;
		}
		int ls,rs,val,lazy,mid=(lp+rp)>>1;
		decode(msk[pre],ls,rs,val,lazy,lp,rp,mid);
		ls=update(ls,beg,en,lp,mid);rs=update(rs,beg,en,mid+1,rp);
		msk[pos]=code(ls,rs,max((lp==mid ? ls : msk[ls]%T),(mid+1==rp ? rs : msk[rs]%T)),lazy);
		return pos;
	}
	int query(int beg,int en,int lp,int rp,int node)
	{
		if (!node) return 0;
		if (lp>en || rp<beg) return 0;
		if (lp==rp) return node;
		if (lp>=beg && rp<=en) return msk[node]%T;
		int mid=(lp+rp)>>1,ls,rs,val,lazy;
		decode(msk[node],ls,rs,val,lazy,lp,rp,mid);
		return max(query(beg,en,lp,mid,ls),query(beg,en,mid+1,rp,rs))+lazy;
	}
}tree;
int n,m,a[200002],b[200002],l,r,x,q,ans,L,R;
bool cmp(int i,int j)
{
	return a[i]>a[j];
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) b[i]=i;
	sort(b+1,b+n+1,cmp);
	for (int i=1;i<=n;i++)
	{
		L=max(1,b[i]-m+1);R=b[i];
		tree.rt[i]=tree.update(tree.rt[i-1],L,R,1,n-m+1);
	}
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d%d",&l,&r,&x);
		x^=ans;
		L=1;R=n;
		while(L<=R)
		{
			int mid=(L+R)>>1;
			if (a[b[mid]]>=x) L=mid+1;
			else R=mid-1;
		}
		ans=tree.query(l,r,1,n-m+1,tree.rt[R]);
		ans=m-ans;
		printf("%d\n",ans);
	}
	return 0;
}