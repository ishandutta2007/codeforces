#include<cstdio>
#include<algorithm>
#include<functional>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=5005,MOD=998244353;
template<typename T>T& read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
	return x;
}
int n,a[N],f[N][N],iv[N];
inline int pow(int aa,int b)
{
	long long a=aa,c=1;
	while(b)
	{
		if(b&1)(c*=a)%=MOD;
		b>>=1;(a*=a)%=MOD;
	}
	return c;
}
inline int inv(int a){return pow(a,MOD-2);}
int main()
{
	F(i,0,N)iv[i]=inv(i);
	F(i,0,read(n))read(a[i]);
	sort(a,a+n,greater<int>());
	for(int l=0,r=0;l<n;l=r)
	{
		while(a[l]==a[r])++r;
		int c=r-l;
		F(i,0,n-r+1)f[r][i]=((((c-1ll)*iv[n-i-1]+f[l][i+1])%MOD*c)%MOD*iv[n-i]+f[l][i])%MOD;
	}
	printf("%d\n",f[n][0]);
	return 0;
}