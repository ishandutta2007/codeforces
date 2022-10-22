#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=105;
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
	modint& operator+=(modint b){return *this=*this+b;}
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
int n,x;
modint f[N][N][N],pow2[N];
char s[N];
int main()
{
	read(n);read(x);
	scanf("%s",s);
	F(i,0,n)f[s[i]-'0'][i][i+1]=1;
	F(i,0,n+1)f[0][i][i]=f[1][i][i]=1;
	pow2[1]=pow2[0]=2;
	F(i,2,x+1)
	{
		pow2[i]=pow2[i-1]*pow2[i-2];
		F(l,0,n+1)F(r,l,n+1)
		{
			F(mid,l,r+1)
			{
				f[i][l][r]+=f[i-1][l][mid]*f[i-2][mid][r];
			}
			if(l==0)f[i][l][r]+=(pow2[i-1]-f[i-1][0][0])*f[i-2][l][r];
			if(r==n)f[i][l][r]+=(pow2[i-2]-f[i-2][n][n])*f[i-1][l][r];
		}
	}
	printf("%u\n",f[x][0][n].a);
	return 0;
}