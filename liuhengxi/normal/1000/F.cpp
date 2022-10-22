#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define lc ls[p]
#define rc rs[p]
using namespace std;
typedef const int &ci;
const int N=5e5+5,INF=0x3fffffff;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct query
{
	int l,r,id;
	bool operator<(query b)const{return r<b.r;}
}r[N];
int n,a[N],last[N],m,q,ls[N<<2],rs[N<<2],ind[N<<2],val[N],ans[N];
inline void pushup(ci p){ind[p]=val[ind[lc]]<val[ind[rc]]?ind[lc]:ind[rc];}
void build(ci p,ci l,ci r)
{
	int mid=(l+r)>>1;
	if(r-l==1)return ind[p]=l,val[l]=INF,void();
	ls[p]=p<<1;rs[p]=p<<1|1;
	build(lc,l,mid);build(rc,mid,r);
	pushup(p);
}
void build(){int p=1,l=0,r=n;build(p,l,r);}
void update(ci p,ci l,ci r,ci x,ci v)
{
	int mid=(l+r)>>1;
	if(r-l==1)return val[l]=v,void();
	if(x<mid)update(lc,l,mid,x,v);
	else update(rc,mid,r,x,v);
	pushup(p);
}
void update(int x,int v){int p=1,l=0,r=n;update(p,l,r,x,v);}
int query(ci p,ci l,ci r,ci x,ci y)
{
	int mid=(l+r)>>1;
	if(y<=l||r<=x)return -1;
	if(x<=l&&r<=y)return ind[p];
	int lans=query(lc,l,mid,x,y),rans=query(rc,mid,r,x,y);
	if(!~lans)return rans;
	if(!~rans)return lans;
	return val[lans]<val[rans]?lans:rans;
}
int query(int x,int y){int p=1,l=0,r=n;return query(p,l,r,x,y);}
int main()
{
	int now=0;
	read(n);
	F(i,0,n)read(a[i]),m=a[i]>m?a[i]:m,--a[i];
	F(i,0,m)last[i]=-1;
	read(q);
	F(i,0,q)read(r[i].l),--r[i].l,read(r[i].r),r[i].id=i;
	sort(r,r+q);
	build();
	F(i,0,q)
	{
		while(now<r[i].r)
		{
			if(~last[a[now]])update(last[a[now]],INF);
			update(now,last[a[now]]);
			last[a[now]]=now;++now;
		}
		ans[r[i].id]=query(r[i].l,r[i].r);
		if(val[ans[r[i].id]]>=r[i].l)ans[r[i].id]=-1;
		else ans[r[i].id]=a[ans[r[i].id]];
	}
	F(i,0,q)printf("%d\n",ans[i]+1);
	return 0;
}