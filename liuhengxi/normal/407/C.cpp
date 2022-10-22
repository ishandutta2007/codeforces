#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5,K=105,MOD=1000000007;
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
struct com
{
	const static int N=2e5+5;
	int fac[N],invfac[N];
	com()
	{
		F(i,fac[0]=1,N)fac[i]=int((long long)fac[i-1]*i%MOD);
		invfac[N-1]=pow(fac[N-1],MOD-2);
		for(int i=N-1;i;--i)invfac[i-1]=int((long long)invfac[i]*i%MOD);
	}
	int C(int n,int m){return int((long long)fac[n]*invfac[m]%MOD*invfac[n-m]%MOD);}
}com;
int n,m,c[N],a[N][K];
int main()
{
	read(n,m);
	F(i,0,n)read(c[i]);
	while(m--)
	{
		int l,r,k;read(l,r,k);--l;
		reduce(a[l][k]+=1);
		F(i,0,k+1)reduce(a[r][i]+=MOD-com.C(k-i+r-l-1,k-i));
	}
	for(int j=100;~j;--j)reduce(a[0][j]+=a[0][j+1]);
	F(i,1,n)for(int j=100;~j;--j)reduce(a[i][j]+=a[i][j+1]),reduce(a[i][j]+=a[i-1][j]);
	F(i,0,n)printf("%d ",(a[i][0]+c[i])%MOD);
	puts("");
	return 0;
}