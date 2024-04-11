#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=505,MOD=1000000007;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,a[N][N],f[N][N],g[N][N];
int main()
{
	read(n);
	F(i,0,n)F(j,0,n)read(a[i][j]);
	F(i,0,n)g[i][1]=f[i][1]=1;
	F(j,2,n+1)
	{
		F(i,0,n)
		{
			if(a[i][(i+j-1)%n])
				F(k,1,j)(f[i][j]+=g[i][k]*(long long)g[(i+k)%n][j-k]%MOD)%=MOD;
			F(k,1,j)(g[i][j]+=f[i][k+1]*(long long)g[(i+k)%n][j-k]%MOD)%=MOD;
		}
	}
	printf("%d\n",g[0][n]);
	return 0;
}