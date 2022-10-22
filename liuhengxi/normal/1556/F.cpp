#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=15,M=(1<<14)+5,MOD=1000000007;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,m,w[N][N],a[N],p[M],g[N][M],ans,h[M],last[M];
int pow(int aa,int b)
{
	long long a=aa,c=1;
	while(b)
	{
		if(b&1)(c*=a)%=MOD;
		b>>=1;(a*=a)%=MOD;
	}
	return c;
}
int get(int i,int j)
{
	long long ans=1;
	while(i)ans=ans*g[__builtin_ctz(i)][j]%MOD,i^=i&-i;
	return ans;
}
int main()
{
	read(n);m=1<<n;
	F(i,0,n)read(a[i]);
	F(i,0,n)F(j,0,n)w[i][j]=a[i]*(long long)pow(a[i]+a[j],MOD-2)%MOD;
	F(i,0,n)g[i][0]=1;
	F(i,0,n)F(j,0,n)g[i][1<<j]=w[i][j];
	F(i,0,n)F(j,1,m)g[i][j]=g[i][j&-j]*(long long)g[i][j^(j&-j)]%MOD;
	F(i,0,m)
	{
		p[i]=1;
		for(int j=(i-1)&i;j;j=(j-1)&i)p[i]=(MOD+p[i]-(long long)p[j]*get(j,i^j)%MOD)%MOD;
		(ans+=(long long)__builtin_popcount(i)*p[i]%MOD*get(i,(m-1)^i)%MOD)%=MOD;
	}
	printf("%d\n",ans);
	return 0;
}