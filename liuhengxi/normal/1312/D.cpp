#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int MOD=998244353;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,m,ans;
int pow(int aa,int b)
{
	long long a=aa,c=1;
	while(b)
	{
		if(b&1)(c*=a)%=MOD;
		(a*=a)%=MOD;b>>=1;
	}
	return (int)c;
}
int inv(int a){return pow(a,MOD-2);}
long long f(int x){return x==0?1:f(x-1)*x%MOD;}
int main()
{
	read(n);read(m);
	if(n==2)return puts("0"),0;
	ans=(n-2ll)*pow(2,n-3)%MOD;
	ans=ans*f(m)%MOD;
	ans=ans*(long long)inv(f(n-1)*f(m-n+1)%MOD)%MOD;
	printf("%d\n",ans);
	return 0;
}