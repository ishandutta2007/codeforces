#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e6+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,a[N];
long long f[N],g[N],h[N];
int main()
{
	read(n);
	F(i,0,n)read(a[i]);
	g[1]=-a[0];h[1]=a[0];
	F(i,1,n+1)
	{
		f[i]=max(g[i]+a[i-1],h[i]-a[i-1]);
		g[i+1]=max(g[i],f[i]-a[i]);
		h[i+1]=max(h[i],f[i]+a[i]);
	}
	printf("%lld\n",f[n]);
	return 0;
}