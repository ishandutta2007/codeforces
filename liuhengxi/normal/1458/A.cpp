#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5;
const long long LLINF=0x3fffffffffffffffll;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,m;
long long a[N],b[N],mina=LLINF,gcda;
long long gcd(long long a,long long b){return b?gcd(b,a%b):a;}
int main()
{
	read(n);read(m);
	F(i,0,n)read(a[i]);
	F(i,0,m)read(b[i]);
	F(i,0,n)if(a[i]<mina)mina=a[i];
	gcda=a[0]-mina;
	F(i,1,n)gcda=gcd(gcda,a[i]-mina);
	F(i,0,m)
	{
		long long t=a[0]+b[i],ans;
		ans=gcd(t,gcda);
		printf("%lld ",ans);
	}
	printf("\n");
	return 0;
}