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
int n,m;
int main()
{
	read(n);read(m);
	F(i,0,n)
	{
		F(j,0,m)
		{
			int a;read(a);
			printf("%d ",720720+a*a*a*a*((i^j)&1));
		}
		printf("\n");
	}
	return 0;
}