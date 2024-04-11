#include<cstdio>
#include<cstring>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1005,MOD=1000000007;
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
int n,f[64][N],C[N][N];
long long z;
int calc(long long s)
{
	long long ans=0;
	memset(f,0,sizeof f);
	f[0][0]=1;
	F(i,0,60)
	{
		for(int j=z>>i&1;j<=n;j+=2)F(k,0,(int)min((long long)n,s-j)+1)
		{
			int t=(int)((s>>1)-((s-j-k)>>1));
			f[i+1][t]=(int)((f[i+1][t]+C[n][j]*(long long)f[i][k])%MOD);
		}
		s>>=1;
	}
	F(i,0,n+1)ans+=f[60][i];
	return (int)(ans%MOD);
}
int main()
{
	F(i,0,N)C[i][0]=1;
	F(i,0,N)F(j,1,i+1)C[i][j]=C[i-1][j]+C[i-1][j-1],(C[i][j]>=MOD)&&(C[i][j]-=MOD);
	int ans;
	long long l,r;
	read(n,l,r,z);--l;
	ans=(calc(r)-calc(l)+MOD)%MOD;
	printf("%d\n",ans);
	return 0;
}