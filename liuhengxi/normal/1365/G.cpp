#include<cstdio>
#ifdef LOCAL
#define TEST
#endif
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
constexpr int N=2005;
int n,mask[N];
long long b[20],p[N];
#ifdef TEST
long long a[N];
#endif
int main()
{
	read(n);
#ifdef TEST
	F(i,0,n)read(a[i]);
#endif
	for(int i=0,j=0;i<n;++i,++j)
	{
		while(__builtin_popcount(j)!=6)++j;
		mask[i]=j;
	}
	F(i,0,13)
	{
		int c=0;
		F(j,0,n)if(mask[j]>>i&1)++c;
		if(c)
		{
#ifdef TEST
			F(j,0,n)if(mask[j]>>i&1)b[i]|=a[j];
#else
			printf("? %d ",c);
			F(j,0,n)if(mask[j]>>i&1)printf("%d ",j+1);
			puts("");
			fflush(stdout);
			scanf("%lld",&b[i]);
#endif
		}
	}
	F(i,0,n)F(j,0,13)if(!(mask[i]>>j&1))p[i]|=b[j];
	printf("! ");
	F(i,0,n)printf("%lld ",p[i]);
	puts("");
	return 0;
}