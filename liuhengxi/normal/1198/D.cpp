#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=55;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,f[N][N][N][N];
char s[N][N];
int main()
{
	read(n);
	F(i,0,n)scanf("%s",s[i]);
	F(x,0,n)F(y,0,n)f[x][y][x+1][y+1]=s[x][y]=='#';
	F(lx,1,n+1)F(ly,1,n+1)if(lx!=1||ly!=1)F(x1,0,n-lx+1)F(y1,0,n-ly+1)
	{
		int x2=x1+lx,y2=y1+ly;
		f[x1][y1][x2][y2]=max(lx,ly);
		F(k,x1+1,x2)f[x1][y1][x2][y2]=min(f[x1][y1][x2][y2],f[x1][y1][k][y2]+f[k][y1][x2][y2]);
		F(k,y1+1,y2)f[x1][y1][x2][y2]=min(f[x1][y1][x2][y2],f[x1][y1][x2][k]+f[x1][k][x2][y2]);
	}
	printf("%d\n",f[0][0][n][n]);
	return 0;
}