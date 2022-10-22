#include<cstdio>
#include<algorithm>
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
int n,l[N],r[N];
modint p[N],ans;
inline modint len(int l,int r){return modint(l<r?r-l:0);}
int main()
{
	read(n);
	F(i,0,n)read(l[i]),--l[i];
	F(i,0,n)read(r[i]);
	ans=MOD-n;
	F(i,0,n-1)ans=ans+(p[i]=len(max(l[i],l[i+1]),min(r[i],r[i+1]))/(len(l[i],r[i])*len(l[i+1],r[i+1])));
	ans=ans*ans;
	F(i,0,n-1)ans=ans-p[i]*p[i]+p[i];
	F(i,0,n-2)
	{
		ans=ans+(len(max(l[i],max(l[i+1],l[i+2])),min(r[i],min(r[i+1],r[i+2])))
		/(len(l[i],r[i])*len(l[i+1],r[i+1])*len(l[i+2],r[i+2]))-p[i]*p[i+1])*2;
	}
	printf("%u\n",ans.a);
	return 0;
}