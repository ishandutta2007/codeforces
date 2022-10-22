#include<cstdio>
#include<algorithm>
#include<utility>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=55,dx[4]={1,0,-1,0},dy[4]={0,1,0,-1},INF=0x3fffffff;
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
int n,m,ans=INF,dis[N][N],qf,qr;
pair<int,int> q[2*N*N];
char s[N][N];
int bfs(int sx,int sy)
{
	int res=-1;
	F(i,0,n)F(j,0,m)dis[i][j]=-1;
	dis[sx][sy]=0;
	qf=qr=N*N;
	q[qr++]={sx,sy};
	while(qf<qr)
	{
		int x=q[qf].first,y=q[qf].second;++qf;
		F(k,0,4)
		{
			int nx=x+dx[k],ny=y+dy[k];
			if(nx<0||ny<0||nx>=n||ny>=m||~dis[nx][ny])continue;
			(s[nx][ny]==s[x][y]?q[--qf]:q[qr++])={nx,ny};
			dis[nx][ny]=dis[x][y]+(s[nx][ny]!=s[x][y]);
		}
	}
	F(i,0,n)F(j,0,m)if(s[i][j]=='B')res=max(res,dis[i][j]);
	return res;
}
int main()
{
	read(n,m);
	F(i,0,n)scanf("%s",s[i]);
	F(i,0,n)F(j,0,m)ans=min(ans,bfs(i,j)+1);
	printf("%d\n",ans);
	return 0;
}