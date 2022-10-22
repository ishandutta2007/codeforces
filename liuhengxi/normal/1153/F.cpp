#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2005,MOD=998244353;
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
int pow(int aa,int b)
{
	long long a=aa,c=1;
	for(;b;b>>=1,(a*=a)%=MOD)if(b&1)(c*=a)%=MOD;
	return (int)c;
}
inline void reduce(int &x){(x>=MOD)&&(x-=MOD);}
int n,k,l,f[N<<1][N],fac[N];
int main()
{
	read(n,k,l);
	F(i,fac[0]=1,n+1)fac[i]=(int)((fac[i-1]*(long long)i)%MOD);
	f[0][0]=1;
	int ans=0;
	F(i,0,2*n)
	{
		F(j,0,min(i,2*n-i)+1)
		{
			reduce(f[i+1][j+1]+=f[i][j]);
			if(j)f[i+1][j-1]=(int)((f[i+1][j-1]+f[i][j]*(long long)j)%MOD);
		}
	}
	F(i,0,2*n)
	{
		F(j,k,min(i,2*n-i)+1)
			ans=(int)((ans+(long long)f[i][j]*f[2*n-i][j]%MOD*fac[j])%MOD);
	}
	ans=(int)((long long)ans*pow(f[2*n][0],MOD-2)%MOD*pow(2*n+1,MOD-2)%MOD*l%MOD);
	printf("%d\n",ans);
	return 0;
}