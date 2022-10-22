#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5;
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
int m,n,a[N],mn,mx,c[N],ans[N];
bool check1(int v)
{
	int f=0;
	F(i,0,n)
	{
		f=max(f+v,a[i+1]);
		if(f>a[i+2])return false;
	}
	return f<=m;
}
bool check2(int v)
{
	int f=0;
	F(i,0,n)
	{
		f=min(f+v,a[i+2]);
		if(f<a[i+1])return false;
	}
	return f>=m;
}
int solve1()
{
	int l=0,r=0x3f3f3f3f,mid;
	while(r-l>1)
	{
		mid=(l+r)>>1;
		if(check1(mid))l=mid;
		else r=mid;
	}
	return l;
}
int solve2()
{
	int l=-1,r=0x3f3f3f3f,mid;
	while(r-l>1)
	{
		mid=(l+r)>>1;
		if(check2(mid))r=mid;
		else l=mid;
	}
	return r;
}
int main()
{
	read(m,n);
	F(i,1,n+1)read(a[i]);
	a[n+1]=m;
	mn=solve1();
	mx=solve2();
	F(i,0,n)c[i+1]=min(c[i]+mx,a[i+2]);
	ans[n]=m;
	for(int i=n;~--i;)ans[i]=min(ans[i+1]-mn,c[i]);
	F(i,0,n)printf("%d %d\n",ans[i],ans[i+1]);
	return 0;
}