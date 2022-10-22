#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=20,M=2520,A[48]={1,2,3,4,5,6,7,8,9,10,12,14,15,18,20,21,24,28,30,35,36,40,42,45,56,60,63,70,72,84,90,105,120,126,140,168,180,210,252,280,315,360,420,504,630,840,1260,2520};
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int B[M+1],d[N],t,LCM[M+1][M+1];
long long l,r,xx[N],f[N][M][48],g[N][M][48];
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int lcm(int a,int b){return b?a*b/gcd(a,b):a;}
long long dp(long long x)
{
	int n=1;
	long long ans=0;
	if(!x)return 1;
	xx[0]=x;
	while(xx[n-1]>=10)xx[n]=xx[n-1]/10,++n;
	F(i,0,n)d[n-1-i]=xx[i]%10;
	g[0][0][0]=1;
	F(i,0,n)F(a,0,M)F(b,0,48)f[i+1][a][b]=g[i+1][a][b]=0;
	F(i,0,n)
	{
		F(a,0,M)F(b,0,48)F(j,0,10)
		{
			f[i+1][(a*10+j)%M][B[LCM[A[b]][j]]]+=f[i][a][b];
			if(j==d[i])g[i+1][(a*10+j)%M][B[LCM[A[b]][j]]]+=g[i][a][b];
			else if(j<d[i])f[i+1][(a*10+j)%M][B[LCM[A[b]][j]]]+=g[i][a][b];
		}
	}
	F(a,0,M)F(b,0,48)if(a%A[b]==0)ans+=f[n][a][b]+g[n][a][b];
	return ans;
}
int main()
{
	F(i,0,M+1)B[i]=-1;
	F(i,0,M+1)F(j,0,M+1)LCM[i][j]=lcm(i,j);
	F(i,0,48)B[A[i]]=i;
	read(t);
	while(t--)
	{
		read(l);read(r);
		printf("%lld\n",dp(r)-dp(l-1));
	}
	return 0;
}