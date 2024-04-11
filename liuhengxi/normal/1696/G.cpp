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
constexpr int N=2e5+5;
struct matrix{long long a[9];matrix(){a[0]=a[4]=a[8]=0;a[1]=a[2]=a[3]=a[5]=a[6]=a[7]=-LLINF;}};
matrix e(){return matrix();}
matrix f(matrix a,matrix b)
{
	matrix c;
	#define func(i,j) c.a[i*3+j]=max({a.a[i*3]+b.a[j],a.a[i*3+1]+b.a[3+j],a.a[i*3+2]+b.a[6+j]});
	func(0,0);func(0,1);func(0,2);
	func(1,0);func(1,1);func(1,2);
	func(2,0);func(2,1);func(2,2);
	return c;
}
segtree<matrix,e,f,N> seg;
int n,q,x,y,b[N];
long long den;
matrix dd(int id)
{
	long long u=b[id];
	matrix c;
	c.a[0]=c.a[1]=c.a[2]=0;
	c.a[3]=c.a[4]=u*y;
	c.a[6]=u*(x+y);
	c.a[5]=c.a[7]=c.a[8]=-LLINF;
	return c;
}
int main()
{
	read(n,q,x,y);
	if(x>y)swap(x,y);
	den=y*(long long)(x+y);
	F(i,0,n)read(b[i]);
	seg.build(n,dd);
	while(q--)
	{
		int opt;
		read(opt);
		if(opt==1)
		{
			int k,v;read(k,v);b[--k]=v;
			seg.update(k,dd(k));
		}
		if(opt==2)
		{
			int l,r;read(l,r);--l;
			matrix res=seg.query(l,r);
			printf("%.12lf\n",(double)*max_element(res.a,res.a+9)/(double)den);
		}
	}
	return 0;
}