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
int cnt1,cnt2,x,y;
bool check(long long v)
{
	long long a=cnt1-v/y+v/x/y,b=cnt2-v/x+v/x/y;
	if(a<0)a=0;if(b<0)b=0;
	return a+b<=v-v/x-v/y+v/x/y;
}
long long solve()
{
	long long l=1,r=4e9,mid;
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
	read(cnt1);read(cnt2);read(x);read(y);
	printf("%lld\n",solve());
	return 0;
}