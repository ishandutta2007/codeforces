#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=30005,N2=500,INF=0x3fffffff;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n=30000,n2=250,m,d,a[N],f[N][N2],g[N2],ans;
int main()
{
	read(m);read(d);
	while(m--)
	{
		int p;read(p);
		++a[--p];
	}
	F(i,0,n)F(j,0,2*n2)f[i][j]=-INF;
	--d;
	f[d][n2]=a[d];
	f[d][n2-1]=a[d];
	f[d][n2+1]=a[d];
	ans=a[d];
	F(i,++d,n)
	{
		F(j,0,2*n2)g[j]=-INF;
		F(j,-n2,n2)
		{
			if(-d-j>=0)continue;
			if(i-d-j>=d-1)g[j+n2]=f[i-d-j][j+n2];
		}
		F(j,0,2*n2)
		{
			f[i][j]=g[j];
			if(j)f[i][j]=f[i][j]>g[j-1]?f[i][j]:g[j-1];
			if(j<2*n2-1)f[i][j]=f[i][j]>g[j+1]?f[i][j]:g[j+1];
			if(f[i][j]<0)f[i][j]=-INF;
			f[i][j]+=a[i];
			if(f[i][j]>ans)ans=f[i][j];
		}
	}
	printf("%d\n",ans);
	return 0;
}