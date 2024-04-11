#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5,INF=0x3fffffff;
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
int n,q;
char s[N];
struct mat
{
	int a[4][4];
}at,bt,ct;
mat mat_e(){mat e;F(i,0,4)F(j,0,4)e.a[i][j]=INF;F(i,0,4)e.a[i][i]=0;return e;}
mat mat_f(mat a,mat b){mat c;F(i,0,4)F(j,0,4)c.a[i][j]=INF;
F(i,0,4)F(k,0,4)F(j,0,4)c.a[i][j]=min(c.a[i][j],a.a[i][k]+b.a[k][j]);return c;}
mat mat_dd(int pos){return s[pos]=='a'?at:s[pos]=='b'?bt:ct;}
segtree<mat,mat_e,mat_f,N> seg;
int main()
{
	at=bt=ct=mat_e();
	at.a[0][0]=1;at.a[0][1]=0;at.a[1][2]=1;at.a[2][3]=1;
	bt.a[1][1]=1;bt.a[1][2]=0;bt.a[0][1]=1;bt.a[2][3]=1;
	ct.a[2][2]=1;ct.a[2][3]=0;ct.a[0][1]=1;ct.a[1][2]=1;
	read(n,q);
	scanf("%s",s);
	seg.build(n,mat_dd);
	while(q--)
	{
		int i;char c[2];--read(i);scanf("%s",c);
		seg.update(i,c[0]=='a'?at:c[0]=='b'?bt:ct);
		mat res=seg.query(0,n);
		printf("%d\n",min({res.a[0][0],res.a[0][1],res.a[0][2]}));
	}
	return 0;
}