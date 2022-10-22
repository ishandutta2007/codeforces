#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=105;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,a[N],mn=0;
int main()
{
	read(n);
	F(i,-n+1,0)
	{
		int x;
		printf("? ");
		F(j,0,n-1)printf("1 ");
		printf("%d\n",1-i);
		fflush(stdout);
		read(x);
		if(x)a[--x]=-i;
	}
	F(i,1,n)
	{
		int x;
		printf("? ");
		F(j,0,n-1)printf("%d ",i+1);
		printf("1\n");
		fflush(stdout);
		read(x);
		if(x)a[--x]=-i;
	}
	F(i,0,n)if(a[i]<mn)mn=a[i];
	F(i,0,n)a[i]+=-mn;
	printf("! ");
	F(i,0,n)printf("%d ",a[i]+1);
	puts("");
	return 0;
}