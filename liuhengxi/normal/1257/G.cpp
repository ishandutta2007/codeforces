#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=(1<<19)+5,M=(1<<21)+5,m=1<<21;
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
namespace ntt
{
	typedef unsigned long long ull;
	const unsigned MOD=998244353;
	struct modint
	{
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
	unsigned n,r[N],m,logn;modint a[N],g[N],gg[N];
	void init(unsigned n_)
	{
		for(n=1;n<n_;n<<=1,++logn);
		g[0]=1;
		g[1]=modint(3)^((MOD-1)/n);
		F(i,2,n+1)g[i]=g[i-1]*g[1];
		F(i,0,n)g[2*n-i]=g[i];
	}
	void fft(modint *a,unsigned n,int opt)
	{
		register modint *u,*v;modint tmp;
		unsigned logn=0;modint invn=modint(n)^-1;
		while((1u<<logn)<n)++logn;
		--logn;
		F(i,0,n)r[i]=r[i>>1]>>1|(i&1)<<logn;
		++logn;
		F(i,0,n)if(r[i]>i)swap(a[i],a[r[i]]);
		F(i,0,logn)
		{
			register unsigned half=1<<i,size=2<<i,k;unsigned t=ntt::n/size*opt;
			F(j,0,half)gg[j]=g[ntt::n+t*j];
			for(unsigned l=0,mid=half;l<n;l+=size,mid+=size)
			for(u=a+l,v=a+mid,k=0;k<half;++k,++u,++v)
			{
				tmp=gg[k]*(*v);
				(*v)=(*u)-tmp;
				(*u)+=tmp;
			}
		}
		if(opt==-1)
		{
			F(i,0,n)a[i]*=invn;
			F(i,1,(n+1)/2)swap(a[i],a[n-i]);
		}
	}
	#undef F
	#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
};
int n,c[M],pool[2*N],*a[M]={pool};
ntt::modint u[N],v[N];
int dfs(int l,int r)
{
	int sum,sl,sr,mid=(l+r)>>1,size=1;
	if(r-l==1)
	{
		F(i,0,c[l]+1)a[l][i]=1;
		return c[l];
	}
	sl=dfs(l,mid);sr=dfs(mid,r);sum=sl+sr;
	while(size<=sum)size<<=1;
	F(i,0,size)u[i]=v[i]=0;
	F(i,0,sl+1)u[i]=a[l][i];
	F(i,0,sr+1)v[i]=a[mid][i];
	fft(u,size,1);fft(v,size,1);
	F(i,0,size)u[i]*=v[i];
	fft(u,size,-1);
	F(i,0,sum+1)a[l][i]=u[i].a;
	return sum;
}
int main()
{
	F(i,0,read(n)){int p;++c[(read(p)-1)/2];}
	ntt::init(n+1);
	F(i,0,m)a[i+1]=a[i]+c[i]*2;
	dfs(0,m);
	printf("%u\n",a[0][n/2]);
	return 0;
}