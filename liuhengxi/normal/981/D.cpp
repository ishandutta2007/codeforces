#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=55;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,k;
bool f[N][N];
long long a[N],s[N];
bool check(long long ans)
{
	F(i,0,n+1)F(j,0,n+1)f[i][j]=false;
	f[0][0]=true;
	F(i,0,k)F(u,0,n)if(f[i][u])F(v,u+1,n+1)f[i+1][v]=f[i+1][v]||(((s[v]-s[u])&ans)==ans);
	return f[k][n];
}
int main()
{
	long long ans=0;
	read(n);read(k);
	F(i,0,n)read(a[i]);
	F(i,0,n)s[i+1]=s[i]+a[i];
	for(long long i=1ll<<55;i;i>>=1)if(check(ans|i))ans|=i;
	printf("%lld\n",ans);
	return 0;
}