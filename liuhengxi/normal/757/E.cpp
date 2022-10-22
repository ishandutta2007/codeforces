#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e6+5,MOD=1000000007;
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
inline void reduce(int &x){(x>=MOD)&&(x-=MOD);}
struct sieve
{
	static const int N=1e6+5;
	int p[N/4],t,mpf[N];
	bool c[N];
	sieve()
	{
		c[0]=c[1]=true;
		F(i,2,N)
		{
			if(!c[i])p[t++]=i,mpf[i]=i;
			F(j,0,t)
			{
				int x=i*p[j];
				if(x>=N)break;
				c[x]=true;mpf[x]=p[j];
				if(i%p[j]==0)break;
			}
		}
	}
}sieve;
struct dp
{
	static const int K=22,n=1000000,k=20;
	int f[N][K];
	dp()
	{
		f[0][0]=1;
		F(i,1,k+1)f[0][i]=2;
		F(i,1,n+1)
		{
			f[i][0]=f[i-1][0];
			F(j,1,k+1)reduce(f[i][j]=f[i-1][j]+f[i][j-1]);
		}
	}
}dp;
auto mpf=sieve.mpf;
auto f=dp.f;
int q,n,r;
int main()
{
	for(read(q);q--;)
	{
		int ans=1;
		read(r,n);
		while(n!=1)
		{
			int t=0,p=mpf[n];
			while(n%p==0)n/=p,++t;
			ans=int((long long)ans*f[r][t]%MOD);
		}
		printf("%d\n",ans);
	}
	return 0;
}