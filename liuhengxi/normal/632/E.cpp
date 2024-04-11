#include<cstdio>
#include<algorithm>
#include<random>
using namespace std;
typedef unsigned long long ull;
const int N=(1<<20)+5,MOD=998244353;
struct modint
{
	unsigned a;
	modint()
	{
		a=0;
	}
	modint(unsigned b)
	{
		a=b;
	}
	modint operator+(modint b)const
	{
		return (a+b.a)%MOD;
	}
	modint operator-(modint b)const
	{
		return (a+MOD-b.a)%MOD;
	}
	modint operator*(modint b)const
	{
		return (unsigned)(a*(ull)b.a%MOD);
	}
	modint operator^(int b)const
	{
		unsigned long long aa=a,c=1;
		b=(b+MOD-1)%(MOD-1);
		for(; b; b>>=1,(aa*=aa)%=MOD)if(b&1)(c*=aa)%=MOD;
		return modint((unsigned)c);
	}
} g[2*N],gg[N];
const modint G(3);
int n,m,r[N];
inline void init()
{
	int n1=n<<1;
	g[0]=1;
	g[1]=G^((MOD-1)/n);
	for(int i=1; i<n; ++i)g[i+1]=g[i]*g[1];
	for(int i=0; i<n; ++i)g[n1-i]=g[i];
	for(int i=1; i<n; ++i)r[i]=r[i>>1]>>1|(i&1)<<(m-1);
}
void fft(modint *a,int opt)
{
	for(int i=0; i<n; ++i)
		if(r[i]>i)
			swap(a[r[i]],a[i]);
	for(int i=0; i<m; ++i)
	{
		modint *u,*v,tmp;
		int k,size=2<<i,half=1<<i,t=n/size*opt;
		for(int j=0; j<half; ++j)gg[j]=g[n+j*t];
		for(int l=0,mid=half; l<n; l+=size,mid+=size)
			for(k=0,u=a+l,v=a+mid; k<half; ++k,++u,++v)
			{
				tmp=gg[k]**v;
				*v=*u-tmp;
				*u=*u+tmp;
			}
	}
	if(opt==-1)
	{
		modint invn=modint(n)^-1;
		for(int i=0; i<n; ++i)
			a[i]=a[i]*invn;
		for(int i=1,end=(n+1)/2; i<end; ++i)
			swap(a[i],a[n-i]);
	}
}
int k;
modint a[N];
mt19937 rnd(79774871);
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=0; i<n; ++i)
	{
		int x;
		scanf("%d",&x);
		m=max(m,x);
		a[x]=rnd()%MOD;
	}
	n=k*m+1;
	while(n!=(n&-n))n+=(n&-n);
	for(m=0; (1<<m)!=n; ++m);
	init();
	fft(a,1);
	for(int i=0; i<n; ++i)
		a[i]=a[i]^k;
	fft(a,-1);
	for(int i=0; i<n; ++i)
		if(a[i].a)
			printf("%d ",i);
	puts("");
	return 0;
}