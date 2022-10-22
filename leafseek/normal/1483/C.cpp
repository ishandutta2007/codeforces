#include<bits/stdc++.h>
#define int long long
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
const int MaxN=300000+5,Inf=(1LL<<60)-1;
int OVERALLLen;
struct SegmentTree
{
	int sum[MaxN<<2],tag[MaxN<<2];
	inline int ls(const register int idx){return idx<<1;}
	inline int rs(const register int idx){return idx<<1|1;}
	inline void push_up(const register int idx)
		{sum[idx]=max(sum[ls(idx)],sum[rs(idx)]);}
	inline void Build(const register int idx,const register int lef,const register int rig)
	{
		tag[idx]=-Inf;
		if(lef==rig)
			{sum[idx]=-Inf;return;}
		register int mid=(lef+rig)>>1;
		Build(ls(idx),lef,mid);
		Build(rs(idx),mid+1,rig);
		push_up(idx);
	}
	inline void func(const register int idx,const register int lef,const register int rig,const register int val)
	{
		sum[idx]=max(sum[idx],val);
		tag[idx]=max(tag[idx],val);
	}
	inline void push_down(const register int idx,const register int lef,const register int rig)
	{
		register int mid=(lef+rig)>>1;
		func(ls(idx),lef,mid,tag[idx]);
		func(rs(idx),mid+1,rig,tag[idx]);
		tag[idx]=-Inf;
	}
	inline void Update(const register int ql,const register int qr,const register int val,const register int idx=1,const register int lef=0,const register int rig=OVERALLLen)
	{
		if(!(ql<=qr))
			return;
		if(ql<=lef&&rig<=qr)
			{func(idx,lef,rig,val);return;}
		push_down(idx,lef,rig);
		register int mid=(lef+rig)>>1;
		if(ql<=mid)
			Update(ql,qr,val,ls(idx),lef,mid);
		if(qr>mid)
			Update(ql,qr,val,rs(idx),mid+1,rig);
		push_up(idx);
	}
	inline int Query(const register int ql,const register int qr,const register int idx=1,const register int lef=0,const register int rig=OVERALLLen)
	{
		if(!(ql<=qr))
			return -Inf;
		if(ql<=lef&&rig<=qr)
			return sum[idx];
		register int Rec=-Inf;
		push_down(idx,lef,rig);
		register int mid=(lef+rig)>>1;
		if(ql<=mid)
			Rec=max(Rec,Query(ql,qr,ls(idx),lef,mid));
		if(qr>mid)
			Rec=max(Rec,Query(ql,qr,rs(idx),mid+1,rig));
		return Rec;
	}
};
SegmentTree St,temp;
int h[MaxN],rev[MaxN],lef[MaxN],rig[MaxN],b[MaxN];
struct Fuck
{
	int idx;
	int lef;
	int rig;
	inline bool operator < (const Fuck& other) const
	{
		return (idx<other.idx);
	}
};
Fuck fuck[MaxN];
signed main()
{
	register int n;
	scanf("%lld",&n);
	OVERALLLen=n;
	rep(i,1,n)
		scanf("%lld",&h[i]),rev[h[i]]=i;
	temp.Build(1,0,n);
	rep(i,1,n)
	{
		temp.Update(h[i],h[i],+i);
		lef[i]=+temp.Query(1,h[i]-1);
		if(lef[i]==-Inf) lef[i]=1;
		else ++lef[i];
	}
	temp.Build(1,0,n);
	dow(i,n,1)
	{
		temp.Update(h[i],h[i],-i);
		rig[i]=-temp.Query(1,h[i]-1);
		if(rig[i]==+Inf) rig[i]=n;
		else --rig[i];
	}
	rep(i,1,n)
		scanf("%lld",&b[i]);
	St.Build(1,0,n);
	St.Update(0,0,0);
	rep(i,1,n)
	{
		fuck[i].lef=lef[i];
		fuck[i].rig=rig[i];
		fuck[i].idx=i;
	}
	sort(fuck+1,fuck+n+1);
	rep(i,1,n)
		St.Update(fuck[i].idx,fuck[i].rig,St.Query(fuck[i].lef-1,fuck[i].idx-1)+b[fuck[i].idx]);
	printf("%lld\n",St.Query(n,n));
	return 0;
}