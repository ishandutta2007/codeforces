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
int n,x[N],v[N],val[N],b[N],id[N];
long long c[N],ans;
int disc(int x)
{
	int l=0,r=n,mid;
	while(r-l>1)
	{
		mid=(l+r)>>1;
		if(x<val[mid])r=mid;
		else l=mid;
	}
	return l;
}
bool cmp(int a,int b){return v[a]!=v[b]?v[a]<v[b]:x[a]<x[b];}
template<typename T>void add(T *a,int x,int y){for(++x;x<=n;x+=x&-x)a[x]+=y;}
template<typename T>T sum(T *a,int x)
{
	T ans=0;
	for(;x;x-=x&-x)ans+=a[x];
	return ans;
}
int main()
{
	read(n);
	F(i,0,n)read(x[i]),val[i]=x[i];
	F(i,0,n)read(v[i]),id[i]=i;
	sort(val,val+n);
	F(i,0,n)x[i]=disc(x[i]);
	sort(id,id+n,cmp);
	F(i,0,n)v[i]=x[id[i]];
	F(i,0,n)x[i]=v[i];
	F(i,0,n)
	{
		ans+=sum(b,x[i])*(long long)val[x[i]]-sum(c,x[i]);
		add(b,x[i],1);
		add(c,x[i],val[x[i]]);
	}
	printf("%lld\n",ans);
	return 0;
}