#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define lc ((p<<1)+1)
#define rc ((p<<1)+2)
using namespace std;
const int N=2e5+5,M4=1<<18,INF=0x3fffffff;
template<typename T>T& read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
	return x;
}
struct rook
{
	int x,y;
	bool operator<(rook b)const{return x>b.x;}
}r[N];
struct rect
{
	int x1,y1,x2,y2,id;
	bool operator<(rect b)const{return x1>b.x1;}
}q[N];
int n,m,k,qq,a[M4];
bool ans[N];
void build(int p,int l,int r)
{
	int mid=(l+r)>>1;
	a[p]=INF;
	if(r-l==1)return;
	build(lc,l,mid);build(rc,mid,r);
}
void update(int p,int l,int r,int x,int v)
{
	int mid=(l+r)>>1;
	if(r-l==1)return void(a[p]=v);
	if(x<mid)update(lc,l,mid,x,v);
	else update(rc,mid,r,x,v);
	a[p]=max(a[lc],a[rc]);
}
int query(int p,int l,int r,int x,int y)
{
	int mid=(l+r)>>1;
	if(y<=l||r<=x)return 0;
	if(x<=l&&r<=y)return a[p];
	return max(query(lc,l,mid,x,y),query(rc,mid,r,x,y));
}
void solve()
{
	build(0,0,m);
	for(int i=0,j=0;i<qq;++i)
	{
		while(j<k&&r[j].x>=q[i].x1)
		{
			update(0,0,m,r[j].y,r[j].x);
			++j;
		}
		ans[q[i].id]=ans[q[i].id]||query(0,0,m,q[i].y1,q[i].y2)<q[i].x2;
	}
}
int main()
{
	read(n);read(m);read(k);read(qq);
	F(i,0,k)--read(r[i].x),--read(r[i].y);
	F(i,0,qq)--read(q[i].x1),--read(q[i].y1),read(q[i].x2),read(q[q[i].id=i].y2);
	sort(r,r+k);sort(q,q+qq);
	solve();
	swap(n,m);
	F(i,0,k)swap(r[i].x,r[i].y);
	F(i,0,qq)swap(q[i].x1,q[i].y1),swap(q[i].x2,q[i].y2);
	sort(r,r+k);sort(q,q+qq);
	solve();
	F(i,0,qq)puts(ans[i]?"YES":"NO");
	return 0;
}