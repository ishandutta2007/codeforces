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
int n,a[N],f[N][N],g[N];
int main()
{
	read(n);
	F(i,0,n)read(a[i]);
	F(i,0,n)f[i][i+1]=a[i];
	F(j,2,n+1)for(int i=j-2;~i;--i)F(k,i+1,j)
		if(f[i][k]&&f[i][k]==f[k][j])f[i][j]=f[k][j]+1;
	F(i,1,n+1)g[i]=i;
	F(i,1,n+1)F(j,0,i)if(f[j][i])g[i]=g[i]<g[j]+1?g[i]:g[j]+1;
	printf("%d\n",g[n]);
	return 0;
}