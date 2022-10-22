#include<cstdio>
#ifdef TEST_TIME
#include<ctime>
#endif
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e7+5,MOD=998244353;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
int n,m,k,fac[N],invfac[N];
long long ans;
int pow(int aa,int b)
{
	long long a=aa,c=1;
	for(;b;b>>=1,(a*=a)%=MOD)if(b&1)(c*=a)%=MOD;
	return (int)c;
}
inline int C(int a,int b){return (int)((long long)fac[a]*invfac[b]%MOD*invfac[a-b]%MOD);}
inline int distrib(int cnt,int sum){return C(sum+cnt-1,sum);}
int calc(int cnt,int sum,int lim)
{
	long long res=0;
	if(sum/lim>cnt)return 0;
	if(cnt==0)return sum==0;
	F(exceed,0,sum/lim+1)
		res+=(exceed&1?MOD-1ll:1ll)*C(cnt,exceed)%MOD*distrib(cnt,sum-exceed*lim)%MOD;
	return (int)(res%MOD);
}
int main()
{
	F(i,fac[0]=1,N)fac[i]=(int)(fac[i-1]*(long long)i%MOD);
	invfac[N-1]=pow(fac[N-1],MOD-2);
	for(int i=N;--i;)invfac[i-1]=(int)(invfac[i]*(long long)i%MOD);
	read(n,m,k);
	if(k==0)return printf("%d\n",pow(n,MOD-2)),0;
	F(same,1,n+1)
	{
		long long delta=0;
		F(i,k,m/same+1)delta+=calc(n-same,m-i*same,i);
		ans+=delta%MOD*pow(same,MOD-2)%MOD*C(n-1,same-1)%MOD;
	}
	ans=ans%MOD*pow(distrib(n,m-k),MOD-2)%MOD;
	printf("%lld\n",ans);
	return 0;
}