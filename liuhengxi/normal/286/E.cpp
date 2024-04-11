#include<cstdio>
#include<algorithm>
using namespace std;
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
namespace poly
{
	#define F(i,l,r) for(ui i=l,i##_end=r;i<i##_end;++i)
	typedef unsigned ui;typedef unsigned long long ull;
	constexpr ui MOD=998244353,G=3,LogN=21,N=(1<<LogN)+5,INV2=(MOD+1)>>1;
	constexpr ull pow(ull a,ui b)
	{
		ull c=1;
		for(;b;b>>=1,(a*=a)%=MOD)if(b&1)(c*=a)%=MOD;
		return c;
	}
	constexpr ui I=pow(G,(MOD-1)>>2);
	ui getn(ui n){return n<2?1:1<<(32-__builtin_clz(n-1));}
	namespace NTT
	{
		ui mxn,mxlgn,r[N],g[N];
		void init(ui n)
		{
			mxn=n=getn(n);mxlgn=31-__builtin_clz(mxn);
			F(i,1,n)r[i]=r[i>>1]>>1|(i&1)<<(mxlgn-1);
			g[0]=1;g[1]=(ui)pow(3,(MOD-1)/n);
			F(i,1,n)g[i+1]=(ui)(g[i]*(ull)g[1]%MOD);
		}
		void ntt(ui *a,ui n,ui opt)
		{
			static ull gg[N];
			ui lgn=31-__builtin_clz(n),dlg=mxlgn-lgn;
			F(i,0,n)if((r[i]>>dlg)>i)swap(a[r[i]>>dlg],a[i]);
			F(i,0,lgn)
			{
				ui h=1<<i,s=2<<i;
				ui *u=&g[0],*v,delta=mxn/s,tmp;
				F(j,0,h)gg[j]=*u,u+=delta;
				for(ui l=0,mid=h,k;l<n;l+=s,mid+=s)
					for(u=a+l,v=a+mid,k=0;k<h;++k,++u,++v)
					{
						tmp=(ui)(gg[k]**v%MOD);
						*v=*u-tmp;*v+=(int)*v>>31&MOD;
						(*u)+=tmp;(*u>=MOD)&&(*u-=MOD);
					}
			}
			if(!~opt)
			{
				F(i,1,n>>1)swap(a[i],a[n-i]);
				ull invn=pow(n,MOD-2);
				F(i,0,n)a[i]=(ui)(a[i]*invn%MOD);
			}
		}
		void mul(const ui *aa,ui n,const ui *bb,ui m,ui *cc,ui k=-1)
		{
			static ui a[N],b[N],c[N];
			ui siz=getn(n+m-1);
			F(i,0,n)a[i]=aa[i];
			F(i,0,m)b[i]=bb[i];
			F(i,n,siz)a[i]=0;
			F(i,m,siz)b[i]=0;
			ntt(a,siz,1);
			ntt(b,siz,1);
			F(i,0,siz)c[i]=(ui)((ull)a[i]*b[i]%MOD);
			ntt(c,siz,-1);
			F(i,0,min(k,n+m-1))cc[i]=c[i];
		}
	}
	using NTT::init;using NTT::ntt;using NTT::mul;
	void derivative(const ui *f,ui n,ui *g)
	{
		F(i,0,n-1)g[i]=(ui)(f[i+1]*(i+1ull)%MOD);
	}
	void integrate(const ui *f,ui n,ui *g)
	{
		static ui inv[N],maxn=0;
		if(n>maxn)
		{
			if(!maxn)inv[++maxn]=1;
			F(i,maxn+1,n+1)inv[i]=(ui)(inv[MOD%i]*(ull)(MOD-MOD/i)%MOD);
			maxn=n;
		}
		for(ui i=n;i;--i)g[i]=(ui)(f[i-1]*(ull)inv[i]%MOD);
		g[0]=0;
	}
}
using poly::ui;using poly::ull;using poly::N;
ui n,m,a[N],f[N],g[N],cnt;
bool ans[N];
int main()
{
	read(n,m);++m;
	poly::init(m<<1);
	f[0]=1;
	F(i,0,n)f[read(a[i])]=1;
	poly::mul(f,m,f,m,g,m);
	F(i,1,m)
	{
		if(f[i]==1)
		{
			if(g[i]==2)ans[i]=true,++cnt;
		}
		else if(g[i])return puts("NO"),0;
	}
	puts("YES");
	printf("%d\n",cnt);
	F(i,1,m)if(ans[i])printf("%d ",i);
	puts("");
	return 0;
}