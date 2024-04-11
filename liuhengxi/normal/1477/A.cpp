#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int T,n;
long long k,a[N];
long long gcd(long long a,long long b)
{return !b?a:gcd(b,a%b);}
int main()
{
	read(T);
	while(T--)
	{
		long long g=0;
		read(n);read(k);
		F(i,0,n)read(a[i]);
		F(i,1,n)a[i]-=a[0];
		k-=a[0];a[0]=0;
		F(i,1,n)g=gcd(a[i],g);
		if(k%g)puts("NO");
		else puts("YES");
	}
	return 0;
}