#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=(1<<20)+5,MOD=1000000007;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,n2,m,c[N],pow2[N];
void fwt(int *a,int n,int m)
{
	F(i,0,m)
	{
		int half=1<<i,size=2<<i;
		for(int j=0;j<n;j+=size)for(int u=j,end=j+half,v=j+half;u<end;++u,++v)(a[u]+=a[v])%=MOD;
	}
}
void ifwt(int *a,int n,int m)
{
	F(i,0,m)
	{
		int half=1<<i,size=2<<i;
		for(int j=0;j<n;j+=size)for(int u=j,end=j+half,v=j+half;u<end;++u,++v)(a[u]+=MOD-a[v])%=MOD;
	}
}
int main()
{
	read(n);n2=1;
	F(i,0,n)
	{
		int a;read(a);
		++c[a];
		for(;n2<=a;n2<<=1,++m);
	}
	fwt(c,n2,m);
	F(i,pow2[0]=1,n+1)pow2[i]=(pow2[i-1]<<1)%MOD;
	F(i,0,n2)c[i]=pow2[c[i]]-1;
	ifwt(c,n2,m);
	printf("%d\n",c[0]);
	return 0;
}