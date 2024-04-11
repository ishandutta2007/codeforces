#include<cstdio>
#include<cstring>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=20;
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
int n,a,b,h[N],f[N][N][N][N],pp[N][N][N][N],px[N][N][N][N],py[N][N][N][N],pz[N][N][N][N];
int main()
{
	memset(f,0x3f,sizeof f);
	read(n,a,b);
	F(i,0,n)++read(h[i]);
	f[0][h[0]][h[1]][h[2]]=0;
	F(i,0,n-2)
	{
		for(int x=16;~x;--x)for(int y=16;~y;--y)for(int z=16;~z;--z)
		{
			if(f[i][x][y][z]+1<f[i][max(x-b,0)][max(y-a,0)][max(z-b,0)])
			{
				f[i][max(x-b,0)][max(y-a,0)][max(z-b,0)]=f[i][x][y][z]+1;
				pp[i][max(x-b,0)][max(y-a,0)][max(z-b,0)]=i;
				px[i][max(x-b,0)][max(y-a,0)][max(z-b,0)]=x;
				py[i][max(x-b,0)][max(y-a,0)][max(z-b,0)]=y;
				pz[i][max(x-b,0)][max(y-a,0)][max(z-b,0)]=z;
			}
			if(x==0)
			{
				if(f[i+1][y][z][h[i+3]]>f[i][x][y][z])
				{
					f[i+1][y][z][h[i+3]]=f[i][x][y][z];
					pp[i+1][y][z][h[i+3]]=i;
					px[i+1][y][z][h[i+3]]=x;
					py[i+1][y][z][h[i+3]]=y;
					pz[i+1][y][z][h[i+3]]=z;
				}
			}
		}
	}
	printf("%d\n",f[n-2][0][0][0]);
	for(int i=n-2,x=0,y=0,z=0;f[i][x][y][z];)
	{
		int ni=pp[i][x][y][z];
		int nx=px[i][x][y][z];
		int ny=py[i][x][y][z];
		int nz=pz[i][x][y][z];
		if(i==ni)printf("%d ",i+2);
		i=ni;x=nx;y=ny;z=nz;
	}
	puts("");
	return 0;
}