#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define lc ((p<<1)+1)
#define rc ((p<<1)+2)
using namespace std;
const int N=3e5+5,MOD=1000000009;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,m,a[N],f[N+1],fs[N+2];
int s[N<<2],ta[N<<2],tb[N<<2];
void build(int p,int l,int r)
{
	int mid=(l+r)>>1;
	if(r-l==1)return s[p]=a[l],void();
	build(lc,l,mid);build(rc,mid,r);
	s[p]=(s[lc]+s[rc])%MOD;
}
void pushdown(int p,int l,int r)
{
	int mid=(l+r)>>1,ra,rb;
	int k=mid-l,q=r-mid;
	(ta[lc]+=ta[p])%=MOD;(tb[lc]+=tb[p])%=MOD;
	if(k==1)
	{
		ra=tb[p];
		rb=(ta[p]+tb[p])%MOD;
	}
	else
	{
		ra=((long long)f[k-2]*ta[p]+(long long)f[k-1]*tb[p])%MOD;
		rb=((long long)f[k-1]*ta[p]+(long long)f[k-0]*tb[p])%MOD;
	}
	(ta[rc]+=ra)%=MOD;
	(tb[rc]+=rb)%=MOD;
	(s[lc]+=((long long)fs[k]*ta[p]+(long long)(fs[k+1]-1+MOD)*tb[p])%MOD)%=MOD;
	(s[rc]+=((long long)fs[q]*ra+(long long)(fs[q+1]-1+MOD)*rb)%MOD)%=MOD;
	ta[p]=tb[p]=0;
}
void update(int p,int l,int r,int x,int v)
{
	int mid=(l+r)>>1;
	if(r-l==1)return s[p]=(s[p]+v)%MOD,void();
	pushdown(p,l,r);
	if(x<mid)
	{
		update(lc,l,mid,x,v);
		int k=mid-x,q=r-mid,ra,rb;
		if(k==1)ra=0,rb=v;
		else ra=(long long)f[k-2]*v%MOD,rb=(long long)f[k-1]*v%MOD;
		(ta[rc]+=ra)%=MOD;(tb[rc]+=rb)%=MOD;
		(s[rc]+=((long long)fs[q]*ra+(long long)(fs[q+1]-1+MOD)*rb)%MOD)%=MOD;
	}
	else update(rc,mid,r,x,v);
	s[p]=(s[lc]+s[rc])%MOD;
}
int query(int p,int l,int r,int x,int y)
{
	int mid=(l+r)>>1,a,b;
	if(y<=l||r<=x)return 0;
	if(x<=l&&r<=y)return s[p];
	pushdown(p,l,r);
	a=query(lc,l,mid,x,y);
	b=query(rc,mid,r,x,y);
	return (a+b)%MOD;
}
int main()
{
	read(n);read(m);
	F(i,0,n)read(a[i]);
	build(0,0,n);
	f[0]=f[1]=1;
	F(i,2,n+1)f[i]=(f[i-1]+f[i-2])%MOD;
	F(i,0,n+1)fs[i+1]=(fs[i]+f[i])%MOD;
	while(m--)
	{
		int op,l,r;read(op);read(l);read(r);--l;
		if(op==1&&l!=r)
		{
			update(0,0,n,l,1);
			if(r<n)update(0,0,n,r,MOD-f[r-l]);
			if(r+1<n)update(0,0,n,r+1,MOD-f[r-l-1]);
		}
		if(op==2)
		{
			printf("%d\n",query(0,0,n,l,r));
		}
	}
	return 0;
}