#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,m,a[N/2],b[N/2],x[N],y[N],id[N],c[N];
long long ans;
void add(int x){for(++x;x<=m;x+=(x&-x))++c[x];}
int sum(int x)
{
	int ans=0;
	for(;x;x-=(x&-x))ans+=c[x];
	return ans;
}
int main()
{
	read(n);
	F(i,0,n)read(a[i]),read(b[i]),x[2*i]=a[i],x[2*i+1]=b[i];
	sort(x,x+2*n);
	m=unique(x,x+2*n)-x;
	F(i,0,m)y[i]=x[id[i]=i];
	F(i,0,n)
	{
		int u,v;
		u=lower_bound(x,x+m,a[i])-x,v=lower_bound(x,x+m,b[i])-x;
		y[u]^=y[v]^=y[u]^=y[v];id[u]^=id[v]^=id[u]^=id[v];
	}
	F(i,0,m)
	{
		int tmp=(x[i]-i)-(y[i]-id[i]);
		ans+=tmp>0?tmp:-tmp;
	}
	for(int i=m-1;~i;--i)
	{
		ans+=sum(id[i]);
		add(id[i]);
	}
	printf("%lld\n",ans);
	return 0;
}