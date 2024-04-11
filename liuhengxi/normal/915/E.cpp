#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define lc (p<<1)
#define rc ((p<<1)|1)
using namespace std;
const int N=3e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,m,x[N],y[N],t[N],v[N<<1],val[N<<3],tag[N<<3];
void build(int p,int l,int r)
{
	int mid=(l+r)>>1;
	val[p]=v[r]-v[l];
	if(r-l==1)return;
	build(lc,l,mid);build(rc,mid,r);
}
void set(const int &p,const int &l,const int &r,const int &k){tag[p]=k;val[p]=(k-1)*(v[r]-v[l]);}
void update(int p,int l,int r,int x,int y,int k)
{
	int mid=(l+r)>>1;
	if(y<=l||r<=x)return;
	if(x<=l&&r<=y)return set(p,l,r,k);
	if(tag[p])
	{
		set(lc,l,mid,tag[p]);
		set(rc,mid,r,tag[p]);
		tag[p]=0;
	}
	update(lc,l,mid,x,y,k);update(rc,mid,r,x,y,k);
	val[p]=val[lc]+val[rc];
}
int main()
{
	read(n);read(m);
	v[m<<1]=0;
	v[m<<1|1]=n;
	n=(m+1)<<1;
	F(i,0,m)
	{
		read(x[i]);read(y[i]);read(t[i]);
		v[i<<1]=--x[i],v[i<<1|1]=y[i];
	}
	sort(v,v+n);
	F(i,0,m)x[i]=lower_bound(v,v+n,x[i])-v,y[i]=lower_bound(v,v+n,y[i])-v;
	v[n]=v[n-1];
	build(1,0,n);
	F(i,0,m)
	{
		update(1,0,n,x[i],y[i],t[i]);
		printf("%d\n",val[1]);
	}
	return 0;
}