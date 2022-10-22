#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5;
const long long epsinv=10000000000000ll;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,w,id[N],c[N],d[N],s[N];
long long a[N],b[N],u[N],v[N];
bool cmp(int u,int v){return a[u]!=a[v]?a[u]>a[v]:b[u]<b[v];}
void add(int x)
{
	for(++x;x<=n;x+=(x&-x))++s[x];
}
int sum(int x)
{
	int ans=0;
	for(;x;x-=(x&-x))ans+=s[x];
	return ans;
}
int main()
{
	long long ans=0;
	read(n);read(w);
	F(i,0,n)
	{
		int x,y;read(x);read(y);
		u[i]=a[i]=(-y+w)*epsinv/x;
		v[i]=b[i]=(-y-w)*epsinv/x;
		id[i]=i;
	}
	sort(id,id+n,cmp);
	sort(u,u+n);sort(v,v+n);
	F(i,0,n)
	{
		c[i]=lower_bound(u,u+n,a[id[i]])-u;
		d[i]=lower_bound(v,v+n,b[id[i]])-v;
	}
	F(i,0,n)
	{
		ans+=sum(d[i]+1);
		add(d[i]);
	}
	printf("%lld\n",ans);
	return 0;
}