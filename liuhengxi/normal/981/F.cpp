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
int n,l[2*N],r[2*N];
long long m,a[2*N],bb[4*N],*b=bb+N;
bool check(int d)
{
	int mx=-n;
	for(int i=0,j=-n;i<2*n;++i)
	{
		while(j<3*n&&a[i]-b[j]>d)++j;
		l[i]=j;
	}
	for(int i=0,j=-n;i<2*n;++i)
	{
		while(j<3*n&&b[j]-a[i]<=d)++j;
		r[i]=j;
	}
	F(i,0,2*n)l[i]-=i,r[i]-=i;
	F(i,0,2*n)
	{
		mx=l[i]>mx?l[i]:mx;
		if(mx>=r[i])return false;
	}
	return true;
}
int solve()
{
	int l=-1,r=m/2,mid;
	while(r-l>1)
	{
		mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid;
	}
	return r;
}
int main()
{
	read(n);read(m);
	F(i,0,n)read(a[i]);
	sort(a,a+n);
	F(i,0,n)a[i+n]=a[i]+m;
	F(i,0,n)read(b[i]);
	sort(b,b+n);
	F(i,0,n)b[i-n]=b[i]-m;
	F(i,0,n)b[i+n]=b[i]+m;
	F(i,0,n)b[i+2*n]=b[i]+2*m;
	printf("%d\n",solve());
	return 0;
}