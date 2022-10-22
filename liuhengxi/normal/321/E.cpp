#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=4005,INF=0x3fffffff;
struct input
{
	unsigned char ibuf[(33<<20)+5],*ip=ibuf;
	input(){fread(ip=ibuf,1,33<<20,stdin);}
	unsigned char gc(){return *(ip++);}
}in;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=in.gc();
	for(;(c^48)>9;c=in.gc())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=in.gc())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,k,u[N][N],s[N][N],g[N][N],f[N/*number of intervals*/][N/*length*/];
void dp(int l,int r,int kl,int kr,int j)
{
	int mid=(l+r)>>1,k=kl;
	if(l==r)return;
	F(i,kl+1,kr+1)if(f[j][i]+g[i][mid]<f[j][k]+g[k][mid])k=i;
	f[j+1][mid]=f[j][k]+g[k][mid];
	dp(l,mid,kl,k,j);
	dp(mid+1,r,k,kr,j);
}
int main()
{
	read(n);read(k);
	F(i,0,n)F(j,0,n)read(u[i][j]);
	F(i,0,n)F(j,i,n)u[i][j]=0;
	F(i,0,n)F(j,0,n)s[i+1][j+1]=s[i+1][j]+s[i][j+1]-s[i][j]+u[i][j];
	F(i,0,n+1)F(j,0,n+1)g[i][j]=s[i][i]-s[i][j]-s[j][i]+s[j][j];
	F(i,1,n+1)f[0][i]=INF;
	F(i,0,k)dp(0,n+1,0,n,i);
	printf("%d\n",f[k][n]);
	return 0;
}