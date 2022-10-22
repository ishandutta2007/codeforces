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
constexpr int N=1e5+5,INF=0x3fffffff;
template<typename T,T e(),T f(T,T),int N,T d()=e>struct segtree
{
#define lc (p<<1)
#define rc (p<<1|1)
private:
	int n;T seg[N<<2];
	void build(int p,int l,int r)
	{
		int mid=(l+r)>>1;
		if(r-l==1)return seg[p]=d(),void();
		build(lc,l,mid);build(rc,mid,r);
		seg[p]=f(seg[lc],seg[rc]);
	}
	void build(int p,int l,int r,T (*const &dd)(int))
	{
		int mid=(l+r)>>1;
		if(r-l==1)return seg[p]=dd(l),void();
		build(lc,l,mid,dd);build(rc,mid,r,dd);
		seg[p]=f(seg[lc],seg[rc]);
	}
	void update(int p,int l,int r,const int &x,const T &v)
	{
		int mid=(l+r)>>1;
		if(r-l==1)return seg[p]=v,void();
		if(x<mid)update(lc,l,mid,x,v);
		else update(rc,mid,r,x,v);
		seg[p]=f(seg[lc],seg[rc]);
	}
	T get(int p,int l,int r,const int &x)
	{
		int mid=(l+r)>>1;
		if(r-l==1)return seg[p];
		if(x<mid)return get(lc,l,mid,x);
		else return get(rc,mid,r,x);
	}
	T query(int p,int l,int r,const int &x,const int &y)
	{
		int mid=(l+r)>>1;
		if(x<=l&&r<=y)return seg[p];
		if(y<=mid)return query(lc,l,mid,x,y);
		if(x>=mid)return query(rc,mid,r,x,y);
		return f(query(lc,l,mid,x,y),query(rc,mid,r,x,y));
	}
public:
	void build(int n_){build(1,0,n=n_);}
	void build(int n_,T dd(int)){build(1,0,n=n_,dd);}
	void update(int x,T v){update(1,0,n,x,v);}
	T get(int x){return get(1,0,n,x);}
	T query(int x,int y){return query(1,0,n,x,y);}
#undef lc
#undef rc
};
struct segment{int l,r;};
inline segment empty(){return segment({INF,-INF});}
inline segment merge(segment a,segment b){return segment({min(a.l,b.l),max(a.r,b.r)});}
segtree<segment,empty,merge,N> seg[36];
int n,q,a[N],h=35,nowk;
long long _1=1ll<<35;
bool sp;
inline segment dd(int id)
{
	if(nowk==0)
	{
		int l=a[id],r=a[id+1];
		if(l==r)return empty();
		if(l>r)swap(l,r);
		return segment({l,r});
	}
	segment res=seg[nowk-1].query(id,id+1);
	if(res.l<res.r)return seg[nowk-1].query(res.l,res.r);
	else return empty();
}
int main()
{
	read(n,q);
	if(n==1)
	{
		while(q--)puts("0");
		return 0;
	}
	F(i,0,n)--read(a[i]);
	F(i,0,h)
	{
		nowk=i;
		seg[i].build(n-1,dd);
	}
	segment all=seg[0].query(0,n-1);
	sp=all.l!=0||all.r!=n-1;
	while(q--)
	{
		int l,r;read(l,r);--l,--r;
		long long ans=0;
		if(sp)ans=l==0&&r==n-1?0:-1;
		else
		{
			if(l==r)ans=-1;
			else if(l==0&&r==n-1)ans=0;
			else
			{
				int hh=h;
				if(l<r)
				{
					segment tmp=seg[18].query(l,r);
					if(tmp.l==0&&tmp.r==n-1)hh=18;
				}
				for(int i=hh;~--i;)
				{
					if(l<r)
					{
						segment res=seg[i].query(l,r);
						if(res.l!=0||res.r!=n-1)
						{
							l=res.l,r=res.r;
							ans+=1ll<<i;
						}
					}
					else ans+=1ll<<i;
				}
				++ans;
				if(ans==_1)ans=-1;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}