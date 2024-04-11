#include<cstdio>
#include<algorithm>
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
int n,m,t[N],l[N],r[N],sum[N<<3],all[N<<3],rev[N<<3];
long long ll[N],rr[N],v[2*N];
int disc(long long x)
{
	int l=0,r=m,mid;
	while(r-l>1)
	{
		mid=(l+r)>>1;
		if(x<v[mid])r=mid;
		else l=mid;
	}
	return l;
}
void pushdown(int p,int l,int r)
{
	int mid=(l+r)>>1;
	if(r-l==1)return;
	if(all[p]==1)
	{
		all[lc]=1;all[rc]=1;
		rev[lc]=0;rev[rc]=0;
		sum[lc]=mid-l;sum[rc]=r-mid;
	}
	if(all[p]==2)
	{
		all[lc]=2;all[rc]=2;
		rev[lc]=0;rev[rc]=0;
		sum[lc]=0;sum[rc]=0;
	}
	all[p]=0;
	if(rev[p]==1)
	{
		if(all[lc])all[lc]=3-all[lc];
		else rev[lc]=1-rev[lc];
		if(all[rc])all[rc]=3-all[rc];
		else rev[rc]=1-rev[rc];
		sum[lc]=mid-l-sum[lc];
		sum[rc]=r-mid-sum[rc];
	}
	rev[p]=0;
}
void update1(int p,int l,int r,int x,int y)
{
	int mid=(l+r)>>1;
	if(y<=l||r<=x)return;
	if(x<=l&&r<=y)
	{
		sum[p]=r-l;
		all[p]=1;rev[p]=0;
		return;
	}
	pushdown(p,l,r);
	update1(lc,l,mid,x,y);update1(rc,mid,r,x,y);
	sum[p]=sum[lc]+sum[rc];
}
void update2(int p,int l,int r,int x,int y)
{
	int mid=(l+r)>>1;
	if(y<=l||r<=x)return;
	if(x<=l&&r<=y)
	{
		sum[p]=0;
		all[p]=2;rev[p]=0;
		return;
	}
	pushdown(p,l,r);
	update2(lc,l,mid,x,y);update2(rc,mid,r,x,y);
	sum[p]=sum[lc]+sum[rc];
}
void update3(int p,int l,int r,int x,int y)
{
	int mid=(l+r)>>1;
	if(y<=l||r<=x)return;
	if(x<=l&&r<=y)
	{
		if(all[p])all[p]=3-all[p];
		else rev[p]=1-rev[p];
		sum[p]=r-l-sum[p];
		return;
	}
	pushdown(p,l,r);
	update3(lc,l,mid,x,y);update3(rc,mid,r,x,y);
	sum[p]=sum[lc]+sum[rc];
}
int query(int p,int l,int r)
{
	int mid=(l+r)>>1;
	if(r-l==1)return l;
	pushdown(p,l,r);
	if(sum[lc]==mid-l)return query(rc,mid,r);
	else return query(lc,l,mid);
}
void unique(int &m)
{
	int del=0;
	for(int i=1;i+del<m;)
	{
		if(v[i+del]!=v[i-1])v[i]=v[i+del],++i;
		else ++del;
	}
	m-=del;
}
int main()
{
	read(n);
	F(i,0,n)read(t[i]),read(ll[i]),read(rr[i]),v[2*i]=ll[i],v[2*i+1]=++rr[i];
	v[2*n]=1;sort(v,v+(m=2*n+1));unique(m);
	F(i,0,n)l[i]=disc(ll[i]),r[i]=disc(rr[i]);
	F(i,0,n)
	{
		if(t[i]==1)update1(0,0,m,l[i],r[i]);
		if(t[i]==2)update2(0,0,m,l[i],r[i]);
		if(t[i]==3)update3(0,0,m,l[i],r[i]);
		printf("%lld\n",v[query(0,0,m)]);
	}
	return 0;
}