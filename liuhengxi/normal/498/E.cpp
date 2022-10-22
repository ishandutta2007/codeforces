#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=(1<<7)+5,MOD=1000000007;
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
int w,ans[N],f[N][N],g[N][N];
int main()
{
	ans[0]=1;
	F(h,1,8)
	{
		int n=1<<h,full=n-1;
		F(i,0,n)F(j,0,n)f[i][j]=0;
		F(i,0,n)F(j,0,n)F(k,0,n>>1)if((i|j|k|k<<1)==full)++f[i][j];
		read(w);
		while(w)
		{
			if(w&1)
			{
				F(i,0,n)g[0][i]=0;
				F(i,0,n)F(j,0,n)g[0][j]=(int)(((long long)ans[i]*f[i][j]+g[0][j])%MOD);
				F(i,0,n)ans[i]=g[0][i];
			}
			F(i,0,n)F(j,0,n)g[i][j]=0;
			F(i,0,n)F(k,0,n)F(j,0,n)g[i][j]=(int)(((long long)f[i][k]*f[k][j]+g[i][j])%MOD);
			F(i,0,n)F(j,0,n)f[i][j]=g[i][j];
			w>>=1;
		}
	}
	printf("%d\n",ans[0]);
	return 0;
}