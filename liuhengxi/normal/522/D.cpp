#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=5e5+5,INF=0x3fffffff;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct interval
{
	int l,r;
	bool operator<(interval b)const{return l>b.l;}
}b[N];
struct query
{
	int l,r,id;
	bool operator<(query b)const{return l>b.l;}
}q[N];
int n,m,k,a[N],v[N],p[N],c[N],ans[N];
void add(int x,int y)
{
	y=INF-y;
	for(++x;x<=n;x+=x&-x)c[x]=c[x]>y?c[x]:y;
}
int getmax(int x)
{
	int ans=0;
	for(;x;x-=x&-x)ans=ans>c[x]?ans:c[x];
	return INF-ans;
}
int main()
{
	read(n);read(m);
	F(i,0,n)read(a[i]),v[i]=a[i];
	F(i,0,m)read(q[i].l),read(q[i].r),--q[q[i].id=i].l;
	sort(q,q+m);
	sort(v,v+n);
	F(i,0,n)a[i]=lower_bound(v,v+n,a[i])-v;
	F(i,0,n)p[i]=-1;
	F(i,0,n)
	{
		if(~p[a[i]])
		{
			b[k].l=p[a[i]];b[k++].r=i;
		}
		p[a[i]]=i;
	}
	sort(b,b+k);
	++n;
	for(int i=0,j=0;i<m;++i)
	{
		while(j<k&&b[j].l>=q[i].l)
		{
			add(b[j].r,b[j].r-b[j].l);
			++j;
		}
		ans[q[i].id]=getmax(q[i].r);
	}
	F(i,0,m)if(ans[i]<INF)printf("%d\n",ans[i]);else puts("-1");
	return 0;
}