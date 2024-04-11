#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5;
const unsigned MOD=1000000007;
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
int n,t,lastm=-1,lastk;
modint fac[N],invfac[N],ans,lastans,inv2=modint(2)^-1,div2=1;
long long s;
modint C(int n,int m){return fac[n]*invfac[m]*invfac[n-m];}
int main()
{
	read(n,s);
	fac[0]=1;F(i,1,n+1)fac[i]=fac[i-1]*i;invfac[n]=fac[n]^-1;for(int i=n;i;--i)invfac[i-1]=invfac[i]*i;
	F(i,1,n+1)
	{
		div2=div2*inv2;
		s-=read(t);
		if(s<0)return printf("%u\n",ans.a),0;
		if(s>=i)ans=ans+1;
		else
		{
			int &m=i,k=s;
			if(!~lastm)
			{
				F(j,0,k+1)lastans=lastans+C(m,j);
				lastm=m;lastk=k;
			}
			else
			{
				lastans=lastans+lastans-C(lastm,lastk);++lastm;
				while(lastk>k)lastans=lastans-C(m,lastk--);
			}
			ans=ans+lastans*div2;
		}
	}
	printf("%u\n",ans.a);
	return 0;
}