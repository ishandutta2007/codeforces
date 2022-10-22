#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5;
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
int m,fa[41],c[N][11];
bool o[41];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
struct T{int x,l[11],r[11],c;};
T e(){T a;a.x=-1;return a;}
T f(T u,T v)
{
	T w;
	if(!~u.x)return v;
	if(!~v.x)return u;
	F(i,0,m<<2)fa[i]=i,o[i]=false;
	F(i,0,m)v.l[i]+=m<<1,v.r[i]+=m<<1;
	F(i,0,m)if(c[v.x][i]==c[v.x-1][i])fa[find(u.r[i])]=find(v.l[i]);
	w.x=u.x;
	w.c=u.c+v.c;
	F(i,0,m)
	{
		o[w.l[i]=find(u.l[i])]=true;
		o[w.r[i]=find(v.r[i])]=true;
	}
	F(i,0,m)
	{
		if(!o[find(u.r[i])])o[find(u.r[i])]=true,++w.c;
		if(!o[find(v.l[i])])o[find(v.l[i])]=true,++w.c;
	}
	F(i,0,m<<2)o[i]=false;
	F(i,0,m)o[w.l[i]]=o[w.r[i]]=true;
	int p=0;
	F(i,0,m)
	{
		if((w.l[i]=find(w.l[i]))>=(m<<1))
		{
			while(o[p])++p;
			o[p]=true;
			fa[w.l[i]]=fa[p]=p;
			w.l[i]=find(w.l[i]);
		}
		if((w.r[i]=find(w.r[i]))>=(m<<1))
		{
			while(o[p])++p;
			o[p]=true;
			fa[w.r[i]]=fa[p]=p;
			w.r[i]=find(w.r[i]);
		}
	}
	return w;
}
segtree<T,e,f,N> seg;
int n,q;
T dd(int id)
{
	int cnt=-1;
	T a;a.x=id;a.c=0;
	F(i,0,m)
	{
		a.l[i]=a.r[i]=i&&c[id][i]==c[id][i-1]?cnt:++cnt;
	}
	return a;
}
int main()
{
	read(m,n,q);
	F(i,0,m)F(j,0,n)read(c[j][i]);
	seg.build(n,dd);
	while(q--)
	{
		int l,r;--read(l),read(r);
		T res=seg.query(l,r);
		int ans=res.c;
		F(i,0,m<<1)o[i]=false;
		F(i,0,m)
		{
			ans+=!o[res.l[i]];o[res.l[i]]=true;
			ans+=!o[res.r[i]];o[res.r[i]]=true;
		}
		printf("%d\n",ans);
	}
	return 0;
}