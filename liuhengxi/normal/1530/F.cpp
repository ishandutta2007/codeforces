#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=25,M=(1<<21)+5,MOD=31607;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,a[N][N],b[N][N],ans,f[N][M],full,pop[M];
inline int calc()
{
	long long ans=0;
	F(i,0,n)
	{
		f[i][0]=1;
		F(j,0,n)f[i][1<<j]=b[i][j];
		F(j,1,1<<n)if(j!=(j&-j))f[i][j]=f[i][j&-j]*f[i][j^(j&-j)]%MOD;
		F(j,0,1<<n)(f[i][j]+=MOD-f[i][full])%=MOD;
	}
	F(i,0,1<<n)
	{
		int tmp=1;
		if(i)pop[i]=pop[i^(i&-i)]^1;
		F(j,0,n)(tmp*=f[j][i])%=MOD;
		if(pop[i])ans+=MOD-tmp;
		else ans+=tmp;
	}
	return ans%MOD;
}
int main()
{
	int tmp;
	read(n);full=(1<<n)-1;
	F(i,0,n)F(j,0,n)read(a[i][j]),(a[i][j]*=3973)%=MOD;
	F(i,0,n)F(j,0,n)b[i][j]=a[i][j];
	ans+=calc();
	tmp=1;
	F(i,0,n)(tmp*=b[i][i])%=MOD,b[i][i]=1;
	ans-=calc()*tmp%MOD;
	F(i,0,n)F(j,0,n)b[i][j]=a[i][j];
	tmp=1;
	F(i,0,n)(tmp*=b[i][n-i-1])%=MOD,b[i][n-i-1]=1;
	ans-=calc()*tmp%MOD;
	F(i,0,n)(tmp*=b[i][i])%=MOD,b[i][i]=1;
	ans+=calc()*tmp%MOD;
	ans=((1-ans)%MOD+MOD)%MOD;
	printf("%d\n",ans);
	return 0;
}