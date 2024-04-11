#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int MOD=1000000007;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,a=1,b=1;
int main()
{
	read(n);
	F(i,1,n+1)a=(long long)a*i%MOD;
	F(i,0,n-1)b=(b+b)%MOD;
	a=(a-b+MOD)%MOD;
	printf("%d\n",a);
	return 0;
}