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
int n,a[N];
long long ans;
int main()
{
	read(n);
	F(i,0,n)read(a[i]);
	F(i,0,n)
	{
		int b;
		read(b);a[i]-=b;
	}
	sort(a,a+n);
	for(int i=0,j=n;i<n;++i)
	{
		while(j&&a[i]+a[j-1]>0)--j;
		ans+=n-j;
	}
	F(i,0,n)if(a[i]>0)--ans;
	ans>>=1;
	printf("%lld\n",ans);
	return 0;
}