#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1005,M=11005,MOD=1000000007;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,a[N],sum=1;
unsigned ff[N][M<<1],*f[N],ans;
int main()
{
	read(n);F(i,0,n)read(a[i]),sum+=a[i];
	F(i,0,n+1)f[i]=&ff[i][M],f[i][0]=1;
	F(i,0,n)
	{
		F(j,-sum,sum)(f[i+1][j+a[i]]+=f[i][j])%=MOD;
		F(j,-sum,sum)(f[i+1][j-a[i]]+=f[i][j])%=MOD;
	}
	F(i,1,n+1)(ans+=f[i][0]+MOD-1)%=MOD;
	printf("%d\n",ans);
	return 0;
}