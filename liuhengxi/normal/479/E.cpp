#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=5005,MOD=1000000007;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,k,a,b,f[N][N],ans;
int main()
{
	read(n);read(a);read(b);read(k);
	if(a>b)a=a-b,n=n-b+1;
	else a=b-a,n=b;
	f[0][a]=1;
	F(i,0,k)
	{
		int sum=0;
		for(int j=1;j<n;++j)(sum+=f[i][j])%=MOD;
		for(int j=1;j<n;++j)
		{
			if(!(j&1))(sum+=MOD-f[i][j/2])%=MOD;
			f[i+1][j]=(sum-f[i][j]+MOD)%MOD;
		}
	}
	for(int j=0;j<=n;++j)(ans+=f[k][j])%=MOD;
	printf("%d\n",ans);
	return 0;
}