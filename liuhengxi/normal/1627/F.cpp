#include<cstdio>
#include<algorithm>
#include<stack>
#include<utility>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=505,M=100005,dx[4]={1,0,-1,0},dy[4]={0,1,0,-1},INF=0x3fffffff;
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
int tt,n,m,w[N][N][4],d[N][N];
stack<pair<int,int> > s[M<<1];
int bfs()
{
	s[0].push({n>>1,n>>1});
	d[n>>1][n>>1]=0;
	for(int i=0;;)
	{
		while(s[i].empty())++i;
		int x=s[i].top().first,y=s[i].top().second;s[i].pop();
		if(x==0||y==0||x==n||y==n)
		{
			F(j,0,2*m+1)while(!s[j].empty())s[j].pop();
			return i;
		}
		if(i>d[x][y])continue;
		F(k,0,4)
		{
			int nx=x+dx[k],ny=y+dy[k];
			if(i+w[x][y][k]<d[nx][ny])
			{
				d[nx][ny]=i+w[x][y][k];
				s[d[nx][ny]].push({nx,ny});
			}
		}
	}
}
int main()
{
	read(tt);
	while(tt--)
	{
		read(m,n);
		F(i,0,n+1)F(j,0,n+1)w[i][j][0]=w[i][j][1]=w[i][j][2]=w[i][j][3]=0,d[i][j]=INF;
		F(i,0,m)
		{
			int x1,y1,x2,y2;--read(x1);--read(y1);--read(x2);--read(y2);
			if(x1>x2)swap(x1,x2);
			if(y1>y2)swap(y1,y2);
			if(x1==x2)
			{
				++w[x2][y2][0];
				++w[x2+1][y2][2];
				++w[n-x2][n-y2][2];
				++w[n-x2-1][n-y2][0];
			}
			else
			{
				++w[x2][y2][1];
				++w[x2][y2+1][3];
				++w[n-x2][n-y2][3];
				++w[n-x2][n-y2-1][1];
			}
		}
		printf("%d\n",m-bfs());
	}
	return 0;
}