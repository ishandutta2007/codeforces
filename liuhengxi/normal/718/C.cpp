#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define lc (p<<1)
#define rc ((p<<1)|1)
using namespace std;
typedef long long ll;
const int N=1e5+5,MOD=1000000007;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct mat
{
	int a00,a01,a10,a11;
	mat(int b=1){a00=b,a01=0,a10=0,a11=b;}
	mat(int b,int c,int d,int e){a00=b,a01=c,a10=d,a11=e;}
	mat operator+(mat b){return mat((a00+b.a00)%MOD,(a01+b.a01)%MOD,(a10+b.a10)%MOD,(a11+b.a11)%MOD);}
	mat operator*(mat b)
	{
		return mat(((ll)a00*b.a00+(ll)a01*b.a10)%MOD,((ll)a00*b.a01+(ll)a01*b.a11)%MOD,
		((ll)a10*b.a00+(ll)a11*b.a10)%MOD,((ll)a10*b.a01+(ll)a11*b.a11)%MOD);
	}
	mat operator^(int b)
	{
		mat c,a=*this;
		while(b)
		{
			if(b&1)c=c*a;
			a=a*a;b>>=1;
		}
		return c;
	}
	int val(){return (a01)%MOD;}
}f(0,1,1,1),val[N<<2],tag[N<<2];
int n,m,a[N];
void build(int p,int l,int r)
{
	int mid=(l+r)>>1;
	if(r-l==1)return val[p]=f^a[l],void();
	build(lc,l,mid);build(rc,mid,r);
	val[p]=val[lc]+val[rc];
}
void update(int p,int l,int r,int x,int y,mat v)
{
	int mid=(l+r)>>1;
	if(y<=l||r<=x)return;
	if(x<=l&&r<=y)
	{
		tag[p]=tag[p]*v;
		val[p]=val[p]*v;
		return;
	}
	tag[lc]=tag[lc]*tag[p];
	tag[rc]=tag[rc]*tag[p];
	val[lc]=val[lc]*tag[p];
	val[rc]=val[rc]*tag[p];
	tag[p]=mat();
	update(lc,l,mid,x,y,v);update(rc,mid,r,x,y,v);
	val[p]=val[lc]+val[rc];
}
mat query(int p,int l,int r,int x,int y)
{
	int mid=(l+r)>>1;
	if(y<=l||r<=x)return mat(0);
	if(x<=l&&r<=y)return val[p];
	tag[lc]=tag[lc]*tag[p];
	tag[rc]=tag[rc]*tag[p];
	val[lc]=val[lc]*tag[p];
	val[rc]=val[rc]*tag[p];
	tag[p]=mat();
	return query(lc,l,mid,x,y)+query(rc,mid,r,x,y);
}
int main()
{
	read(n);read(m);
	F(i,0,n)read(a[i]);
	build(1,0,n);
	while(m--)
	{
		int op;read(op);
		if(op==1)
		{
			int l,r,x;read(l);read(r);read(x);--l;
			update(1,0,n,l,r,f^x);
		}
		else
		{
			int l,r;read(l);read(r);--l;
			printf("%d\n",query(1,0,n,l,r).val());
		}
	}
	return 0;
}