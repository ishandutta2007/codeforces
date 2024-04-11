#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define lc ((p<<1)+1)
#define rc ((p<<1)+2)
using namespace std;
const int N=1e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,q,a[N];
double s[N<<2],ta[N<<2],tb[N<<2]/* x = ax + b */;
void build(int p,int l,int r)
{
	int mid=(l+r)>>1;
	ta[p]=1.0;tb[p]=0.0;
	if(r-l==1)
	{
		s[p]=a[l];
		return;
	}
	build(lc,l,mid);build(rc,mid,r);
	s[p]=s[lc]+s[rc];
}
void pushdown(int p,int l,int r)
{
	double a=ta[p],b=tb[p];
	int mid=(l+r)>>1;
	s[lc]=s[lc]*a+b*(mid-l);s[rc]=s[rc]*a+b*(r-mid);
	ta[lc]*=a;ta[rc]*=a;
	tb[lc]=tb[lc]*a+b;tb[rc]=tb[rc]*a+b;
	ta[p]=1.0;tb[p]=0.0;
}
double query(int p,int l,int r,int x,int y)
{
	int mid=(l+r)>>1;
	if(y<=l||r<=x)return 0.0;
	if(x<=l&&r<=y)return s[p];
	pushdown(p,l,r);
	return query(lc,l,mid,x,y)+query(rc,mid,r,x,y);
}
void update(int p,int l,int r,int x,int y,double a,double b)
{
	int mid=(l+r)>>1;
	if(y<=l||r<=x)return;
	if(x<=l&&r<=y)
	{
		s[p]=s[p]*a+b*(r-l);
		ta[p]*=a;tb[p]=tb[p]*a+b;
		return;
	}
	pushdown(p,l,r);
	update(lc,l,mid,x,y,a,b);
	update(rc,mid,r,x,y,a,b);
	s[p]=s[lc]+s[rc];
}
int main()
{
	read(n);read(q);
	F(i,0,n)read(a[i]);
	build(0,0,n);
	while(q--)
	{
		int op;read(op);
		if(op==1)
		{
			int l1,r1,l2,r2;read(l1);read(r1);read(l2);read(r2);--l1,--l2;
			double a1=query(0,0,n,l1,r1)/(r1-l1),a2=query(0,0,n,l2,r2)/(r2-l2);
			update(0,0,n,l1,r1,1.0-1.0/(r1-l1),a2/(r1-l1));
			update(0,0,n,l2,r2,1.0-1.0/(r2-l2),a1/(r2-l2));
		}
		else
		{
			int l,r;read(l);read(r);
			printf("%.8lf\n",query(0,0,n,--l,r));
		}
	}
	return 0;
}