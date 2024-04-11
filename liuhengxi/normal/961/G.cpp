#include<cstdio>//
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
int n,k,w,ans,tmp,f[N];
inline int inv(int a);
int pow(int a,int b)
{
	int c=1;
	if(b<0)b=-b,a=inv(a);
	while(b)
	{
		if(b&1)c=(long long)c*a%MOD;
		a=(long long)a*a%MOD;
		b>>=1;
	}
	return c;
}
inline int inv(int a)
{
	return pow(a,MOD-2);
}
int main()
{
	read(n);read(k);
	F(i,0,n)
	{
		int w1;read(w1);
		w+=w1;w%=MOD;
	}
	f[0]=1;
	F(i,1,k)f[i]=(long long)f[i-1]*i%MOD;
	F(i,0,k)
	{
		tmp=(i&1)?-w:w;
		tmp=(long long)tmp*inv((long long)f[i]*f[k-1-i]%MOD)%MOD;
		tmp=(long long)tmp*pow(k-i,n-2)%MOD;
		tmp=(long long)tmp*(n-1+k-i)%MOD;
		ans+=tmp;ans%=MOD;
	}
	ans+=MOD;ans%=MOD;
	printf("%d\n",ans);
	return 0;
}