#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e6+5,MOD=1000000007;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int q,x,y,f[N]={1},pri[N],pre[N],cnt;
long long inv(long long a)
{
	int b=MOD-2;a%=MOD;
	long long c=1;
	while(b)
	{
		if(b&1)(c*=a)%=MOD;
		(a*=a)%=MOD;
		b>>=1;
	}
	return c;
}
int pow(int aa,int b)
{
	long long a=aa,c=1;
	while(b)
	{
		if(b&1)(c*=a)%=MOD;
		(a*=a)%=MOD;
		b>>=1;
	}
	return (int)c;
}
int C(int n,int m){return f[n]*inv((long long)f[m]*f[n-m])%MOD;}
int main()
{
	F(i,1,2000001)f[i]=f[i-1]*(long long)i%MOD;
	pre[1]=-1;
	F(i,2,1000001)
	{
		if(!pre[i])pre[i]=i,pri[cnt++]=i;
		F(j,0,cnt)
		{
			if(i*pri[j]>1000000)break;
			pre[i*pri[j]]=pri[j];
			if(i%pri[j]==0)break;
		}
	}
	read(q);
	while(q--)
	{
		int ans=1;
		read(x);read(y);
		for(int i=pre[x];~i;i=pre[x])if(x%i==0)
		{
			int t=0;
			while(x%i==0)x/=i,++t;
			ans=(long long)ans*C(y+t-1,t)%MOD;
		}
		if(x!=1)ans=(long long)ans*y%MOD;
		ans=(long long)ans*pow(2,y-1)%MOD;
		printf("%d\n",ans);
	}
	return 0;
}