#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5,MOD=1000000007;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int t,n,k,inv[N],fac[N],invfac[N],tot=1;
void init(int n)
{
	F(i,tot+1,n+1)
	{
		fac[i]=fac[i-1]*(long long)i%MOD;
		inv[i]=MOD/i*(long long)(MOD-inv[MOD%i])%MOD;
		invfac[i]=invfac[i-1]*(long long)inv[i]%MOD;
	}
	tot=n;
}
int main()
{
	read(t);
	inv[1]=1;fac[0]=fac[1]=invfac[0]=invfac[1]=1;
	while(t--)
	{
		long long ans=0,tmp;
		read(n);read(k);
		init(2*n);
		F(i,0,(n-1)/k+2)
		{
			tmp=fac[n-i];
			(tmp*=invfac[n])%=MOD;
			(tmp*=invfac[n-k*i+k-1])%=MOD;
			(tmp*=fac[n-k*i+k+i-1])%=MOD;
			ans+=tmp;
		}
		ans%=MOD;
		printf("%lld\n",ans);
	}
	return 0;
}