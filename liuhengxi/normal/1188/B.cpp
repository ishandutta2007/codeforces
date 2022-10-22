#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=3e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,p,k,a[N];long long ans;
int main()
{
	read(n);read(p);read(k);
	F(i,0,n)
	{
		long long x,y,z;
		read(x);y=x;(y*=y)%=p;(y*=y)%=p;z=k*x%p;
		a[i]=(y+p-z)%p;
	}
	sort(a,a+n);
	for(int l=0,r=0;l<n;l=r)
	{
		while(r<n&&a[r]==a[l])++r;
		ans+=(r-l)*(long long)(r-l-1)>>1;
	}
	printf("%lld\n",ans);
	return 0;
}