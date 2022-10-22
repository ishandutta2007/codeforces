#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
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
namespace fwt
{
	typedef unsigned int ui;typedef unsigned long long ull;
	constexpr ui N=(1<<18)+5,MOD=998244353,INV2=(MOD+1)>>1;
	#define DEFFWT(name,opt)\
	void name(ui *a,ui n){for(ui i=1;i^n;i<<=1)for(ui j=0;j^n;++j,j+=j&i){opt((a[j]),(a[j^i]));}}
	#define opt_and(x,y) x+=y,(x>=MOD)&&(x-=MOD);
	#define opt_iand(x,y) x-=y,x+=(int)x>>31&MOD;
	#define opt_or(x,y) y+=x,(y>=MOD)&&(y-=MOD);
	#define opt_ior(x,y) y-=x,y+=(int)y>>31&MOD;
	#define opt_xor(x,y) x+=y,y<<=1,y=x-y,(x>=MOD)&&(x-=MOD),y+=(int)y>>31&MOD;
	#define opt_ixor(x,y) x+=y,y<<=1,y=x-y,(x>=MOD)&&(x-=MOD),y+=(int)y>>31&MOD,\
	x=(x>>1)+(x&1)*INV2,y=(y>>1)+(y&1)*INV2;
//	DEFFWT(fwt_and,opt_and);
//	DEFFWT(fwt_iand,opt_iand);
//	DEFFWT(fwt_or,opt_or);
//	DEFFWT(fwt_ior,opt_ior);
	DEFFWT(fwt_xor,opt_xor);
	DEFFWT(fwt_ixor,opt_ixor);
}
using fwt::ui;using fwt::ull;using fwt::MOD;using fwt::N;
ull pow(ull a,ui b)
{
	ull c=1;
	for(;b;b>>=1,(a*=a)%=MOD)if(b&1)(c*=a)%=MOD;
	return c;
}
ui n,k,x,y,z,f[8][N],g[8],h[N];
int main()
{
	read(n,k,x,y,z);
	F(i,0,n)
	{
		ui a,b,c;read(a,b,c);
		++f[0][0];++f[1][a];++f[2][b];++f[3][a^b];++f[4][c];++f[5][a^c];++f[6][b^c];++f[7][a^b^c];
	}
	F(i,0,8)fwt::fwt_xor(f[i],1<<k);
	F(i,0,1<<k)
	{
		g[0]=f[0][i];g[1]=f[1][i];g[2]=f[2][i];g[3]=f[3][i];
		g[4]=f[4][i];g[5]=f[5][i];g[6]=f[6][i];g[7]=f[7][i];
		fwt::fwt_ixor(g,8);
		#define x (ull)x
		h[i]=(ui)
		(pow(x+y+z,g[0])
		*pow(MOD-x+y+z,g[1])%MOD
		*pow(MOD+x-y+z,g[2])%MOD
		*pow(MOD+MOD-x-y+z,g[3])%MOD
		*pow(MOD+x+y-z,g[4])%MOD
		*pow(MOD+MOD-x+y-z,g[5])%MOD
		*pow(MOD+MOD+x-y-z,g[6])%MOD
		*pow(MOD+MOD+MOD-x-y-z,g[7])%MOD);
	}
	fwt::fwt_ixor(h,1<<k);
	F(i,0,1<<k)printf("%u ",h[i]);
	puts("");
	return 0;
}