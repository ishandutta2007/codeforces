#include<cstdio>
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
template<typename S,typename T,S e(),T o(),S f(S,S),S g(T,S),T h(T,T),int N,S d()=e>
struct lazysegtree
{
#define lc (p<<1)
#define rc (p<<1|1)
private:
	int n;S seg[N<<2];T tag[N<<2];
	void build(int p,int l,int r)
	{
		int mid=(l+r)>>1;
		tag[p]=o();
		if(r-l==1)return seg[p]=d(),void();
		build(lc,l,mid);build(rc,mid,r);
		seg[p]=f(seg[lc],seg[rc]);
	}
	void build(int p,int l,int r,S (*const &dd)(int))
	{
		int mid=(l+r)>>1;
		tag[p]=o();
		if(r-l==1)return seg[p]=dd(l),void();
		build(lc,l,mid,dd);build(rc,mid,r,dd);
		seg[p]=f(seg[lc],seg[rc]);
	}
	inline void update(int p,const T &v){seg[p]=g(v,seg[p]);tag[p]=h(v,tag[p]);}
	inline void pushdown(int p){update(lc,tag[p]);update(rc,tag[p]);tag[p]=o();}
	void update(int p,int l,int r,const int &x,const int &y,const T &v)
	{
		int mid=(l+r)>>1;
		if(x==l&&r==y)return update(p,v);
		pushdown(p);
		if(y<=mid)update(lc,l,mid,x,y,v);
		else if(mid<=x)update(rc,mid,r,x,y,v);
		else update(lc,l,mid,x,mid,v),update(rc,mid,r,mid,y,v);
		seg[p]=f(seg[lc],seg[rc]);
	}
	S query(int p,int l,int r,const int &x,const int &y)
	{
		int mid=(l+r)>>1;
		if(x==l&&r==y)return seg[p];
		pushdown(p);
		if(y<=mid)return query(lc,l,mid,x,y);
		if(mid<=x)return query(rc,mid,r,x,y);
		return f(query(lc,l,mid,x,mid),query(rc,mid,r,mid,y));
	}
public:
	void build(int n_){build(1,0,n=n_);}
	void build(int n_,S dd(int)){build(1,0,n=n_,dd);}
	void update(int x,int y,T v){if(x<y)update(1,0,n,x,y,v);}
	S query(int x,int y){return x<y?query(1,0,n,x,y):e();}
#undef lc
#undef rc
};
struct S
{
	long long s[10];
	S(){F(i,0,10)s[i]=0;}
};
struct T
{
	int t[10];
	T(){F(i,0,10)t[i]=i;}
};
S e(){return S();}
T o(){return T();}
S f(S a,S b){S c;F(i,0,10)c.s[i]=a.s[i]+b.s[i];return c;}
S g(T a,S b){S c;F(i,0,10)c.s[a.t[i]]+=b.s[i];return c;}
T h(T a,T b){T c;F(i,0,10)c.t[i]=a.t[b.t[i]];return c;}
constexpr int N=1e5+5;
lazysegtree<S,T,e,o,f,g,h,N> seg;
int n,q,a[N];
S dd(int id)
{
	S ans;
	for(int i=1;i<=a[id];i*=10)ans.s[(a[id]/i)%10]+=i;
	return ans;
}
int main()
{
	read(n,q);
	F(i,0,n)read(a[i]);
	seg.build(n,dd);
	while(q--)
	{
		int opt;read(opt);
		if(opt==1)
		{
			int l,r,x,y;read(l,r,x,y);--l;
			T tmp;tmp.t[x]=y;
			seg.update(l,r,tmp);
		}
		if(opt==2)
		{
			int l,r;read(l,r);--l;
			S res=seg.query(l,r);
			long long ans=0;
			F(i,0,10)ans+=res.s[i]*i;
			printf("%lld\n",ans);
		}
	}
	return 0;
}