#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
long long cost(int x,int c)
{
	int r=x%c,y=x/c;
	return (c-r)*y*(long long)y+r*(y+1ll)*(y+1ll);
}
long long costd(int x,long long d)
{
	int l=1,r=x+1,mid;
	while(r-l>1)
	{
		mid=(l+r)>>1;
		if(cost(x,mid-1)-cost(x,mid)>=d)l=mid;
		else r=mid;
	}
	return cost(x,l);
}
int inst(int x,long long d)
{
	int l=1,r=x+1,mid;
	while(r-l>1)
	{
		mid=(l+r)>>1;
		if(cost(x,mid-1)-cost(x,mid)>=d)l=mid;
		else r=mid;
	}
	return l-1;
}
int n,a[N];
long long m;
bool check(long long d)
{
	long long tot=0;
	F(i,0,n)tot+=costd(a[i],d);
	return tot<=m;
}
long long solve()
{
	long long l=0,r=1ll<<60,mid;
	while(r-l>1)
	{
		mid=(l+r)>>1;
		if(check(mid))l=mid;
		else r=mid;
	}
	return l;
}
int main()
{
	long long d,ans=0;
	read(n);
	F(i,0,n)read(a[i+1]);
	F(i,0,n)a[i]=a[i+1]-a[i];
	read(m);
	d=solve();
	++d;
	F(i,0,n)ans+=inst(a[i],d),m-=costd(a[i],d);
	--d;
	ans+=(d-1-m)/d;
	printf("%lld\n",ans);
	return 0;
}