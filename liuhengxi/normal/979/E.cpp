#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=64;
const unsigned MOD=1000000007;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,p,c[N],binom[N][N],b2[N][2],e2[N];
unsigned f[N][N][N][N],ans[2];
int main()
{
	read(n);read(p);
	F(i,0,n)read(c[i]),c[i]=2-c[i];
	F(i,0,n)binom[i][0]=1;
	F(i,1,n)F(j,0,n)binom[i][j]=(binom[i-1][j]+binom[i-1][j-1])%MOD;
	F(i,0,n)F(j,0,n)(b2[i][j&1]+=binom[i][j])%=MOD;
	F(i,e2[0]=1,n)e2[i]=(e2[i-1]<<1)%MOD;
	f[0][0][0][0]=1;
	F(i,0,n)
	{
		if(c[i]&1)F(w0,0,i+1)F(w1,0,i-w0+1)F(b0,0,i-w0-w1+1)
		{
			int b1=i-w0-w1-b0;
			(f[w0+1][w1][b0][b1]+=(unsigned long long)f[w0][w1][b0][b1]*b2[b1][1]%MOD*e2[i-b1]%MOD)%=MOD;
			(f[w0][w1+1][b0][b1]+=(unsigned long long)f[w0][w1][b0][b1]*b2[b1][0]%MOD*e2[i-b1]%MOD)%=MOD;
		}
		if(c[i]&2)F(w0,0,i+1)F(w1,0,i-w0+1)F(b0,0,i-w0-w1+1)
		{
			int b1=i-w0-w1-b0;
			(f[w0][w1][b0+1][b1]+=(unsigned long long)f[w0][w1][b0][b1]*b2[w1][1]%MOD*e2[i-w1]%MOD)%=MOD;
			(f[w0][w1][b0][b1+1]+=(unsigned long long)f[w0][w1][b0][b1]*b2[w1][0]%MOD*e2[i-w1]%MOD)%=MOD;
		}
	}
	F(w0,0,n+1)F(w1,0,n-w0+1)F(b0,0,n-w0-w1+1)
	{
		int b1=n-w0-w1-b0;
		(ans[(w1^b1)&1]+=f[w0][w1][b0][b1])%=MOD;
	}
	printf("%d\n",ans[p]);
	return 0;
}