#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5,K=105,MOD=998244353;
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
struct modint
{
	typedef unsigned long long ull;
	unsigned a;
	modint(){a=0;}
	modint(unsigned b){a=b;}
	modint operator+(modint b)const{return (a+b.a)%MOD;}
	modint operator-(modint b)const{return (a+MOD-b.a)%MOD;}
	modint operator*(modint b)const{return a*(ull)b.a%MOD;}
	modint operator/(modint b)const{return a*(ull)(b^-1).a%MOD;}
	modint operator^(int b)const
	{
		unsigned long long aa=a,c=1;b=(b+MOD-1)%(MOD-1);
		for(;b;b>>=1,(aa*=aa)%=MOD)if(b&1)(c*=aa)%=MOD;
		return modint((unsigned)c);
	}
};
int n,k,len,a[N],s[N][K];
modint f[N],g[N][K];
int main()
{
	read(n,k,len);
	if(len==0)return puts("0"),0;
	F(i,0,n)if(~read(a[i]))--a[i];
	F(i,0,n)
	{
		F(j,0,k)s[i+1][j]=s[i][j];
		if(~a[i])
		{
			F(j,0,a[i])++s[i+1][j];
			F(j,a[i]+1,k)++s[i+1][j];
		}
	}
	f[0]=1;
	F(i,1,n+1)F(j,0,k)if(j==a[i-1]||!~a[i-1])
	{
		g[i][j]=f[i-1];
		if(i>=len&&s[i][j]==s[i-len][j])g[i][j]=g[i][j]-f[i-len]+g[i-len][j];
		f[i]=f[i]+g[i][j];
	}
	printf("%u\n",f[n].a);
	return 0;
}