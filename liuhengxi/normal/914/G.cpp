#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int M=1e6+5,N=(1<<17)+5,LogN=19,MOD=1000000007,I2=500000004;
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
int n,logn;
struct poly
{
	int s[N];
	int &operator[](int id){return s[id];}
	const int &operator[](int id)const{return s[id];}
	poly &copy(const poly &a){F(i,0,n)s[i]=a[i];return *this;}
}tmp1,tmp2,tmp3[LogN],tmp4[LogN],tmp5[LogN];
void fwt(poly &a,void f(int&,int&))
{for(int i=1;i<=n;i<<=1)F(j,0,n)if(j&i)f(a[j^i],a[j]);}
void fand(poly &a){fwt(a,[](int &x,int &y){(x+=y)%=MOD;});}
void iand(poly &a){fwt(a,[](int &x,int &y){x-=y;x+=(x>>31)&MOD;});}
void f_or(poly &a){fwt(a,[](int &x,int &y){(y+=x)%=MOD;});}
void i_or(poly &a){fwt(a,[](int &x,int &y){y-=x;y+=(y>>31)&MOD;});}
void fxor(poly &a){fwt(a,[](int &x,int &y){static int z;z=x;(x+=y)%=MOD;y=z-y;y+=y>>31&MOD;});}
void ixor(poly &a){fwt(a,[](int &x,int &y){static int z;z=x;(x+=y)%=MOD;y=z-y;y+=y>>31&MOD;
x=int(x*(long long)I2%MOD);y=int(y*(long long)I2%MOD);});}
template<void trans(poly &),void itrans(poly &)>void opt(const poly &a,const poly &b,poly &c)
{
	tmp1.copy(a);tmp2.copy(b);
	trans(tmp1);trans(tmp2);
	F(i,0,n)c[i]=(int)((long long)tmp1[i]*tmp2[i]%MOD);
	itrans(c);
}
#define __POLY_FWT__(o)\
void p##o(const poly &a,const poly &b,poly &c){opt<f##o,i##o>(a,b,c);}
__POLY_FWT__(and);__POLY_FWT__(_or);__POLY_FWT__(xor);
#undef __POLY_FWT__
void psub(const poly &a,const poly &b,poly &c)
{
	F(i,0,logn+1)F(j,0,n)tmp3[i][j]=tmp4[i][j]=tmp5[i][j]=0;
	F(i,0,n)tmp3[__builtin_popcount(i)][i]=a[i];
	F(i,0,n)tmp4[__builtin_popcount(i)][i]=b[i];
	F(i,0,logn+1)f_or(tmp3[i]),f_or(tmp4[i]);
	F(i,0,n)F(j,0,logn+1)F(k,0,logn+1-j)(tmp5[j+k][i]+=int((long long)tmp3[j][i]*tmp4[k][i]%MOD))%=MOD;
	F(i,0,logn+1)i_or(tmp5[i]);
	F(i,0,n)c[i]=tmp5[__builtin_popcount(i)][i];
}
poly a,b,c;
int m,f[N],ans;
int main()
{
	read(m);
	F(i,0,m)
	{
		int s;read(s);
		++a[s];
		if(s>n)n=s;
	}
	++n;
	while((1<<logn)<n)++logn;
	n=1<<logn;
	psub(a,a,b);
	pxor(a,a,c);
	f[1]=1;
	F(i,2,n)f[i]=(f[i-1]+f[i-2])%MOD;
	F(i,0,n)a[i]=int((long long)a[i]*f[i]%MOD);
	F(i,0,n)b[i]=int((long long)b[i]*f[i]%MOD);
	F(i,0,n)c[i]=int((long long)c[i]*f[i]%MOD);
	pand(a,b,a);pand(a,c,a);
	F(i,0,n)if(__builtin_popcount(i)==1)ans=(ans+a[i])%MOD;
	printf("%d\n",ans);
	return 0;
}