#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=5005,MOD=1000000007,INV2=500000004;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,k,S[N][N],ans;
int pow(int aa,int b)
{
	long long c=1,a=aa;
	while(b)
	{
		if(b&1)(c*=a)%=MOD;
		b>>=1;(a*=a)%=MOD;
	}
	return (int)c;
}
int main()
{
	long long t=1,s=1;
	read(n);read(k);
	S[0][0]=1;
	F(i,1,k+1)F(j,1,k+1)
	{
		S[i][j]=(S[i-1][j-1]+j*(long long)S[i-1][j]%MOD)%MOD;
	}
	s=pow(2,n);
	F(i,0,k+1)
	{
		(ans+=S[k][i]*s%MOD*t%MOD)%=MOD;
		s=s*INV2%MOD;
		(t*=n-i)%=MOD;
	}
	printf("%d\n",ans);
	return 0;
}