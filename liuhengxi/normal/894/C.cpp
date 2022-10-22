#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e3+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,a[N];
int main()
{
	read(n);
	F(i,0,n)read(a[i]);
	F(i,0,n)if(a[i]%a[0])return puts("-1"),0;
	printf("%d\n",2*n-1);
	F(i,0,n)
	{
		printf("%d ",a[i]);
		if(i)printf("%d ",a[0]);
	}
	printf("\n");
	return 0;
}