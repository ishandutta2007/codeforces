#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5,MOD=998244353;
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
template<typename T>struct BITt
{
	int n;T c[N];
	void init(int n_){n=n_;}
	void add(int x,T y){for(++x;x<=n;x+=x&-x)c[x]=c[x]+y;}
	T sum(int x){T ans=0;for(;x;x-=x&-x)ans=ans+c[x];return ans;}
};
int n,q,d[N],c[N],v[N],m;
modint sum;
BITt<int> s;
BITt<modint> t;
int main()
{
	read(n,q);
	F(i,0,n)v[i]=read(d[i]);
	sort(v,v+n);m=unique(v,v+n)-v;
	F(i,0,n)c[i]=lower_bound(v,v+m,d[i])-v;
	s.init(m);t.init(m);
	F(i,0,n)s.add(c[i],1);
	F(i,0,n)t.add(c[i],d[i]);
	F(i,0,n)sum=sum+d[i];
	while(q--)
	{
		int a,b;read(a,b);b=lower_bound(v,v+m,b)-v;
		int k=n-s.sum(b);modint tt=t.sum(b);
		printf("%u\n",((modint(max(k-a,0))/k)*(sum-tt)+(modint(max(k-a+1,0))/(k+1))*tt).a);
	}
	return 0;
}