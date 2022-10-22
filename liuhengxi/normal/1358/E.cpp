#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=5e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,a[N],up,down,c[N];
long long s[N],x;
constexpr long long floor(long long a,long long b){return (a-(a%b+b)%b)/b;}
constexpr long long ceil(long long a,long long b){return floor(a,b)+(a%b?1:0);}
int main()
{
	read(n);up=(n+1)>>1,down=n>>1;
	for(int i=up-1;~i;--i)read(a[i]);
	read(x);
	F(i,0,up)s[i+1]=s[i]+a[i];
	F(i,1,up+1)
	{
		long long l=0,r=0;
		if(x<0)l=ceil(s[i],-x)+i,r=down+i+1;
		if(x==0&&s[i]<=0)l=down+1,r=down+i+1;
		if(x>0)l=down+1,r=min(floor(-s[i],x),(long long)down)+i+1;
		if(l<0)l=0;
		if(r>n)r=n+1;
		if(l<r)++c[l],--c[r];
	}
	F(i,1,n+1)c[i]+=c[i-1];
	F(i,down+1,n+1)if(c[i]==0)return printf("%d\n",i),0;
	puts("-1");
	return 0;
}