#include<cstdio>
namespace sgt
{
	const int N=1e6+5;
	int sum[N],tag[N];
	inline void push_up(int x)
	{
		sum[x]=sum[x<<1]+sum[x<<1|1];
	}
	inline void push_down(int x,int lp,int rp)
	{
		if(!~tag[x])
			return;
		int mid=(lp+rp)>>1;
		sum[x<<1]=tag[x]*(mid-lp+1);tag[x<<1]=tag[x];
		sum[x<<1|1]=tag[x]*(rp-mid);tag[x<<1|1]=tag[x];
		tag[x]=-1;
		return;
	}
	void build(int x,int lp,int rp,char *s)
	{
		tag[x]=-1;
		if(lp==rp)
			return sum[x]=s[lp]-'0',void();
		int mid=(lp+rp)>>1;
		build(x<<1,lp,mid,s);
		build(x<<1|1,mid+1,rp,s);
		push_up(x);
		return;
	}
	void modify(int x,int lp,int rp,int l,int r,int k)
	{
		if(lp==l&&rp==r)
		{
			sum[x]=k*(rp-lp+1);tag[x]=k;
			return;
		}
		push_down(x,lp,rp);
		int mid=(lp+rp)>>1;
		if(r<=mid)
			modify(x<<1,lp,mid,l,r,k);
		else if(l>=mid+1)
			modify(x<<1|1,mid+1,rp,l,r,k);
		else
			modify(x<<1,lp,mid,l,mid,k),modify(x<<1|1,mid+1,rp,mid+1,r,k);
		push_up(x);
		return;
	}
	int query(int x,int lp,int rp,int l,int r)
	{
		if(lp==l&&rp==r)
			return sum[x];
		push_down(x,lp,rp);
		int mid=(lp+rp)>>1;
		if(r<=mid)
			return query(x<<1,lp,mid,l,r);
		else if(l>=mid+1)
			return query(x<<1|1,mid+1,rp,l,r);
		else
			return query(x<<1,lp,mid,l,mid)+query(x<<1|1,mid+1,rp,mid+1,r);
	}
}
const int N=1e6+5;
int n,q;
char s[N],t[N];
int l[N],r[N];
inline void solve()
{
	int d;
	register int i;
	scanf("%d%d",&n,&q);
	scanf("%s%s",s+1,t+1);
	for(i=1;i<=q;i++)
		scanf("%d%d",&l[i],&r[i]);
	sgt::build(1,1,n,t);
	for(i=q;i>=1;i--)
	{
		d=sgt::query(1,1,n,l[i],r[i]);
		if(d*2<r[i]-l[i]+1)
			sgt::modify(1,1,n,l[i],r[i],0);
		else if((r[i]-l[i]+1-d)*2<r[i]-l[i]+1)
			sgt::modify(1,1,n,l[i],r[i],1);
		else
			return puts("NO"),void();
	}
	for(i=1;i<=n;i++)
		if(sgt::query(1,1,n,i,i)!=s[i]-'0')
			return puts("NO"),void();
	puts("YES");
}
signed main()
{
	int T;
	scanf("%d",&T);
	while(T--)
		solve();
	return 0;
}