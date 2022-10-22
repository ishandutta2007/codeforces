#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define lc (p<<1)
#define rc ((p<<1)|1)
using namespace std;
const int N=2e5+5,K=105,k=100;
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
int n,q,a[N],f[N<<2][K],ans[N];
inline void assign(int p,int x,int y){F(i,0,k)if(f[p][i]==x)f[p][i]=y;}
inline void assign(int p,int *g){F(i,0,k)f[p][i]=g[f[p][i]];}
inline void pushdown(int p){assign(lc,f[p]);assign(rc,f[p]);F(i,0,k)f[p][i]=i;}
void build(int p,int l,int r)
{
	int mid=(l+r)>>1;
	F(i,0,k)f[p][i]=i;
	if(r-l==1)return;
	build(lc,l,mid);build(rc,mid,r);
}
void update(int p,int l,int r,int x,int y,int xx,int yy)
{
	int mid=(l+r)>>1;
	if(y<=l||r<=x)return;
	if(x<=l&&r<=y)return assign(p,xx,yy);
	pushdown(p);
	update(lc,l,mid,x,y,xx,yy);
	update(rc,mid,r,x,y,xx,yy);
}
void dfs(int p,int l,int r)
{
	int mid=(l+r)>>1;
	if(r-l==1)return ans[l]=f[p][a[l]],void();
	pushdown(p);
	dfs(lc,l,mid);dfs(rc,mid,r);
}
int main()
{
	F(i,0,read(n))--read(a[i]);
	build(1,0,n);
	for(read(q);q--;)
	{
		int l,r,x,y;
		--read(l),read(r),--read(x),--read(y);
		update(1,0,n,l,r,x,y);
	}
	dfs(1,0,n);
	F(i,0,n)printf("%d ",ans[i]+1);
	puts("");
	return 0;
}