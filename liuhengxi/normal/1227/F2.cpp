#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
typedef unsigned long long ull;
const int N=(1<<19)+5;const unsigned MOD=998244353;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct modint
{
	unsigned a;
	modint(){a=0;}
	modint(unsigned b){a=b;}
	modint operator+(modint b)const{return (a+b.a)%MOD;}
	modint operator-(modint b)const{return (a+MOD-b.a)%MOD;}
	modint operator*(modint b)const{return a*(ull)b.a%MOD;}
	modint operator^(int b)const
	{
		unsigned long long aa=a,c=1;b=(b+MOD-1)%(MOD-1);
		for(;b;b>>=1,(aa*=aa)%=MOD)if(b&1)(c*=aa)%=MOD;
		return modint((unsigned)c);
	}
}a[N],b[N],g[N<<1],gg[N];
const modint G(3);
int n,k,h[N],c,d,n2,m,r[N];
inline void init()
{
	int n21=n2<<1;
	g[0]=1;
	g[1]=G^((MOD-1)/n2);
	F(i,1,n2)g[i+1]=g[i]*g[1];
	F(i,0,n2)g[n21-i]=g[i];
	--m;
	F(i,1,n2)r[i]=r[i>>1]>>1|(i&1)<<m;
	++m;
}
void fft(modint *a,int opt)
{
	#define n n2
	F(i,0,n)if(r[i]>i)swap(a[r[i]],a[i]);
	F(i,0,m)
	{
		modint *u,*v,tmp;unsigned k,size=2<<i,half=1<<i;int t=n/size*opt;
		F(j,0,half)gg[j]=g[n+j*t];
		for(int l=0,mid=half;l<n;l+=size,mid+=size)
		for(k=0,u=a+l,v=a+mid;k<half;++k,++u,++v)
		{
			tmp=gg[k]**v;
			*v=*u-tmp;
			*u=*u+tmp;
		}
	}
	if(opt==-1)
	{
		modint invn=modint(n2)^-1;
		F(i,0,n)a[i]=a[i]*invn;
		F(i,1,(n+1)/2)swap(a[i],a[n-i]);
	}
	#undef n
}
int main()
{
	modint ans;
	read(n);read(k);
	F(i,0,n)read(h[i]);
	F(i,0,n)++(h[i]==h[(i+1)%n]?c:d);
	a[1]=k;
	b[0]=1;b[1]=k-2;b[2]=1;
	for(n2=1;n2<((n<<1)+1);n2<<=1,++m);
	init();
	fft(a,1);
	fft(b,1);
	F(i,0,n2)a[i]=(a[i]^c)*(b[i]^d);
	fft(a,-1);
	ans=((modint(k)^n)-a[n])*(modint(2)^-1);
	printf("%d\n",ans.a);
	return 0;
}