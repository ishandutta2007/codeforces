#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=5e3+5,MOD=1000000007;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
int n,a[N],c[N],pool[2*N*N],*p=pool,*f[N],*g[N],ans[2*N];
int main()
{
	F(i,0,N)f[i]=p,p+=N-i;
	F(i,0,N)g[i]=p,p+=N+i;
	F(i,0,read(n)-1)read(a[i]);
	c[0]=1;
	F(i,0,n-1)c[i+1]=c[i]*(long long)a[i]%MOD;
	for(int i=n;~--i;)
	{
		f[i][0]=1;
		F(j,1,n-i+1)(ans[j]+=c[i]*(long long)(f[i][j]=f[i+1][j-1]*(long long)a[i]%MOD)%MOD)%=MOD;
	}
	g[0][0]=1;
	F(i,1,n)
	{
		g[i][0]=1;
		F(j,1,n+i)(ans[j]+=c[i]*(long long)(g[i][j]=(g[i-1][j-1]+(a[i-1]-1ll)*(j-2<=n-i?f[i][j-2]:0))%MOD)%MOD)%=MOD;
	}
	F(i,1,2*n-1)printf("%lld ",ans[i]*500000004ll%MOD);
	puts("");
	return 0;
}