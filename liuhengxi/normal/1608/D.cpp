#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5;
const unsigned MOD=998244353;
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
int n,un,w;
char s[N][3];
modint ans;
modint bruteC(int n,int m)
{
	modint ans=1,den=1;
	if(n<0||m<0||m>n)return 0;
	F(i,1,n+1)ans=ans*i;
	F(i,1,m+1)den=den*i;
	F(i,1,n-m+1)den=den*i;
	ans=ans/den;
	return ans;
}
modint reduce()
{
	int w=0,un=0;
	F(i,0,n)
	{
		if(s[i][0]=='?'&&s[i][1]=='?')++un;
		else if(s[i][0]==s[i][1])return 0;
		else if(s[i][0]=='W'||s[i][1]=='B')++w;
	}
	return modint(2)^un;
}
modint add()
{
	int wb=1,bw=1;
	F(i,0,n)if(s[i][0]=='B'||s[i][1]=='W')wb=0;
	F(i,0,n)if(s[i][0]=='W'||s[i][1]=='B')bw=0;
	return wb+bw;
}
int main()
{
	read(n);
	F(i,0,n)scanf("%s",s[i]);
	F(i,0,n)
	{
		if(s[i][0]=='?')++un;
		if(s[i][0]=='W')++w;
		if(s[i][1]=='?')++un;
		if(s[i][1]=='W')++w;
	}
	ans=bruteC(un,n-w)-reduce()+add();
	printf("%u\n",ans.a);
	return 0;
}