#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define X(a) ((a)/m)
#define Y(a) ((a)%m)
using namespace std;
const int N=1005,dx[4]={1,0,-1,0},dy[4]={0,1,0,-1},INF=0x3fffffff;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,m,k,dis[N][N],nex[N][N][4],x1,y1,x2,y2,q[N*N];
bool vis[N][N];
char map[N][N];
inline int A(int x,int y){return x<0||x>=n||y<0||y>=m||
map[x][y]=='#'?-1:x*m+y;}
int find(int a,int b)
{
	return (a==-1)||nex[X(a)][Y(a)][b]==a?a:
	nex[X(a)][Y(a)][b]=find(nex[X(a)][Y(a)][b],b);
}
int main()
{
	read(n);read(m);read(k);
	F(i,0,n)scanf("%s",map[i]);
	F(i,0,n)F(j,0,m)F(p,0,4)nex[i][j][p]=A(i,j);
	read(x1);read(y1);read(x2);read(y2);
	--x1,--y1,--x2,--y2;
	q[0]=A(x1,y1);
	vis[x1][y1]=true;
	F(pp,0,4)nex[x1][y1][pp]=A(x1+dx[pp],y1+dy[pp]);
	for(int i=0,j=1;i<j;++i)
	{
		int x=X(q[i]),y=Y(q[i]);
		F(p,0,4)
		{
			int a=find(q[i],p);
			while(~a)
			{
				if(X(a)-x<-k||X(a)-x>k||Y(a)-y<-k||Y(a)-y>k)break;
				vis[X(a)][Y(a)]=true;dis[X(a)][Y(a)]=dis[x][y]+1;
				q[j++]=a;
				F(pp,0,4)nex[X(a)][Y(a)][pp]=A(X(a)+dx[pp],Y(a)+dy[pp]);
				a=find(a,p);
			}
		}
	}
	if(!vis[x2][y2])puts("-1");
	else printf("%d\n",dis[x2][y2]);
	return 0;
}