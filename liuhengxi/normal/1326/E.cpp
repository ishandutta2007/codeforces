#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define lc ((p<<1)+1)
#define rc ((p<<1)+2)
using namespace std;
const int N=3e5+5,INF=0x0fffffff;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,p[N],q[N],val[4*N],tag[4*N],now;
void pushdown(int p)
{
	tag[lc]+=tag[p];val[lc]+=tag[p];
	tag[rc]+=tag[p];val[rc]+=tag[p];
	tag[p]=0;
}
void update(int p,int l,int r,int x,int y,int v)
{
	int mid=(l+r)>>1;
	if(y<=l||r<=x)return;
	if(x<=l&&r<=y)
	{
		val[p]+=v;
		tag[p]+=v;
		return;
	}
	pushdown(p);
	update(lc,l,mid,x,y,v);
	update(rc,mid,r,x,y,v);
	val[p]=val[lc]>val[rc]?val[lc]:val[rc];
}
int main()
{
	read(n);
	F(i,0,n)
	{
		int a;read(a);
		p[--a]=i;
	}
	F(i,0,n)
	{
		read(q[i]);--q[i];
	}
	now=n;
	update(0,0,n,0,p[--now]+1,1),update(0,0,n,p[now],p[now]+1,INF);
	F(i,0,n)
	{
		while(val[0]<=INF&&now>0)
			update(0,0,n,0,p[--now]+1,1),update(0,0,n,p[now],p[now]+1,INF);
		printf("%d ",now+1);
		update(0,0,n,0,q[i]+1,-1);
	}
	return 0;
}