#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=(1<<19)+5;
const unsigned MOD=998244353;
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
struct modint
{
	typedef unsigned long long ull;
	unsigned a;
	modint(){a=0;}
	modint(unsigned b){a=b;}
	modint operator+(modint b)const{return (a+b.a)%MOD;}
	modint &operator+=(modint b){(a+=b.a)%=MOD;return *this;}
	modint operator-(modint b)const{return (a+MOD-b.a)%MOD;}
	modint operator*(modint b)const{return (unsigned)(a*(ull)b.a%MOD);}
	modint &operator*=(modint b){a=(unsigned)(a*(ull)b.a%MOD);return *this;}
	modint operator/(modint b)const{return (unsigned)(a*(ull)(b^-1).a%MOD);}
	modint operator^(int b)const
	{
		unsigned long long aa=a,c=1;b=(b+MOD-1)%(MOD-1);
		for(;b;b>>=1,(aa*=aa)%=MOD)if(b&1)(c*=aa)%=MOD;
		return modint((unsigned)c);
	}
};
namespace ntt
{
	#undef F
	#define F(i,l,r) for(unsigned i=l,i##_end=r;i<i##_end;++i)
	typedef unsigned long long ull;
	const unsigned MOD=998244353;
	unsigned n,n2,r[N],m,logn;modint g[N<<1],gg[N],invn;
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
int fn;
int n,k,f;
modint ans[N];
int main()
{
	read(n,k,f);
	for(fn=1;fn<(2*k+1);fn<<=1);
	ntt::init(fn);
	F(i,0,k+1)ans[i]=1;
	F(i,0,n)
	{
		ntt::fft(ans,1);
		F(j,0,fn)ans[j]=ans[j]*ans[j];
		ntt::fft(ans,-1);
		if(i!=n-1)
		{
			for(int j=fn-1;~--j;)ans[j]+=ans[j+1];
			F(j,0,k+1)ans[j]=ans[j]*(k+1-j);
			F(j,k+1,fn)ans[j]=0;
			F(j,0,fn-1)ans[j]=ans[j]-ans[j+1];
		}
	}
	printf("%d\n",(int)ans[f].a);
	return 0;
}