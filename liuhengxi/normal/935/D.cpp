#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5,MOD=1000000007;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,m,c[N],d[N];
long long ans,invm,inv2=500000004;
int pow(int aa,int b)
{
	long long a=aa,c=1;
	while(b)
	{
		if(b&1)(c*=a)%=MOD;
		b>>=1;(a*=a)%=MOD;
	}
	return (int)c;
}
int main()
{
	read(n);read(m);
	invm=pow(m,MOD-2);
	F(i,0,n)read(c[n-i-1]);
	F(i,0,n)read(d[n-i-1]);
	F(i,0,n)
	{
		int a=c[i],b=d[i];
		if(a&&b)
		{
			if(a>b)ans=1;
			if(a<b)ans=0;
		}
		else if(a||b)
		{
			if(a)ans=(ans*invm+(a-1)*invm)%MOD;
			else ans=(ans*invm+(m-b)*invm)%MOD;
		}
		else ans=(ans*invm+(m-1)*invm%MOD*inv2)%MOD;
	}
	printf("%lld\n",ans);
	return 0;
}