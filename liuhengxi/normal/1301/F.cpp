#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1005,INF=0x3f3f3f3f;
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
int n,m,k,a[N][N],d[45][N][N],dc[45],q[2*N*N],qf,qr;
vector<int> c[N];
void bfs(int dis[N][N])
{
	while(qf<qr)
	{
		int u=q[qf++];
		if(u<0)
		{
			u=-u-1;
			for(int v:c[u])
			{
				int vx=v/m,vy=v%m;
				if(dis[vx][vy]>dc[u])
				{
					dis[vx][vy]=dc[u];
					q[--qf]=v;
				}
			}
		}
		else
		{
			int x=u/m,y=u%m;
			if(dc[a[x][y]]>dis[x][y]+1)dc[a[x][y]]=dis[x][y]+1,q[qr++]=-a[x][y]-1;
			if(x>0&&dis[x-1][y]>dis[x][y]+1)dis[x-1][y]=dis[x][y]+1,q[qr++]=u-m;
			if(x<n-1&&dis[x+1][y]>dis[x][y]+1)dis[x+1][y]=dis[x][y]+1,q[qr++]=u+m;
			if(y>0&&dis[x][y-1]>dis[x][y]+1)dis[x][y-1]=dis[x][y]+1,q[qr++]=u-1;
			if(y<m-1&&dis[x][y+1]>dis[x][y]+1)dis[x][y+1]=dis[x][y]+1,q[qr++]=u+1;
		}
	}
}
int main()
{
	memset(d,0x3f,sizeof d);
	read(n,m,k);
	F(i,0,n)F(j,0,m)c[--read(a[i][j])].emplace_back(i*m+j);
	F(i,0,k)
	{
		qf=qr=N*N;
		F(j,0,k)dc[j]=INF;
		dc[i]=0;
		q[qr++]=-i-1;
		bfs(d[i]);
	}
	int qq;read(qq);
	while(qq--)
	{
		int x1,y1,x2,y2,ans;
		read(x1,y1,x2,y2);--x1,--y1,--x2,--y2;
		ans=abs(x1-x2)+abs(y1-y2);
		F(i,0,k)ans=min(ans,d[i][x1][y1]+d[i][x2][y2]+1);
		printf("%d\n",ans);
	}
	return 0;
}