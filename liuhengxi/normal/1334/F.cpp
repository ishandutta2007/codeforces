#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define lc (p<<1)
#define rc ((p<<1)|1)
using namespace std;
const int N=5e5+5;
const long long LLINF=0x3fffffffffffffffll;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
int n,a[N],p[N],m,b[N],c[N];
long long f[N],val[N<<2],tag[N<<2];
void build(int p,int l,int r)
{
	int mid=(l+r)>>1;
	val[p]=-LLINF;
	if(r-l==1)return;
	build(lc,l,mid);build(rc,mid,r);
}
inline void update(int p,long long v){tag[p]+=v,val[p]+=v;}
inline void pushdown(int p){update(lc,tag[p]);update(rc,tag[p]);tag[p]=0;}
void update(int p,int l,int r,int x,int y,long long v)
{
	int mid=(l+r)>>1;
	if(y<=l||r<=x)return;
	if(x<=l&&r<=y)return update(p,v);
	pushdown(p);
	update(lc,l,mid,x,y,v);update(rc,mid,r,x,y,v);
}
long long query(int p,int l,int r,int x)
{
	int mid=(l+r)>>1;
	if(r-l==1)return val[p];
	pushdown(p);
	if(x<mid)return query(lc,l,mid,x);
	else return query(rc,mid,r,x);
}
int main()
{
	long long ans;
	read(n);
	F(i,0,n)--read(a[i]);
	F(i,0,n)read(p[i]);
	F(i,0,read(m))--read(b[i]);
	F(i,0,n)if(b[c[i]=lower_bound(b,b+m,a[i])-b]!=a[i])c[i]=-1;
	F(i,0,n)f[i]=-LLINF;
	build(1,0,n);
	F(i,0,n)
	{
		if(~c[i])
		{
			if(c[i])f[i]=query(1,0,n,b[c[i]-1])+p[i];
			else f[i]=p[i];
		}
		if(p[i]>0)update(1,0,n,a[i],n,p[i]);
		if(~c[i])
		{
			long long delta;
			delta=f[i]-query(1,0,n,b[c[i]]);
			if(delta>0)update(1,0,n,a[i],a[i]+1,delta);
		}
	}
	ans=query(1,0,n,b[m-1]);
	if(ans>-LLINF/2)
	{
		puts("YES");
		ans=-ans;
		F(i,0,n)ans+=p[i];
		printf("%lld\n",ans);
	}
	else puts("NO");
	return 0;
}