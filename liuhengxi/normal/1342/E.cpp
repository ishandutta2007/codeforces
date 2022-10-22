#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5,MOD=998244353;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,fac[N]={1},invfac[N],f[N];
long long k;
int pow(int aa,int b)
{
	long long c=1,a=aa;
	while(b)
	{
		if(b&1)(c*=a)%=MOD;
		b>>=1;(a*=a)%=MOD;
	}
	return (int)c;
}
inline int C(int n,int m){return fac[n]*(long long)invfac[m]%MOD*invfac[n-m]%MOD;}
int main()
{
	F(i,1,N)fac[i]=fac[i-1]*(long long)i%MOD;
	invfac[N-1]=pow(fac[N-1],MOD-2);
	for(int i=N-1;i;--i)invfac[i-1]=invfac[i]*(long long)i%MOD;
	read(n);read(k);
	if(k>=n)puts("0");
	else if(k==0)printf("%d\n",fac[n]);
	else
	{
		int ans=0;k=n-k;
		F(i,1,k+1)(ans+=(1ll-(((k^i)&1)<<1)+MOD)*C(k,i)%MOD*pow(i,n)%MOD)%=MOD;
		printf("%lld\n",C(n,k)*2ll*ans%MOD);
	}
	return 0;
}