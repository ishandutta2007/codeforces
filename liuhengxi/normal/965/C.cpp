#include<cstdio>
#include<algorithm>
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
long long n,k,m,d,ans;
int main()
{
	read(n);read(k);read(m);read(d);
	F(i,1,d+1)
	{
		if(i>(n-1)/k+1)break;
		ans=max(ans,min(m,n/(k*(i-1)+1))*i);
	}
	printf("%lld\n",ans);
	return 0;
}