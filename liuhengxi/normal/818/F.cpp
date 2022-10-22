#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define sum(x) ((x)*((x)+1)/2)
using namespace std;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int q,n;
long long ans;
int solve()
{
	int l=0,r=n,mid;
	while(r-l>1)
	{
		mid=(l+r)>>1;
		if(n-1-mid>=sum((long long)mid))l=mid;
		else r=mid;
	}
	return l;
}
int main()
{
	read(q);
	while(q--)
	{
		read(n);
		ans=n-1;
		int i=solve();
		long long j=sum((long long)i);
		if(n-1-i+j>ans)ans=n-1-i+j;
		j+=++i;
		if(2ll*(n-1-i)>ans)ans=2ll*(n-1-i);
		printf("%lld\n",ans);
	}
	return 0;
}