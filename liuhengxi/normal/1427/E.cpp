#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int x,m,y;
long long c,d,a[N],b[N];
char op[N];
long long ADD(long long x,long long y)
{
	a[m]=x;b[m]=y;op[m++]='+';
	return x+y;
}
long long XOR(long long x,long long y)
{
	a[m]=x;b[m]=y;op[m++]='^';
	return x^y;
}
int main()
{
	read(x);
	c=x;
	F(i,0,30)c=ADD(ADD(c,x),XOR(c,x));
	y=ADD(x,x);
	d=y;
	F(i,0,29)d=ADD(ADD(d,y),XOR(d,y));
	int fsb=XOR(c,d);
	F(i,1,25)
	{
		if(x>>i&1)x=XOR(x,fsb);
		if(x==1)break;
		fsb=ADD(fsb,fsb);
	}
	printf("%d\n",m);
	F(i,0,m)printf("%lld %c %lld\n",a[i],op[i],b[i]);
	return 0;
}