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
int n,k,a[N],s[N],f[N];
char str[N];
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
inline int inv(int a){return pow(a,MOD-2);}
void init()
{
	f[0]=1;
	F(i,1,N)f[i]=f[i-1]*(long long)i%MOD;
}
int binom(int n,int m)
{
	if(m>n)return 0;
	return f[n]*(long long)inv(f[m]*(long long)f[n-m]%MOD)%MOD;
}
int main()
{
	int ans=0;
	long long t=1;
	init();
	read(n);read(k);
	gets(str);
	F(i,0,n)a[i]=str[i]-'0';
	F(i,0,n)s[i+1]=s[i]+a[i];
	if(k==0)
	{
		F(i,0,n)ans=(ans*10ll+a[i])%MOD;
		printf("%d\n",ans);
		return 0;
	}
	F(i,0,n-1)
	{
		(ans+=binom(n-i-2,k-1)*t%MOD*s[n-i-1]%MOD)%=MOD;
		(t*=10)%=MOD;
	}
	t=1;
	for(int i=n-1;~i;--i)
	{
		(ans+=a[i]*t%MOD*binom(i,k)%MOD)%=MOD;
		(t*=10)%=MOD;
	}
	printf("%d\n",ans);
	return 0;
}