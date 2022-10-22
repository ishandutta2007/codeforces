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
constexpr int N=5e5+8;
constexpr long long LLINF=0x3fffffffffffffff;
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
		if(x==l&&r==y)return seg[p];
		if(y<=mid)return query(lc,l,mid,x,y);
		if(mid<=x)return query(rc,mid,r,x,y);
		return f(query(lc,l,mid,x,mid),query(rc,mid,r,mid,y));
	}
public:
	void build(int n_){build(1,0,n=n_);}
	void build(int n_,T dd(int)){build(1,0,n=n_,dd);}
	void update(int x,T v){update(1,0,n,x,v);}
	T get(int x){return get(1,0,n,x);}
	T query(int x,int y){return x<y?query(1,0,n,x,y):e();}
#undef lc
#undef rc
}; 
namespace SEG1
{
	struct S{long long max;};
	S e(){return {-LLINF};}
	S f(S a,S b){return {max(a.max,b.max)};}
	segtree<S,e,f,N> seg1;
}
namespace SEG2
{
	struct S{long long ans,lmax,rmax;};
	S e(){return {-LLINF,-LLINF,-LLINF};}
	S f(S a,S b){return {max({a.ans,b.ans,a.lmax+b.rmax}),max(a.lmax,b.lmax),max(a.rmax,b.rmax)};}
	segtree<S,e,f,N> seg2;
}
using SEG1::seg1;
using SEG2::seg2;
int n,q,a[3][N],l[N],r[N],k[N],id[N];
long long b[N],c[N];
SEG1::S dd1(int i){return {b[i]};}
SEG2::S dd2(int i){return {-LLINF,seg1.get(i).max,c[i]};}
int main()
{
	read(n,q);
	F(i,0,3)F(j,0,n)read(a[i][i+j]);
	F(i,0,q)read(l[i],r[i],k[i]),++r[i],id[i]=i;
	sort(id,id+q,[](int u,int v){return r[u]<r[v];});
	n+=3;
	F(i,0,n)a[0][i]-=a[1][i],a[2][i]-=a[1][i];
	F(i,0,n)b[i+1]=b[i]+a[0][i];
	for(int i=n;~--i;)c[i]=c[i+1]+a[2][i];
	seg1.build(n,dd1);
	F(i,0,q)
	{
		int u=id[i];
		seg1.update(r[u],{max(seg1.get(r[u]).max,seg1.query(l[u],r[u]).max-k[u])});
	}
	seg2.build(n,dd2);
	long long ans=-LLINF;
	F(i,0,q)ans=max(ans,seg2.query(l[i],r[i]+1).ans-k[i]);
	F(i,0,n)ans+=a[1][i];
	printf("%lld\n",ans);
	return 0;
}