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
int n,a[N],f[N]={1},m,ans;
inline int pow(int a1,int b)
{
	long long a=a1,c=1;
	while(b)
	{
		if(b&1)c*=a,c%=MOD;
		a*=a,a%=MOD;b>>=1;
	}
	return (int)c;
}
inline int inv(int a){return pow(a,MOD-2);}
int main()
{
	read(n);
	F(i,0,n)read(a[i]);
	if(n==1)return printf("%d\n",a[0]),0;
	m=(n>>1)-1;
	F(i,1,m+1)f[i]=(long long)f[i-1]*i%MOD;
	if(((long long)n*(n-1))&2)
	{
		if(n&1)F(i,0,--n)if(i&1)a[i]-=a[i+1];else a[i]+=a[i+1];
		F(i,0,n)a[i]%=MOD;
		F(i,0,n>>1)
		{
			long long b=a[i<<1]+a[(i<<1)+1];
			ans+=b*f[m]%MOD*inv((long long)f[i]*f[m-i]%MOD)%MOD;
			ans%=MOD;
		}
	}
	else
	{
		if(n&1)F(i,0,--n)if(i&1)a[i]-=a[i+1];else a[i]+=a[i+1];
		F(i,0,n)a[i]%=MOD;
		F(i,0,n>>1)
		{
			long long b=a[i<<1]-a[(i<<1)+1];
			ans+=b*f[m]%MOD*inv((long long)f[i]*f[m-i]%MOD)%MOD;
			ans%=MOD;
		}
	}
	ans+=MOD;ans%=MOD;
	printf("%d\n",ans);
	return 0;
}