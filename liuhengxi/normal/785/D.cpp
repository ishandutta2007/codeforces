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
int n,fac[2*N],invfac[2*N],left[N],right[N],ans;
char s[N];
inline int pow(int aa,int b)
{
	long long a=aa,c=1;
	while(b)
	{
		if(b&1)(c*=a)%=MOD;
		(a*=a)%=MOD;b>>=1;
	}
	return (int)c;
}
inline int C(int n,int m){return fac[n]*(long long)invfac[m]%MOD*invfac[n-m]%MOD;}
int main()
{
	scanf("%s",s);
	while(s[n])++n;
	F(i,fac[0]=1,2*n+1)fac[i]=fac[i-1]*(long long)i%MOD;
	invfac[2*n]=pow(fac[2*n],MOD-2);
	for(int i=2*n;i;--i)invfac[i-1]=invfac[i]*(long long)i%MOD;
	F(i,0,n)left[i+1]=left[i]+(s[i]=='(');
	for(int i=n-1;~i;--i)right[i]=right[i+1]+(s[i]==')');
	F(i,0,n)if(s[i]=='(')
	{
		int a=left[i],b=right[i];
		if(b)(ans+=C(a+b,b-1))%=MOD;
	}
	printf("%d\n",ans);
	return 0;
}