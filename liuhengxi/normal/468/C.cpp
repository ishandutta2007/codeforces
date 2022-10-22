#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
typedef unsigned long long ull;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
ull n,offset;
ull mul(ull a,ull b,ull p=n)
{
	ull c=0;
	while(b)
	{
		if(b&1)(c+=a)%=p;
		b>>=1;(a<<=1)%=p;
	}
	return c;
}
int main()
{
	read(n);
	offset=(n<<1)-mul(19*45,1000000000000000000ull%n);
	printf("%llu 1%019llu\n",offset,offset-1);
	return 0;
}