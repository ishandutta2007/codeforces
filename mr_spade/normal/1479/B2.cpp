#include<bits/stdc++.h>
using namespace std;
namespace sgt
{
	const int N=4e5+5;
	int Min[N],tag[N];
	inline void push_down(int x)
	{
		if(tag[x]==0)
			return;
		Min[x<<1]+=tag[x];tag[x<<1]+=tag[x];
		Min[x<<1|1]+=tag[x];tag[x<<1|1]+=tag[x];
		tag[x]=0;return;
	}
	inline void push_up(int x)
	{
		Min[x]=min(Min[x<<1],Min[x<<1|1]);
	}
	void modify(int x,int lp,int rp,int l,int r,int k)
	{
		if(lp==l&&rp==r)
			return Min[x]+=k,tag[x]+=k,void();
		int mid=(lp+rp)>>1;
		push_down(x);
		if(r<=mid)
			modify(x<<1,lp,mid,l,r,k);
		else if(l>=mid+1)
			modify(x<<1|1,mid+1,rp,l,r,k);
		else
			modify(x<<1,lp,mid,l,mid,k),modify(x<<1|1,mid+1,rp,mid+1,r,k);
		push_up(x);
	}
	int query(int x,int lp,int rp,int l,int r)
	{
		if(l>r)
			return 0x3f3f3f3f;
		if(lp==l&&rp==r)
			return Min[x];
		int mid=(lp+rp)>>1;
		push_down(x);
		if(r<=mid)
			return query(x<<1,lp,mid,l,r);
		else if(l>=mid+1)
			return query(x<<1|1,mid+1,rp,l,r);
		else
			return min(query(x<<1,lp,mid,l,mid),query(x<<1|1,mid+1,rp,mid+1,r));
	}
}
const int N=1e5+5;
int n,m;
int a[N];
signed main()
{
	int t,t2;
	register int i;
	scanf("%d",&n);
	if(n==1)
		return puts("1"),0;
	a[0]=n+1;
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	m=n+1;
	sgt::modify(1,1,m,1,m-1,0x3f3f3f3f);
	for(i=1;i<=n;i++)
	{
		t=min(min(sgt::query(1,1,m,1,a[i]-1)+1,sgt::query(1,1,m,a[i]+1,m)+1),sgt::query(1,1,m,a[i],a[i]));
		if(a[i]!=a[i-1])
			sgt::modify(1,1,m,1,m,1);
		t2=sgt::query(1,1,m,a[i-1],a[i-1]);
		if(t2>t)
			sgt::modify(1,1,m,a[i-1],a[i-1],t-t2);
	}
	printf("%d\n",sgt::query(1,1,m,1,m));
	return 0;
}