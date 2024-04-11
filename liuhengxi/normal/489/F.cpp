#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=505;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,m,mod,c[N],two,one,f[N+1][N+1];
int main()
{
	read(n);read(m);read(mod);
	F(i,0,m)F(j,0,n)
	{
		char ch=getchar();
		while(ch!='0'&&ch!='1')ch=getchar();
		c[j]+=ch-'0';
	}
	F(i,0,n)if(c[i]==0)++two;else if(c[i]==1)++one;
	f[0][0]=1;
	F(i,0,n+1)F(j,0,n+1)if(i+j<=n)
	{
		if(j>1)(f[i][j]+=j*(j-1ll)/2*f[i][j-2]%mod)%=mod;
		if(i&&j)(f[i][j]+=i*j*(long long)f[i-1][j]%mod)%=mod;
		if(i>1)(f[i][j]+=i*(i-1ll)/2*f[i-2][j+2]%mod)%=mod;
	}
	printf("%d\n",f[two][one]);
	return 0;
}