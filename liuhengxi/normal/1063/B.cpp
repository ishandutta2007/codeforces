#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2010,INF=0x3fffffff,C[2][3]={{1,0,0},{0,0,1}};
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,m,r,c,x,y,qx[2*N*N],qy[2*N*N],qf=N*N,qr=N*N,d[N][N],ans;
char map[N][N+1];bool vis[N][N];
inline void pb(int x,int y){qx[qr]=x;qy[qr++]=y;}
inline void pf(int x,int y){qx[--qf]=x;qy[qf]=y;}
inline bool check(int x,int y,int dd)
{return 0<=x&&x<n&&0<=y&&y<m&&map[x][y]=='.'&&d[x][y]>dd
&&(d[x][y]=dd,true);}
int main()
{
	read(n);read(m);read(r);read(c);read(x);read(y);
	--r,--c;
	F(i,0,n)scanf("%s",map[i]);
	F(i,0,n)F(j,0,m)d[i][j]=INF;
	d[r][c]=0;
	pb(r,c);
	while(qf<qr)
	{
		int x=qx[qf],y=qy[qf++],z=y==c?1:(y<c?0:2);
		if(vis[x][y])continue;
		vis[x][y]=true;
		if(check(x+1,y,d[x][y]))pf(x+1,y);
		if(check(x-1,y,d[x][y]))pf(x-1,y);
		if(check(x,y+1,d[x][y]+C[0][z]))(C[0][z]?pb:pf)(x,y+1);
		if(check(x,y-1,d[x][y]+C[1][z]))(C[1][z]?pb:pf)(x,y-1);
	}
	F(i,0,n)F(j,0,m)
	{
		int a=d[i][j],b=d[i][j];
		if(j<c)a+=c-j;else b+=j-c;
		if(a<=x&&b<=y)++ans;
	}
	printf("%d\n",ans);
	return 0;
}