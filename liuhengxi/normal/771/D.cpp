#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=80,INF=0x3fffffff;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
inline int g(int *a,int *b,int *c,int x,int y,int z)
{return max(b[a[x]]-y,0)+max(c[a[x]]-z,0);}
int n,sv[N],sk[N],sx[N],pv[N],pk[N],px[N],vv,kk,xx,f[N/*v*/][N/*k*/][N/*x*/][2/*last isn't v*/];
char s[N];
int main()
{
	read(n);
	scanf("%s",s);
	F(i,0,n)sv[i+1]=sv[i]+(s[i]=='V');
	F(i,0,n)sk[i+1]=sk[i]+(s[i]=='K');
	F(i,0,n)sx[i+1]=sx[i]+(s[i]!='V'&&s[i]!='K');
	F(i,0,n)(s[i]=='V'?pv[vv++]=i:(s[i]=='K'?pk[kk++]=i:px[xx++]))=i;
	F(i,0,vv+1)F(j,0,kk+1)F(k,0,xx+1)f[i][j][k][0]=f[i][j][k][1]=INF;
	f[0][0][0][1]=0;
	F(i,0,vv+1)F(j,0,kk+1)F(k,0,xx+1)
	{
		if(i)f[i][j][k][0]=min(f[i][j][k][0],f[i-1][j][k][0]+g(pv,sk,sx,i-1,j,k));
		if(j)f[i][j][k][1]=min(f[i][j][k][1],f[i][j-1][k][1]+g(pk,sv,sx,j-1,i,k));
		if(k)f[i][j][k][1]=min(f[i][j][k][1],f[i][j][k-1][0]+g(px,sv,sk,k-1,i,j));
		f[i][j][k][0]=min(f[i][j][k][0],f[i][j][k][1]);
	}
	printf("%d\n",f[vv][kk][xx][0]);
	return 0;
}