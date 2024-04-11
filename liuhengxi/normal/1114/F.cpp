#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=4e5+5,P[62]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,
137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293},
MOD=1000000007;
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
template<typename S,typename T,S e(),T o(),S f(S,S),S g(T,S),T h(T,T),int N,S d()=e>struct lazysegtree
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
		if(y<=l||r<=x)return;
		if(x<=l&&r<=y)return update(p,v);
		pushdown(p);
		update(lc,l,mid,x,y,v);update(rc,mid,r,x,y,v);
		seg[p]=f(seg[lc],seg[rc]);
	}
	S query(int p,int l,int r,const int &x,const int &y)
	{
		int mid=(l+r)>>1;
		if(y<=l||r<=x)return e();
		if(x<=l&&r<=y)return seg[p];
		pushdown(p);
		return f(query(lc,l,mid,x,y),query(rc,mid,r,x,y));
	}
public:
	void build(int n_){build(1,0,n=n_);}
	void build(int n_,S dd(int)){build(1,0,n=n_,dd);}
	void update(int x,int y,T v){update(1,0,n,x,y,v);}
	S query(int x,int y){return query(1,0,n,x,y);}
#undef lc
#undef rc
};
int pow(int aa,int b)
{
	long long a=aa,c=1;
	for(;b;b>>=1,(a*=a)%=MOD)if(b&1)(c*=a)%=MOD;
	return (int)c;
}
struct S
{
	int cnt,prod;long long mask;
	S(){}
	S(int a,int b,long long c){cnt=a,prod=b,mask=c;}
};
struct T
{
	int mul;long long mask;
	T(){}
	T(int a,long long b){mul=a,mask=b;}
};
S e(){return S(0,1,0);}
T o(){return T(1,0);}
S f(S a,S b)
{
	S c;
	c.cnt=a.cnt+b.cnt;
	c.prod=int((long long)a.prod*b.prod%MOD);
	c.mask=a.mask|b.mask;
	return c;
}
S g(T a,S b)
{
	b.prod=int(b.prod*(long long)pow(a.mul,b.cnt)%MOD);
	b.mask|=a.mask;
	return b;
}
T h(T a,T b)
{
	T c;
	c.mul=int((long long)a.mul*b.mul%MOD);
	c.mask=a.mask|b.mask;
	return c;
}
lazysegtree<S,T,e,o,f,g,h,N> seg;
int n,q,a[N],Q[62];
long long getmask(int x)
{
	long long mask=0;
	F(i,0,62)if(x%P[i]==0)mask|=1ll<<i;
	return mask;
}
S dd(int pos){return S(1,a[pos],getmask(a[pos]));}
int main()
{
	F(i,0,62)Q[i]=int((P[i]-1ll)*pow(P[i],MOD-2)%MOD);
	read(n,q);
	F(i,0,n)read(a[i]);
	seg.build(n,dd);
	while(q--)
	{
		char opt[10];scanf("%s",opt);
		if(opt[0]=='M')
		{
			int l,r,x;read(l,r,x);--l;
			seg.update(l,r,T(x,getmask(x)));
		}
		if(opt[0]=='T')
		{
			int l,r;read(l,r);--l;
			S res=seg.query(l,r);int ans=res.prod;
			F(i,0,62)if(res.mask>>i&1)ans=int((long long)ans*Q[i]%MOD);
			printf("%d\n",ans);
		}
	}
	return 0;
}