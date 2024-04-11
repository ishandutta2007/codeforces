// LUOGU_RID: 90576684
#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
typedef unsigned ui;
typedef unsigned long long ull;
constexpr int N=5005;
constexpr ui MOD=1000000007;
ull pow(ull a,ui b)
{
	ull c=1;
	for(;b;b>>=1,(a*=a)%=MOD)if(b&1)(c*=a)%=MOD;
	return c;
}
int n,k;ui f[N];
ull prod=1;
int main()
{
	read(n,k);
	f[0]=1;
	F(i,0,n)
	{
		ull a;(prod*=read(a))%=MOD;
		for(int j=min(i,k);~j;--j)
			f[j+1]-=f[j],f[j+1]+=(int)f[j+1]>>31&MOD,f[j]=(ui)(f[j]*a%MOD);
	}
	ull ans=0,p=1,kk=k;
	F(i,0,min(n,k)+1)ans=(ans+f[i]*p%MOD*pow(n,k-i))%MOD,p=p*(kk--)%MOD;
	ans=ans*pow(n,MOD-1-k)%MOD;
	ans=prod-ans;
	ans+=(int)ans>>31&MOD;
	printf("%llu\n",ans);
	return 0;
}