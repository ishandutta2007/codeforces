#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define lc (p<<1)
#define rc ((p<<1)|1)
const int N=1e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,m,a[N],max[N<<2];long long sum[N<<2];
inline void pushup(const int &p)
{
	max[p]=std::max(max[lc],max[rc]);
	sum[p]=sum[lc]+sum[rc];
}
void build(int p,int l,int r)
{
	int mid=(l+r)>>1;
	if(r-l==1)return max[p]=sum[p]=a[l],void();
	build(lc,l,mid);build(rc,mid,r);
	pushup(p);
}
void assign(int p,int l,int r,int x,int v)
{
	int mid=(l+r)>>1;
	if(r-l==1)return max[p]=sum[p]=v,void();
	if(x<mid)assign(lc,l,mid,x,v);else assign(rc,mid,r,x,v);
	pushup(p);
}
void modulo(int p,int l,int r,int x,int y,int v)
{
	int mid=(l+r)>>1;
	if(y<=l||r<=x||max[p]<v)return;
	if(r-l==1)return max[p]=sum[p]=sum[p]%v,void();
	modulo(lc,l,mid,x,y,v);modulo(rc,mid,r,x,y,v);
	pushup(p);
}
long long query(int p,int l,int r,int x,int y)
{
	int mid=(l+r)>>1;
	if(y<=l||r<=x)return 0;
	if(x<=l&&r<=y)return sum[p];
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
			int l,r;read(l);read(r);--l;
			printf("%lld\n",query(1,0,n,l,r));
		}
		if(op==2)
		{
			int l,r,x;read(l);read(r);read(x);--l;
			modulo(1,0,n,l,r,x);
		}
		if(op==3)
		{
			int k,x;read(k);read(x);--k;
			assign(1,0,n,k,x);
		}
	}
	return 0;
}