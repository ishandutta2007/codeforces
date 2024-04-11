#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define lc (p<<1)
#define rc ((p<<1)|1)
using namespace std;
const int N=5e5+5,M=1e6+5;
const long long LLINF=0x3fffffffffff;
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
int n,x[N],y[N],c[N],v[N<<1],m,id[N],ind[N<<3],xy1=2000000000,xy2=xy1;
long long mx[N<<3],tg[N<<3],ans;
bool cmp(int u,int v){return x[u]>x[v];}
inline void update(int p,long long v){mx[p]+=v;tg[p]+=v;}
inline void pushdown(int p){update(lc,tg[p]);update(rc,tg[p]);tg[p]=0;}
void build(int p,int l,int r)
{
	int mid=(l+r)>>1;
	ind[p]=l;
	if(r-l==1)return;
	build(lc,l,mid);build(rc,mid,r);
}
void update(int p,int l,int r,int x,int y,long long v)
{
	int mid=(l+r)>>1;
	if(y<=l||r<=x)return;
	if(x<=l&&r<=y)return update(p,v);
	pushdown(p);
	update(lc,l,mid,x,y,v);update(rc,mid,r,x,y,v);
	if(mx[lc]>mx[rc])mx[p]=mx[lc],ind[p]=ind[lc];else mx[p]=mx[rc],ind[p]=ind[rc];
}
int main()
{
	F(i,0,read(n))
	{
		read(x[i],y[i],c[i]);
		if(x[i]>y[i])swap(x[i],y[i]);
		v[i<<1]=x[i];v[i<<1|1]=y[i];
		id[i]=i;
	}
	sort(id,id+n,cmp);
	sort(v,v+(n<<1));m=unique(v,v+(n<<1))-v;
	build(1,0,m);update(1,0,m,0,m,-LLINF);
	F(i,0,n)x[i]=lower_bound(v,v+m,x[i])-v,y[i]=lower_bound(v,v+m,y[i])-v;
	for(int i=m-1,j=0;~i;--i)
	{
		update(1,0,m,i,i+1,LLINF);
		update(1,0,m,i+1,m,v[i]-v[i+1]);
		for(;j<n&&x[id[j]]==i;++j)update(1,0,m,y[id[j]],m,c[id[j]]);
		if(mx[1]>ans)
		{
			ans=mx[1];
			xy1=v[i];
			xy2=v[ind[1]];
		}
	}
	printf("%lld\n%d %d %d %d\n",ans,xy1,xy1,xy2,xy2);
	return 0;
}