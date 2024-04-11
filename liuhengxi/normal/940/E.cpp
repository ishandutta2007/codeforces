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
int n,c,a[N],q[N],qf,qr;
long long sum,f[N];
int main()
{
	read(n);read(c);
	F(i,0,n)read(a[i]),sum+=a[i];
	F(i,0,c)
	{
		while(qf<qr&&a[q[qr-1]]>=a[i])--qr;
		q[qr++]=i;
	}
	F(i,c,n+1)
	{
		f[i]=f[i-c]+a[q[qf]];
		if(f[i]<f[i-1])f[i]=f[i-1];
		while(qf<qr&&a[q[qr-1]]>=a[i])--qr;
		q[qr++]=i;
		if(q[qf]==i-c)++qf;
	}
	printf("%lld\n",sum-f[n]);
	return 0;
}