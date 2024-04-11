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
long long x,y;
int main()
{
	read(x);read(y);
	if(x<y)puts("-1");
	else
	{
		long long k1=(x-y)/(2*y),k2=(x+y)/(2*y);
		double ans=(x+y)/2.0/k2;
		if(k1&&(x-y)/2.0/k1<ans)ans=(x-y)/2.0/k1;
		printf("%.12lf\n",ans);
	}
	return 0;
}