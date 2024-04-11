#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
constexpr int N=2e5+5;
constexpr int INF=0x3fffffff;
namespace seg
{
	struct data
	{
		int min,tag;
	}s[(1<<19)+5];
#define lc (p<<1)
#define rc (p<<1|1)
	inline void update(int p,int v){s[p].min+=v;s[p].tag+=v;}
	void build(int p,int l,int r)
	{
		s[p].min=-r;
		if(r-l==1)return;
		int mid=(l+r)>>1;
		build(lc,l,mid);
		build(rc,mid,r);
	}
	inline void pushdown(int p)
	{
		update(lc,s[p].tag);
		update(rc,s[p].tag);
		s[p].tag=0;
	}
	void update(int p,int l,int r,int x,int y,int v)
	{
		if(x==l&&r==y)return update(p,v);
		int mid=(l+r)>>1;
		pushdown(p);
		if(y<=mid)update(lc,l,mid,x,y,v);
		else if(mid<=x)update(rc,mid,r,x,y,v);
		else update(lc,l,mid,x,mid,v),update(rc,mid,r,mid,y,v);
		s[p].min=min(s[lc].min,s[rc].min);
	}
	int query(int p,int l,int r,int x,int y,int v)
	{
		if(x<=l&&r<=y)
		{
			if(s[p].min>v)return -1;
			if(r-l==1)return l;
			int mid=(l+r)>>1;
			pushdown(p);
			if(s[rc].min<=v)return query(rc,mid,r,x,y,v);
			return query(lc,l,mid,x,y,v);
		}
		int mid=(l+r)>>1;
		pushdown(p);
		if(y<=mid)return query(lc,l,mid,x,y,v);
		if(mid<=x)return query(rc,mid,r,x,y,v);
		int res=query(rc,mid,r,x,y,v);
		if(res!=-1)return res;
		return query(lc,l,mid,x,y,v);
	}
#undef lc
#undef rc
}
using seg::build;
using seg::update;
using seg::query;
int n,k,d,a[N],ad[N],last[N],v[N],gmaxlen,gmaxl;
int sx[N],sxp[N],txp,sn[N],snp[N],tnp;
void solve(int l,int r)
{
	int m=r-l;
	int maxlen=0,maxl=0;
	if(maxlen>gmaxlen)gmaxlen=maxlen,gmaxl=maxl;
	F(i,l,r)a[i]-=(a[i]%d+d)%d,v[i-l]=a[i]/=d;
	sort(v,v+m);
	F(i,l,r)ad[i]=(int)(lower_bound(v,v+m,a[i])-v);
	F(i,0,m)last[i]=r;
	int ri=r;
	txp=tnp=0;
	for(int i=r;--i>=l;)
	{
		ri=min(ri,last[ad[i]]);
		last[ad[i]]=i;
		while(txp&&a[i]>=sx[txp-1])
		{
			--txp;
			update(1,0,n,sxp[txp],txp?sxp[txp-1]:r,a[i]-sx[txp]);
		}
		sx[txp]=a[i];
		sxp[txp++]=i;
		while(tnp&&a[i]<=sn[tnp-1])
		{
			--tnp;
			update(1,0,n,snp[tnp],tnp?snp[tnp-1]:r,sn[tnp]-a[i]);
		}
		sn[tnp]=a[i];
		snp[tnp++]=i;
		int res=query(1,0,n,i,ri,k-i-1);
		if(~res&&res-i+1>=maxlen)maxlen=res-i+1,maxl=i;
	}
	if(maxlen>gmaxlen)gmaxlen=maxlen,gmaxl=maxl;
}
int main()
{
	read(n,k,d);
	F(i,0,n)read(a[i]);
	if(d==0)
	{
		int maxlen=0;
		for(int l=0,r=0;l<n;l=r)
		{
			while(r<n&&a[l]==a[r])++r;
			maxlen=max(maxlen,r-l);
		}
		for(int l=0,r=0;l<n;l=r)
		{
			while(r<n&&a[l]==a[r])++r;
			if(maxlen==r-l)return printf("%d %d\n",l+1,r),0;
		}
	}
	build(1,0,n);
	for(int l=0,r=0;l<n;l=r)
	{
		while(r<n&&(a[r]-a[l])%d==0)++r;
		solve(l,r);
	}
	printf("%d %d\n",gmaxl+1,gmaxl+gmaxlen);
	return 0;
}