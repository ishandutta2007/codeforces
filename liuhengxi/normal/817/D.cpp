#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define lc ((p<<1)+1)
#define rc ((p<<1)+2)
using namespace std;
typedef long long ll;
const int N=1e6+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,m,a[N];
ll min[2][N<<2],max[2][N<<2],ans;
void pushdown(ll a[2][N<<2],int p)
{
	if(a[0][p]==0)
	{
		a[0][lc]=a[1][lc]=0;
		a[0][rc]=a[1][rc]=0;
	}
}
void update(ll a[2][N<<2],int p,int l,int r,int x,int v)
{
	int mid=(l+r)>>1;
	if(r-l>1)pushdown(a,p);
	a[0][p]+=v;
	a[1][p]+=(ll)x*v;
	if(r-l==1)return;
	if(x<mid)update(a,lc,l,mid,x,v);
	else update(a,rc,mid,r,x,v);
}
int sum(ll a[2][N<<2],int p,int l,int r,int x,int y)
{
	int mid=(l+r)>>1;
	if(y<=l||r<=x)return 0;
	if(x<=l&&r<=y)return a[0][p];
	pushdown(a,p);
	return sum(a,lc,l,mid,x,y)+sum(a,rc,mid,r,x,y);
}
void erase(ll a[2][N<<2],int p,int l,int r,int x,int y)
{
	int mid=(l+r)>>1;
	if(y<=l||r<=x)return;
	if(x<=l&&r<=y)
	{
		a[0][p]=0;a[1][p]=0;
		return;
	}
	pushdown(a,p);
	erase(a,lc,l,mid,x,y);erase(a,rc,mid,r,x,y);
	a[0][p]=a[0][lc]+a[0][rc];
	a[1][p]=a[1][lc]+a[1][rc];
}
int main()
{
	read(n);
	F(i,0,n)read(a[i]);
	F(i,0,n)if(a[i]>m)m=a[i];
	F(i,0,n)--a[i];
	F(i,0,n)
	{
		int c=sum(min,0,0,m,a[i],m);
		erase(min,0,0,m,a[i],m);
		update(min,0,0,m,a[i],c+1);
		c=sum(max,0,0,m,0,a[i]);
		erase(max,0,0,m,0,a[i]);
		update(max,0,0,m,a[i],c+1);
		ans+=max[1][0]-min[1][0];
	}
	printf("%lld\n",ans);
	return 0;
}