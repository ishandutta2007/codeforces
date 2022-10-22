#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define lc (p<<1)
#define rc ((p<<1)|1)
using namespace std;
const int N=2e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct twomin
{
	unsigned f,s;
	twomin(unsigned a=0x7fffffff,unsigned b=0x7fffffff){f=a,s=b;}
	twomin operator+(twomin b)const{return f<b.f?twomin(f,min(s,min(b.f,b.s))):twomin(b.f,min(b.s,min(f,s)));}
};
struct node
{
	twomin t[9];
	node(){}
	node(int x){for(int i=0,d=1;i<9;++i,d*=10)t[i]=twomin(x/d%10?x:0x7fffffff);}
	node operator+(node b)const{node c;F(i,0,9)c.t[i]=t[i]+b.t[i];return c;}
}s[N<<2];
int n,m,a[N];
void build(int p,int l,int r)
{
	int mid=(l+r)>>1;
	if(r-l==1)return s[p]=node(a[l]),void();
	build(lc,l,mid),build(rc,mid,r);
	s[p]=s[lc]+s[rc];
}
void update(int p,int l,int r,int x,int v)
{
	int mid=(l+r)>>1;
	if(r-l==1)return s[p]=node(v),void();
	if(x<mid)update(lc,l,mid,x,v);
	else update(rc,mid,r,x,v);
	s[p]=s[lc]+s[rc];
}
node query(int p,int l,int r,int x,int y)
{
	int mid=(l+r)>>1;
	if(y<=l||r<=x)return node();
	if(x<=l&&r<=y)return s[p];
	return query(lc,l,mid,x,y)+query(rc,mid,r,x,y);
}
int main()
{
	read(n);read(m);
	F(i,0,n)read(a[i]);
	build(1,0,n);
	while(m--)
	{
		int opt;read(opt);
		if(opt==1)
		{
			int i,x;read(i);read(x);--i;
			update(1,0,n,i,x);
		}
		if(opt==2)
		{
			int l,r;node res;unsigned ans=-1;read(l);read(r);--l;
			res=query(1,0,n,l,r);
			F(i,0,9)if(res.t[i].f+res.t[i].s<ans)ans=res.t[i].f+res.t[i].s;
			printf("%d\n",(signed)ans>0?(signed)ans:-1);
		}
	}
	return 0;
}