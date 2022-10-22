#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=5005;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,x,y,l,r;
long long ans;
int main()
{
	read(n);read(x);y=x;
	F(i,0,n)
	{
		read(l);read(r);
		if(r<x)ans+=x-r,y=x,x=r;
		else if(y<l)ans+=l-y,x=y,y=l;
		else x=x>l?x:l,y=y<r?y:r;
	}
	printf("%lld\n",ans);
	return 0;
}