#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define pt(u) point(x[u],-f[u])
using namespace std;
const int N=1e6+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct rect
{
	int x,y;long long a;
	bool operator<(rect b)const{return x<b.x;}
}r[N];
struct point{long long x,y;point(){}point(long long a,long long b){x=a,y=b;}}pt[N];
int n,x[N],y[N],q[N],qf,qr;
long long a[N],f[N],ans;
bool slopecmp(point a,point b,point c,point d)// k_AB < k_CD
{return (b.y-a.y)*(double)(d.x-c.x)<(d.y-c.y)*(double)(b.x-a.x);}// a.x < b.x  c.x < d.x
long long w(int v,int u){return f[v]+(x[u]-x[v])*(long long)y[u]-a[u];}
int main()
{
	read(n);
	F(i,0,n)read(r[i].x),read(r[i].y),read(r[i].a);
	sort(r,r+n);
	F(i,0,n)x[i+1]=r[i].x,y[i+1]=r[i].y,a[i+1]=r[i].a;
	f[0]=0;q[qr++]=0;
	F(i,1,n+1)
	{
		while(qf+1<qr&&w(q[qf],i)<w(q[qf+1],i))++qf;
		f[i]=w(q[qf],i);
		pt[i]=point(x[i],-f[i]);
		while(qf+1<qr&&slopecmp(pt[q[qr-1]],pt[i],pt[q[qr-2]],pt[q[qr-1]]))--qr;
		q[qr++]=i;
	}
	F(i,0,n+1)ans=max(ans,f[i]);
	printf("%lld\n",ans);
	return 0;
}