#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5,M=3e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,m,a[N],b[2*M];
long long d[2*M];
void addb(int x,int y){for(++x;x<=2*m;x+=(x&-x))b[x]+=y;}
int sumb(int x)
{
	int ans=0;for(;x;x-=(x&-x))ans+=b[x];
	return ans;
}
void addd(int x,int y){for(++x;x<=2*m;x+=(x&-x))d[x]+=y;}
long long sumd(int x)
{
	long long ans=0;for(;x;x-=(x&-x))ans+=d[x];
	return ans;
}
int main()
{
	long long ans=0,sum=0;
	read(n);
	F(i,0,n)read(a[i]),m=a[i]>m?a[i]:m;
	++m;
	F(i,0,n)
	{
		ans+=sum;
		for(int j=a[i];j<m;j+=a[i])ans-=(sumb(j+a[i])-sumb(j))*(long long)j;
		ans+=i*(long long)a[i];
		ans-=sumd(a[i]+1);
		addb(a[i],1);
		sum+=a[i];
		for(int j=a[i];j<m;j+=a[i])addd(j,a[i]);
		printf("%lld ",ans);
	}
	puts("");
	return 0;
}