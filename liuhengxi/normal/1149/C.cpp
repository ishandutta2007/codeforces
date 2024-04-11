#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5;
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
struct T{int l,r,a,ll,rr,s,lr,rl;}b[2];
T e(){return T({0,0,0,0,0,0,0,0});}
T f(T u,T v)
{
	T res;
	res.l=max({u.l,u.s+v.ll+2*u.lr,-u.s+v.l});
	res.r=max({v.r,-v.s+u.rr+2*v.rl,v.s+u.r});
	res.a=max({u.a,v.a,u.r+v.ll,v.l+u.rr});
	res.ll=max(u.ll,u.s+v.ll);
	res.rr=max(v.rr,-v.s+u.rr);
	res.lr=max(u.lr,-u.s+v.lr);
	res.rl=max(v.rl,v.s+u.rl);
	res.s=u.s+v.s;
	return res;
}
segtree<T,e,f,N> seg;
int n,q;
char s[N];
T dd(int id){return b[s[id]==')'];}
int main()
{
	b[0]=T({1,1,1,1,0,1,0,1});
	b[1]=T({1,1,1,0,1,-1,1,0});
	read(n,q);
	scanf("%s",s);
	n=2*n-2;
	seg.build(n,dd);
	printf("%d\n",seg.query(0,n).a);
	while(q--)
	{
		int x,y;read(x,y);--x,--y;
		swap(s[x],s[y]);
		if(s[x]!=s[y])seg.update(x,b[s[x]==')']),seg.update(y,b[s[y]==')']);
		printf("%d\n",seg.query(0,n).a);
	}
	return 0;
}