#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=255,MOD=1000000007;
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
int n,k,c[N][N];
long long ans;
int main()
{
	F(i,0,N)c[i][0]=1;
	F(i,1,N)F(j,1,i+1)c[i][j]=(c[i-1][j]+c[i-1][j-1])%MOD;
	read(n,k);
	F(i,0,n+1)F(j,0,n+1)
	{
		int l=(n-i)*(n-j);
		long long d=c[n][i];
		(d*=c[n][j])%=MOD;
		if((i^j)&1)d=MOD-d;
		ans+=d*pow(k,l)%MOD*pow(k-1,n*n-l)%MOD;
	}
	printf("%lld\n",ans%MOD);
	return 0;
}