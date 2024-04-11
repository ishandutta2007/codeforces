#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,q,m,p,a[N],x[N],y[N],b,bl[N],v[2*N],c[2*N],l,r,t,ans[N];
struct mex
{
	int c[2*N],d[2*N],bl[N];
	mex(){c[0]=1e9;d[0]=1;}
	void add(int x){d[bl[x]]+=!c[x]++;}
	void del(int x){d[bl[x]]-=!--c[x];}
	int query()
	{
		int i=0;
		while(d[i]==b)++i;
		i*=b;
		while(c[i])++i;
		return i;
	}
}mex;
struct query
{
	int time,l,r,id;
	bool operator<(query b)const{return bl[time]!=bl[b.time]?bl[time]<bl[b.time]:
	bl[l]!=bl[b.l]?bl[l]<bl[b.l]:r<b.r;}
}qy[N];
void add(int x){mex.del(c[a[x]]);mex.add(++c[a[x]]);}
void del(int x){mex.del(c[a[x]]);mex.add(--c[a[x]]);}
void modify(int x,int &y)
{
	int tmp=a[x];bool in=l<=x&&x<r;
	if(in)del(x);
	a[x]=y;
	if(in)add(x);
	y=tmp;
}
int main()
{
	read(n);read(q);while((long long)b*b*b<(long long)n*n)++b;
	F(i,0,n+1)bl[i]=i/b;
	F(i,0,n)read(a[i]),v[i]=a[i];
	F(i,0,q)
	{
		int op;read(op);
		if(op==1)
		{
			read(qy[p].l);read(qy[p].r);--qy[p].l;
			qy[p].time=m;qy[p].id=p;++p;
		}
		else
		{
			read(x[m]);read(y[m]);v[n+m]=y[m];--x[m++];
		}
	}
	sort(v,v+n+m);
	F(i,0,n)a[i]=lower_bound(v,v+n+m,a[i])-v;
	F(i,0,m)y[i]=lower_bound(v,v+n+m,y[i])-v;
	sort(qy,qy+p);
	F(i,0,p)
	{
		while(t<qy[i].time)modify(x[t],y[t]),++t;
		while(t>qy[i].time)--t,modify(x[t],y[t]);
		while(l>qy[i].l)add(--l);
		while(r<qy[i].r)add(r++);
		while(l<qy[i].l)del(l++);
		while(r>qy[i].r)del(--r);
		ans[qy[i].id]=mex.query();
	}
	F(i,0,p)printf("%d\n",ans[i]);
	return 0;
}