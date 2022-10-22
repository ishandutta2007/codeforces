#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
typedef long long ll;
const int N=1e6+5,MOD=1000000007;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,k,pri[N],cnt,kpow[N],sum[N],pre[N],suf[N],ans,fac[N],invfac[N];
bool vis[N];
int pow(int aa,int b)
{
	ll a=aa,c=1;
	while(b)
	{
		if(b&1)(c*=a)%=MOD;
		(a*=a)%=MOD;b>>=1;
	}
	return (int)c;
}
inline void init()
{
	kpow[0]=0;kpow[1]=1;
	F(i,2,k+1)
	{
		if(!vis[i])pri[cnt++]=i,kpow[i]=pow(i,k);
		F(j,0,cnt)
		{
			int x=i*pri[j];
			if(x>=k)break;
			kpow[x]=kpow[i]*(ll)kpow[pri[j]]%MOD;
			vis[x]=true;
			if(i%pri[j]==0)break;
		}
	}
	F(i,0,k+1)sum[i+1]=(sum[i]+kpow[i])%MOD;
}
int main()
{
	read(n);read(k);++n;
	if(k==0)return printf("%d\n",n-1),0;
	init();
	if(n<k+2)return printf("%d\n",sum[n]),0;
	pre[0]=suf[k+=2]=1;
	F(i,0,k)pre[i+1]=pre[i]*(ll)(n-i)%MOD;
	for(int i=k-1;~i;--i)suf[i]=suf[i+1]*(ll)(n-i)%MOD;
	fac[0]=1;
	F(i,1,k)fac[i]=fac[i-1]*(ll)i%MOD;
	invfac[k-1]=pow(fac[k-1],MOD-2);
	for(int i=k-1;i;--i)invfac[i-1]=invfac[i]*(ll)i%MOD;
	F(i,0,k)
	{
		if((k^i)&1)(ans+=(ll)pre[i]*suf[i+1]%MOD*invfac[i]%MOD*invfac[k-1-i]%MOD*sum[i]%MOD)%=MOD;
		else (ans+=MOD-(ll)pre[i]*suf[i+1]%MOD*invfac[i]%MOD*invfac[k-1-i]%MOD*sum[i]%MOD)%=MOD;
	}
	printf("%d\n",ans);
	return 0;
}