#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int M=5e5+5,N=1e6+5,MOD=1000000007;
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
struct com
{
	static const int N=5e5+5;
	int fac[N];
	com(){F(i,fac[0]=1,N)fac[i]=int((long long)fac[i-1]*i%MOD);}
}com;
auto fac=com.fac;
int m,c[M],b[2*N],*a=b+N,n,d,e=1,l;
int main()
{
	F(i,0,read(m))read(c[i]),++a[1-c[i]],--a[c[i]+1],n=max(n,c[i]);
	for(int i=1-n;i<n;(l+=a[i++])%=MOD)a[i+2]+=a[i],d=int((d+(2ll*l+a[i]-1)*a[i]/2%MOD*i)%MOD),e=int((long long)e*fac[a[i]]%MOD);
	printf("%d %d\n",d,e);
	return 0;
}