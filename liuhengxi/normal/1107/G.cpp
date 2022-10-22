#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define lc (p<<1)
#define rc ((p<<1)|1)
using namespace std;
const int N=3e5+5;
const long long LLINF=0x3fffffffffffffffll;
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
struct node
{
	long long sum,lmax,rmax,submax;
	node(long long a=0){sum=a;lmax=rmax=submax=max(a,0ll);}
	node operator+(node b)const
	{
		const node &a=*this;node c;
		c.sum=max(a.sum+b.sum,-LLINF);
		c.lmax=max(a.lmax,a.sum+b.lmax);
		c.rmax=max(b.rmax,b.sum+a.rmax);
		c.submax=max(a.rmax+b.lmax,max(a.submax,b.submax));
		return c;
	}
}s[N<<3];
struct gap
{
	int id;long long sq;
	bool operator<(gap b)const{return sq<b.sq;}
}g[N];
int n,a,d[N],c[N],m;
long long b[N<<1],ans;
void build(int p,int l,int r)
{
	int mid=(l+r)>>1;
	if(r-l==1)return s[p]=node(b[l]),void();
	build(lc,l,mid);build(rc,mid,r);
	s[p]=s[lc]+s[rc];
}
void update(int p,int l,int r,int x,long long v)
{
	int mid=(l+r)>>1;
	if(r-l==1)return s[p]=node(v),void();
	if(x<mid)update(lc,l,mid,x,v);else update(rc,mid,r,x,v);
	s[p]=s[lc]+s[rc];
}
int main()
{
	read(n,a);m=(n<<1)-1;
	F(i,0,n)read(d[i],c[i]),b[i<<1]=a-c[i],b[i<<1|1]=-LLINF;
	build(1,0,m);
	F(i,0,n)g[i].id=i<<1|1,g[i].sq=(d[i+1]-d[i])*(long long)(d[i+1]-d[i]);
	sort(g,g+n-1);
	ans=max(ans,s[1].submax);
	F(i,0,n-1)
	{
		update(1,0,m,g[i].id,0);
		ans=max(ans,s[1].submax-g[i].sq);
	}
	printf("%lld\n",ans);
	return 0;
}