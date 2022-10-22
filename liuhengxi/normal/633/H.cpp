// LUOGU_RID: 90684621
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
constexpr int N=(1<<15)+5;
unsigned mod;
int v[N],c[N];
namespace seg
{
	struct data
	{
		unsigned a00,a01,a10,a11,a0,a1;
	}s[(1<<16)+5];
	int n;
	void build(int n_)
	{
		n=n_;
		while(n!=(n&-n))n+=n&-n;
		F(i,1,2*n)s[i]=data({1,0,0,1,0,0});
	}
	void merge(data &a,const data &b,const data &c)
	{
		a.a00=(b.a00*c.a00+b.a01*c.a10)%mod;
		a.a01=(b.a00*c.a01+b.a01*c.a11)%mod;
		a.a10=(b.a10*c.a00+b.a11*c.a10)%mod;
		a.a11=(b.a10*c.a01+b.a11*c.a11)%mod;
		a.a0=(b.a0+b.a00*c.a0+b.a01*c.a1)%mod;
		a.a1=(b.a1+b.a10*c.a0+b.a11*c.a1)%mod;
	}
	void update(int x,int t)
	{
		bool cc=!!c[x];
		if(cc!=!!(c[x]+=t))
		{
			if(c[x])s[x+n]=data({0,1,1,1,0,v[x]%mod});
			else s[x+n]=data({1,0,0,1,0,0});
			x+=n;
			while(x>>=1)merge(s[x],s[x<<1],s[x<<1|1]);
		}
	}
}
struct query
{
	int l,r,id;
}qy[N];
int n,m,a[N],q,b,ans[N];
int main()
{
	read(n,mod);
	while(b*b<n)++b;
	F(i,0,n)v[i]=read(a[i]);
	sort(v,v+n);
	m=(int)(unique(v,v+n)-v);
	F(i,0,n)a[i]=(int)(lower_bound(v,v+m,a[i])-v);
	seg::build(m);
	F(i,0,read(q))read(qy[i].l,qy[i].r),--qy[i].l,qy[i].id=i;
	sort(qy,qy+q,[](query x,query y){return x.l/b!=y.l/b?x.l<y.l:(x.l/b&1?x.r>y.r:x.r<y.r);});
	int l=0,r=0;
	F(i,0,q)
	{
		while(l>qy[i].l)seg::update(a[--l],1);
		while(r<qy[i].r)seg::update(a[r++],1);
		while(l<qy[i].l)seg::update(a[l++],-1);
		while(r>qy[i].r)seg::update(a[--r],-1);
		ans[qy[i].id]=seg::s[1].a1;
	}
	F(i,0,q)printf("%d\n",ans[i]);
	return 0;
}