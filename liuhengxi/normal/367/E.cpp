#include<cstdio>
#include<cstring>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=4e2+5,MOD=1000000007;
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
void reduce(int &x){(x>=MOD)&&(x-=MOD);}
int n,m,x,f[N][N],g[N][N],ans;
int main()
{
	read(n,m,x);--x;
	if(n>m)return puts("0"),0;
	f[0][0]=1;
	F(i,0,m)
	{
		if(i==x)
		{
			for(int j=n;~j;--j)for(int k=n;~k;--k)
			{
				reduce(g[j+1][k]+=f[j][k]);
				reduce(g[j+1][k+1]+=f[j][k]);
			}
			memcpy(f,g,sizeof f);
		}
		else
		{
			for(int j=n;~j;--j)for(int k=n;~k;--k)
			{
				reduce(f[j+1][k]+=f[j][k]);
				if(k<j)reduce(f[j][k+1]+=f[j][k]);
				reduce(f[j+1][k+1]+=f[j][k]);
			}
		}
	}
	ans=f[n][n];
	F(i,1,n+1)ans=(int)((long long)ans*i%MOD);
	printf("%d\n",ans);
	return 0;
}