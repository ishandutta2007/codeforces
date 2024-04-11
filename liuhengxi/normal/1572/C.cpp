#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=3e3+5,INF=0x3fffffff;
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
int tt,n,a[N],f[N][N],nex[N],las[N];
int main()
{
	for(read(tt);tt--;)
	{
		F(i,0,read(n))--read(a[i]);
		F(i,0,n)las[i]=-1;
		for(int i=n;~--i;)nex[i]=las[a[i]],las[a[i]]=i;
		F(i,0,n+1)F(j,0,n+1)f[i][j]=INF;
		F(i,0,n)f[i][i+1]=0;
		F(len,2,n+1)F(l,0,n-len+1)
		{
			int r=l+len;
			f[l][r]=f[l+1][r]+1;
			for(int i=l;~i;i=nex[i])f[l][r]=min(f[l][r],f[l][i]+f[i][r]);
		}
		printf("%d\n",f[0][n]);
	}
	return 0;
}