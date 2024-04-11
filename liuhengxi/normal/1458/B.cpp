#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=105,INF=0x3fffffff;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,a[N],b[N],s1,s2;
int f[N*N/*cap*/][N/*glass*/]/*water*/;
int main()
{
	read(n);
	F(i,0,n)read(a[i]),read(b[i]);
	F(i,0,n)s1+=a[i],s2+=b[i];
	F(i,0,s1+1)F(j,0,n+1)f[i][j]=-INF;
	f[0][0]=0;
	F(i,0,n)
	{
		for(int j=s1;j>=a[i];--j)for(int k=n;k>=1;--k)
		{
			f[j][k]=f[j][k]>f[j-a[i]][k-1]+b[i]?
			f[j][k]:f[j-a[i]][k-1]+b[i];
		}
	}
	F(k,0,n)
	{
		int ans=0;
		F(i,0,s1+1)
		{
			int a=i*2<f[i][k+1]+s2?i*2:f[i][k+1]+s2;
			if(a>ans)ans=a;
		}
		printf("%0.10lf\n",ans/2.0);
	}
	return 0;
}