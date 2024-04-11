#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=3e6+5,MOD=1000000007;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,f[N],q,fac[N],invfac[N];
int pow(int aa,int b)
{
	long long a=aa,c=1;
	while(b)
	{
		if(b&1)(c*=a)%=MOD;
		b>>=1;(a*=a)%=MOD;
	}
	return c;
}
int main()
{
	read(n);
	fac[0]=1;
	F(i,1,3*n+4)fac[i]=fac[i-1]*(long long)i%MOD;
	invfac[3*n+3]=pow(fac[3*n+3],MOD-2);
	for(int i=3*n+3;i;--i)invfac[i-1]=invfac[i]*(long long)i%MOD;
	F(i,0,3*n+4)f[i]=(long long)fac[3*n+3]*invfac[i]%MOD*invfac[3*n+3-i]%MOD;
	f[0]=(f[0]+MOD-1)%MOD;
	f[1]=(f[1]+MOD-3)%MOD;
	f[2]=(f[2]+MOD-3)%MOD;
	f[3]=(f[3]+MOD-1)%MOD;
	for(int i=3*n+3;i>=2;--i)
	{
		int t=(MOD-3ll*f[i]%MOD)%MOD;
		(f[i-1]+=t)%=MOD;
		(f[i-2]+=t)%=MOD;
	}
	read(q);
	while(q--)
	{
		int x;read(x);
		printf("%d\n",f[x+3]);
	}
	return 0;
}