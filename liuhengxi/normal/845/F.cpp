#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=255,M=16,MOD=1000000007;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int get()
{
	char c=getchar();
	while(c!='x'&&c!='.')c=getchar();
	return c=='x'?1:0;
}
int n,m,a[N][M],f[1<<M/*down*/][2/*right*/][2/*not protected*/],ans;
long long g[1<<M][2][2];
int main()
{
	read(n);read(m);
	if(n<m)
	{
		F(i,0,n)F(j,0,m)a[j][i]=get();
		n^=m^=n^=m;
	}
	else F(i,0,n)F(j,0,m)a[i][j]=get();
	f[0][0][0]=1;
	F(i,0,n)
	{
		F(j,0,m)
		{
			if(a[i][j]==0)
			F(d,0,1<<m)
			{
				int dd=(d&1<<j)^d;
				g[d][0][0]=d>>j&1?f[d][0][0]:0;
				g[d][0][1]=(d>>j&1?f[d][0][1]:0)+((d>>j&1)==0?f[d][0][0]:0);
				g[d][1][0]=f[d][1][0]+(dd!=d?(long long)f[d][1][0]+f[d][0][0]+
				f[dd][1][0]+f[dd][0][0]:0);
				g[d][1][1]=f[d][1][1]+(dd!=d?(long long)f[d][1][1]+f[d][0][1]+
				f[dd][1][1]+f[dd][0][1]:0);
			}
			else
			F(d,0,1<<m)
			{
				if(d>>j&1)g[d][0][0]=g[d][0][1]=g[d][1][0]=g[d][1][1]=0;
				else
				{
					int dd=d|1<<j;
					g[d][0][0]=f[d][0][0]+f[d][1][0];
					g[d][0][1]=f[d][0][1]+f[d][1][1];
					g[d][1][0]=0;
					g[d][1][1]=0;
					g[d][0][0]+=f[dd][0][0]+f[dd][1][0];
					g[d][0][1]+=f[dd][0][1]+f[dd][1][1];
				}
			}
			F(d,0,1<<m)
			{
				f[d][0][0]=g[d][0][0]%MOD;
				f[d][0][1]=g[d][0][1]%MOD;
				f[d][1][0]=g[d][1][0]%MOD;
				f[d][1][1]=g[d][1][1]%MOD;
			}
		}
		F(d,0,1<<m)
		{
			g[d][0][0]=f[d][0][0]+f[d][1][0];
			g[d][0][1]=f[d][0][1]+f[d][1][1];
			g[d][1][0]=0;
			g[d][1][1]=0;
		}
		F(d,0,1<<m)
		{
			f[d][0][0]=g[d][0][0]%MOD;
			f[d][0][1]=g[d][0][1]%MOD;
			f[d][1][0]=g[d][1][0]%MOD;
			f[d][1][1]=g[d][1][1]%MOD;
		}
	}
	F(d,0,1<<m)(ans+=f[d][0][0])%=MOD;
	F(d,0,1<<m)(ans+=f[d][0][1])%=MOD;
	F(d,0,1<<m)(ans+=f[d][1][0])%=MOD;
	F(d,0,1<<m)(ans+=f[d][1][1])%=MOD;
	printf("%d\n",ans);
	return 0;
}