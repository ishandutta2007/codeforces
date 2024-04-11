#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int MOD=998244353,N=5e3+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,m,k,ans,f[N][N];
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
int C(int n,int m)
{
	int ans=1,ans2=1;
	F(i,0,m)ans=ans*(long long)(n-i)%MOD;
	F(i,1,m+1)ans2=ans2*(long long)i%MOD;
	return (long long)ans*pow(ans2,MOD-2)%MOD;
}
int main()
{
	read(n);read(m);read(k);m=pow(m,MOD-2);
	F(i,f[0][0]=1,k+1)F(j,1,i+1)f[i][j]=(f[i-1][j]+f[i-1][j-1])*(long long)j%MOD;
	F(i,1,min(n,k)+1)(ans+=(long long)C(n,i)*pow(m,i)%MOD*f[k][i]%MOD)%=MOD;
	printf("%d\n",ans);
	return 0;
}