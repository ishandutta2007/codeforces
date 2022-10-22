#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int M=2e5+5,N=1<<19;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T>T read(){T x;return read(x);}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
namespace ntt
{
	typedef unsigned long long ull;
	const unsigned MOD=998244353;
	struct modint
	{
		typedef unsigned long long ull;
		unsigned a;
		modint(){a=0;}
		modint(unsigned b){a=b;}
		modint operator+(modint b)const{return (a+b.a)%MOD;}
		modint &operator+=(modint b){(a+=b.a)%=MOD;return *this;}
		modint operator-(modint b)const{return (a+MOD-b.a)%MOD;}
		modint operator*(modint b)const{return a*(ull)b.a%MOD;}
		modint &operator*=(modint b){a=a*(ull)b.a%MOD;return *this;}
		modint operator/(modint b)const{return a*(ull)(b^-1).a%MOD;}
		modint operator^(int b)const
		{
			unsigned long long aa=a,c=1;b=(b+MOD-1)%(MOD-1);
			for(;b;b>>=1,(aa*=aa)%=MOD)if(b&1)(c*=aa)%=MOD;
			return modint((unsigned)c);
		}
	};	
	#undef F
	#define F(i,l,r) for(unsigned i=l,i##_end=r;i<i##_end;++i)
	unsigned n,n2,r[N],m,logn;modint a[N],g[2*N],gg[N],invn;
	void init(unsigned n_)
	{
		n=n_;for(n2=1;n2<n;n2<<=1,++logn);
		--logn;
		F(i,0,n2)r[i]=r[i>>1]>>1|(i&1)<<logn;
		++logn;
		invn=modint(n2)^-1;
		g[0]=1;
		g[1]=modint(3)^((MOD-1)/n2);
		F(i,2,n2+1)g[i]=g[i-1]*g[1];
		F(i,0,n2)g[2*n2-i]=g[i];
	}
	void fft(modint *a,int opt)
	{
		register modint *u,*v;modint tmp;
		F(i,0,n2)if(r[i]>i)swap(a[i],a[r[i]]);
		F(i,0,logn)
		{
			register unsigned half=1<<i,size=2<<i,k;unsigned t=n2/size*opt;
			F(j,0,half)gg[j]=g[n2+t*j];
			for(unsigned l=0,mid=half;l<n2;l+=size,mid+=size)
			for(u=a+l,v=a+mid,k=0;k<half;++k,++u,++v)
			{
				tmp=gg[k]*(*v);
				(*v)=(*u)-tmp;
				(*u)+=tmp;
			}
		}
		if(opt==-1)
		{
			F(i,0,n2)a[i]*=invn;
			F(i,1,(n2+1)/2)swap(a[i],a[n2-i]);
		}
	}
	#undef F
	#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
}
int n,x,y,a[M],f[N];
ntt::modint b[N],c[N];
int main()
{
	read(n,x,y);
	F(i,0,n+1)b[read(a[i])]=1,c[x-a[i]]=1;
	ntt::init(2*x+1);
	ntt::fft(b,1);
	ntt::fft(c,1);
	F(i,0,ntt::n2)b[i]*=c[i];
	ntt::fft(b,-1);
	F(i,0,N)f[i]=-1;
	F(i,x+1,2*x+1)if(b[i].a)f[i-x+y]=i-x+y;
	x*=2;
	F(i,1,N)for(int j=i<<1;j<N;j+=i)f[j]=max(f[j],f[i]);
	for(int q=read<int>();q--;)
	{
		int l=read<int>()>>1;
		printf("%d ",~f[l]?f[l]<<1:-1);
	}
	puts("");
	return 0;
}