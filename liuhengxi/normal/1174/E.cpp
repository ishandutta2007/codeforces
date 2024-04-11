#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e6+5,MOD=1000000007;
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
int n,d[N],f[N],r[N],fac[N],invfac[N];
int pow(int aa,int b)
{
	long long a=aa,c=1;
	for(;b;b>>=1)(b&1)&&((c*=a)%=MOD),(a*=a)%=MOD;
	return (int)c;
}
int main()
{
	read(n);
	++n;
	F(i,fac[0]=1,n+1)fac[i]=(int)(fac[i-1]*(long long)i%MOD);
	invfac[n]=pow(fac[n],MOD-2);
	for(int i=n;i;--i)invfac[i-1]=(int)(invfac[i]*(long long)i%MOD);
	--n;
	r[0]=n;
	F(i,1,n+1)r[i]=n-n/i;
	for(int i=n;i;--i)for(int j=0;j<=n;j+=i)if(j!=i)d[i]=max(d[i],d[j]+1);
	f[1]=1;
	F(i,1,n+1)for(int j=0;j<=n;j+=i)if(d[i]==d[j]+1)
(f[j]+=(int)(f[i]*((long long)fac[r[j]]*invfac[r[i]]%MOD-(r[i]?(long long)fac[r[j]-1]*invfac[r[i]-1]%MOD:0)+MOD)%MOD))%=MOD;
	printf("%d\n",f[0]);
	return 0;
}