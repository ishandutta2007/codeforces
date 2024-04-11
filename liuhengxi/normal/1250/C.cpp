#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,m,k;
long long ans=-1;
int main()
{
	read(n);read(m);read(k);
	k+=2;
	for(int l=1,r=0;l<=n&&l<k;l=r+1)
	{
		r=n/(n/l);
		if(k-r>m)continue;
		int x=k-r;
		if(x<1)x=1;
		long long t=(long long)(n/l)*(m/x);
		if(t>ans)ans=t;
	}
	printf("%lld\n",ans);
	return 0;
}