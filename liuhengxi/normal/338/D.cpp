#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=10005;
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
inline long long mul(long long a,long long b,long long p)
{return ((a*(b>>21)%p<<21)+a*(b&((1ull<<21)-1)))%p;}
long long pow(long long a,long long b,long long p)
{
	long long c=1;
	for(;b;b>>=1,a=mul(a,a,p))if(b&1)c=mul(c,a,p);
	return c;
}
inline long long gcd(long long a,long long b)
{
	static int c,d,s;s=0;
	while(a&&b)
	{
		if(a&b&1)
		{
			if(a>b)a-=b;
			else b-=a;
		}
		else
		{
			c=__builtin_ctzll(a),d=__builtin_ctzll(b);
			s+=min(c,d);
			a>>=c,b>>=d;
		}
	}
	return (a^b)<<s;
}
int k,t;
long long n,m,a[N],lcm=1,u,v=1,phiv,p[20],o[20],mp[20];
void factor(long long x)
{
	for(long long i=2;i*i<=x;++i)if(x%i==0)
	{
		p[t++]=i;
		while(x%i==0)x/=i;
	}
	if(x!=1)p[t++]=x;
}
inline int V(long long x,long long y)
{
	int ans=0;
	while(y%x==0)y/=x,++ans;
	return ans;
}
int main()
{
	read(n,m,k);
	F(i,0,k)
	{
		read(a[i]);
		long long d=a[i]/gcd(lcm,a[i]);
		if(d>n/lcm)return puts("NO"),0;
		lcm*=d;
	}
	if(lcm>n)return puts("NO"),0;
	n=lcm;
	factor(lcm);
	F(i,0,k)F(j,0,t)
	{
		int vp=V(p[j],a[i]);
		if(vp>mp[j])mp[j]=vp,o[j]=i;
	}
	F(i,0,t)
	{
		long long x=-o[i],y=1;
		while(mp[i]--)y*=p[i];
		x&&(x+=y);
		x=(x-u%y+y)%y;
		u+=mul(x,pow(v,y-y/p[i]-1,y),y)*v;
		v*=y;
	}
	if(!u)u+=v;
	if(u+k-1>m)return puts("NO"),0;
	F(i,0,k)if(gcd(n,u+i)!=a[i])return puts("NO"),0;
	puts("YES");
	return 0;
}