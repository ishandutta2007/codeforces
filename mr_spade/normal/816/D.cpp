#include<cstdio>
#define int long long
namespace fastIO
{
	inline int read()
	{
		int sum(0);
		char x;
		while((x=getchar())<'0'||x>'9');
		for(;x>='0'&&x<='9';x=getchar())
			sum=(sum<<3)+(sum<<1)+x-'0';
		return sum;
	}
	inline void write(int x)
	{
		if(x>=10)
			write(x/10);
		putchar(x%10+'0');
		return;
	}
}
using namespace fastIO;
const int N=2e6,mod=1e9+7;
int n,a[N],fact[N]={1},ans;
inline int pow(int a,int b,int mod)
{
	int mi(1);
	for(;b;a=(a*a)%mod,b>>=1)
		if(b&1)
			mi=(mi*a)%mod;
	return mi;
}
inline void f(int x)
{
	for(int i=1;i<=x;i++)
		fact[i]=fact[i-1]*i%mod;
	return;
}
inline int C(int n,int k)
{
	return fact[n]*pow(fact[k],mod-2,mod)%mod*pow(fact[n-k],mod-2,mod)%mod;
}
signed main()
{
	int i,j;
	n=read();
	for(i=1;i<=n;i++)
		a[i]=read();
	switch(n%4)
	{
		case 0:
			f((n>>1)-1);
			for(i=0;i<=(n>>1)-1;i++)
				ans=(ans+C((n>>1)-1,i)*((a[i<<1|1]-a[(i<<1)+2])%mod+mod)%mod)%mod;
			break;
		case 1:
			f((n-1)>>1);
			for(i=0;i<=(n-1)>>1;i++)
				ans=(ans+C((n-1)>>1,i)*a[i<<1|1]%mod)%mod;
			break;
		case 2:
			f((n>>1)-1);
			for(i=0;i<=(n>>1)-1;i++)
				ans=(ans+C((n>>1)-1,i)*(a[i<<1|1]+a[(i<<1)+2])%mod)%mod;
			break;
		case 3:
			f((n-3)>>1);
			for(i=0;i<=(n-3)>>1;i++)
				ans=(ans+C((n-3)>>1,i)*((a[i<<1|1]+(a[(i<<1)+2]<<1)-a[(i<<1)+3])+mod)%mod)%mod;
			break;
	}
	write(ans);
	putchar('\n');
	return 0;
}