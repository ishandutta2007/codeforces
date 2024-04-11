#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
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
constexpr int N=105,M=10005;
int n,x,m;
double f[N][M],C[N][N],ans;
int main()
{
	F(i,0,N)C[i][0]=1.0;
	F(i,1,N)F(j,1,i+1)C[i][j]=C[i-1][j]+C[i-1][j-1];
	read(n,x);
	f[0][0]=1.0;
	F(i,0,n)
	{
		int c;read(c);
		for(int j=i;~j;--j)F(k,0,m+1)f[j+1][k+c]+=f[j][k];
		m+=c;
	}
	F(i,0,n)F(j,0,m+1)
	{
		double p=f[i][j]/C[n][i];
		ans+=p*min((1.0+(double)n/(n-i))*x/2.0,(double)(m-j)/(n-i));
	}
	printf("%.17lf\n",ans);
	return 0;
}