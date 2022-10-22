#include<cstdio>
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
int n,m,x[N],y[N],dis,ans;
long long xa,xb,ya,yb,f[N];
bool check(long long v)
{
	xa=x[0]-v;xb=x[0]+v;ya=y[0]-v;yb=y[0]+v;
	F(i,1,n)
	{
		if(x[i]-v>xa)xa=x[i]-v;
		if(y[i]-v>ya)ya=y[i]-v;
		if(x[i]+v<xb)xb=x[i]+v;
		if(y[i]+v<yb)yb=y[i]+v;
	}
	return xa<=xb&&ya<=yb;
}
int solve()
{
	int l=-1,r=2.1e9,mid;
	while(r-l>1)
	{
		mid=l+((r-l)>>1);
		if(check(mid))r=mid;
		else l=mid;
	}
	return r;
}
int main()
{
	read(n);read(m);
	read(n);
	F(i,0,n)read(x[i]),read(y[i]),x[i]-=y[i],(y[i]*=2)+=x[i];
	check(dis=solve());
	read(m);
	F(i,0,m)
	{
		long long tmp=0;
		read(x[i]);read(y[i]);x[i]-=y[i],(y[i]*=2)+=x[i];
		if(x[i]<xa)tmp=tmp>xa-x[i]?tmp:xa-x[i];
		if(x[i]>xb)tmp=tmp>x[i]-xb?tmp:x[i]-xb;
		if(y[i]<ya)tmp=tmp>ya-y[i]?tmp:ya-y[i];
		if(y[i]>yb)tmp=tmp>y[i]-yb?tmp:y[i]-yb;
		f[i]=dis+tmp;
	}
	F(i,0,m)if(f[i]<f[ans])ans=i;
	printf("%lld\n%d\n",f[ans],ans+1);
	return 0;
}