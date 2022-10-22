#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=3e5+5;
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
		if(y<=l||r<=x)return e();
		if(x<=l&&r<=y)return seg[p];
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
struct T{int len,suf0,suf01,suf1,pre1,pre01,pre0,ans;}o[3]={{1,1,1,0,0,1,1,1},{1,0,1,1,1,1,0,1},{1,0,0,0,0,0,0,0}};
T e(){return T({0,0,0,0,0,0,0,0});}
T f(T u,T v){return T({u.len+v.len,
v.suf0+(v.suf0==v.len)*u.suf0,
(v.suf1==v.len?v.len+u.suf01:(v.suf01==v.len?v.len+u.suf0:v.suf01))
,v.suf1+(v.suf1==v.len)*u.suf1,
u.pre1+(u.pre1==u.len)*v.pre1,
(u.pre0==u.len?u.len+v.pre01:(u.pre01==u.len?u.len+v.pre1:u.pre01))
,u.pre0+(u.pre0==u.len)*v.pre0,
max({u.ans,v.ans,u.suf0+v.pre01,u.suf01+v.pre1})});}
segtree<T,e,f,N> seg;
int n,a[N],q;
long long d[N];
T dd(int id){return d[id]>0?o[0]:(d[id]<0?o[1]:o[2]);}
int main()
{
	F(i,0,read(n))read(a[i]);
	F(i,0,--n)d[i]=a[i+1]-a[i];
	if(n==0)
	{
		for(read(q);q--;)puts("1");
		return 0;
	}
	seg.build(n,dd);
	for(read(q);q--;)
	{
		int l,r,x;read(l)-=2,--read(r),read(x);
		if(0<=l&&l<n)
		{
			d[l]+=x;
			if(d[l]>0)seg.update(l,o[0]);
			else if(d[l]<0)seg.update(l,o[1]);
			else seg.update(l,o[2]);
		}
		if(0<=r&&r<n)
		{
			d[r]-=x;
			if(d[r]>0)seg.update(r,o[0]);
			else if(d[r]<0)seg.update(r,o[1]);
			else seg.update(r,o[2]);
		}
		printf("%d\n",seg.query(0,n).ans+1);
	}
	return 0;
}