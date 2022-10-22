#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define lc ls[p]
#define rc rs[p]
using namespace std;
const int N=3.5e4+5,INF=0x3fffffff;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int val[N<<6],ls[N<<6],rs[N<<6],cnt,res[N];
int build(int l,int r)
{
	int mid=(l+r)>>1,p;
	p=++cnt;
	if(r-l!=1)lc=build(l,mid),rc=build(mid,r);
	return p;
}
int update(int p,int l,int r,int x,int y,int v)
{
	int mid=(l+r)>>1,q;
	if(y<=l||r<=x)return p;
	q=++cnt;ls[q]=lc;rs[q]=rc;val[q]=val[p];
	if(x<=l&&r<=y)return val[q]+=v,q;
	ls[q]=update(ls[q],l,mid,x,y,v);
	rs[q]=update(rs[q],mid,r,x,y,v);
	return q;
}
void query(int p,int l,int r,int x,int y,int v)
{
	int mid=(l+r)>>1;
	if(y<=l||r<=x)return;
	if(r-l==1)
	{
		res[l]=val[p]+v;
		return;
	}
	query(lc,l,mid,x,y,v+val[p]);
	query(rc,mid,r,x,y,v+val[p]);
}
int n,k,a[N],f[N],g[N],t[N],rt[N],last[N];
void solve(int l,int r,int kl,int kr)
{
	int mid=(l+r)>>1,k=kl,sb=kr<mid?kr:mid;
	if(l==r)return;
	query(rt[mid],0,n,kl,sb,0);
	F(i,kl,sb)t[i]=f[i]+res[i];
	F(i,kl,sb)if(t[i]<t[k])k=i;
	g[mid]=t[k];
	solve(l,mid,kl,k+1);
	solve(mid+1,r,k,kr);
}
int main()
{
	read(n);read(k);
	F(i,0,n)read(a[i]),--a[i];
	F(i,1,n+1)f[i]=INF;
	rt[0]=build(0,n);
	F(i,0,n)last[i]=-1;
	F(i,0,n)
	{
		if(~last[a[i]])rt[i+1]=update(rt[i],0,n,0,last[a[i]]+1,i-last[a[i]]);
		else rt[i+1]=rt[i];
		last[a[i]]=i;
	}
	F(i,0,k)
	{
		solve(1,n+1,0,n);
		F(i,0,n+1)f[i]=g[i];
	}
	printf("%d\n",f[n]);
	return 0;
}