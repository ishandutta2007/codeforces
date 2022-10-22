#include<cstdio>
#include<cmath>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const double PI=2.0*asin(1.0);
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int t,n;
int main()
{
	read(t);
	while(t--)
	{
		read(n);
		printf("%0.8lf\n",cos(PI/(4.0*n))/sin(PI/(2.0*n)));
	}
	return 0;
}