#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int MOD=1000000007;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct mat
{
	const static int MOD=MOD-1;
	int a[5][5];
	mat(int b=0)
	{
		a[0][1]=a[0][2]=a[0][3]=a[0][4]=0;a[1][0]=a[1][2]=a[1][3]=a[1][4]=0;
		a[2][0]=a[2][1]=a[2][3]=a[2][4]=0;a[3][0]=a[3][1]=a[3][2]=a[3][4]=0;
		a[4][0]=a[4][1]=a[4][2]=a[4][3]=0;a[0][0]=a[1][1]=a[2][2]=a[3][3]=a[4][4]=b;
	}
	mat operator*(mat b)
	{
		mat c;
		F(i,0,5)F(k,0,5)F(j,0,5)(c.a[i][j]+=(long long)a[i][k]*b.a[k][j]%MOD)%=MOD;
		return c;
	}
	mat operator^(long long b)
	{
		mat aa=*this,c(1);
		while(b)
		{
			if(b&1)c=c*aa;
			aa=aa*aa;
			b>>=1;
		}
		return c;
	}
}f;
long long n;int f1,f2,f3,c;
int pow(int aa,int b)
{
	long long a=aa,c=1;
	while(b)
	{
		if(b&1)(c*=a)%=MOD;
		(a*=a)%=MOD;b>>=1;
	}
	return (int)c;
}
int main()
{
	long long ans=1;
	read(n);read(f1);read(f2);read(f3);read(c);
	f.a[1][0]=1;f.a[2][1]=1;f.a[0][2]=1;f.a[1][2]=1;f.a[2][2]=1;f.a[3][2]=2;f.a[3][3]=1;
	f.a[4][3]=1;f.a[4][4]=1;
	f=f^(n-3);
	ans=ans*pow(f1,f.a[0][2])%MOD;
	ans=ans*pow(f2,f.a[1][2])%MOD;
	ans=ans*pow(f3,f.a[2][2])%MOD;
	ans=ans*pow(c,f.a[3][2]+f.a[4][2])%MOD;
	printf("%lld\n",ans);
	return 0;
}