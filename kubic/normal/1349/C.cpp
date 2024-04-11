#include <bits/stdc++.h>
using namespace std;
#define N 1005
#define INF 1e9
#define ll long long
#define set(a,v) memset(a,v,sizeof(a))
int X[]={1,-1,0,0},Y[]={0,0,1,-1};
int n,m,c,lim,dst0[N][N],dst1[N][N];bool vs[N][N];char a[N][N];
struct Node {int x,y;};queue<Node> q; 
bool chk(int x,int y)
{
	return a[x][y]==a[x-1][y] || a[x][y]==a[x+1][y] || 
		   a[x][y]==a[x][y-1] || a[x][y]==a[x][y+1];
} 
void bfs0()
{
	set(vs,0);set(dst0,-1);
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) if(a[i][j]=='0' && chk(i,j))
		q.push((Node) {i,j}),vs[i][j]=1,dst0[i][j]=0;
	while(!q.empty())
	{
		Node t=q.front();int x=t.x,y=t.y;q.pop();
		for(int i=0,gX,gY;i<4;++i)
		{
			gX=x+X[i];gY=y+Y[i];
			if(gX>0 && gX<=n && gY>0 && gY<=m && !vs[gX][gY])
				vs[gX][gY]=1,dst0[gX][gY]=dst0[x][y]+1,q.push((Node) {gX,gY});
		}
	}
} 
void bfs1()
{
	set(vs,0);set(dst1,-1);
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) if(a[i][j]=='1' && chk(i,j))
		q.push((Node) {i,j}),vs[i][j]=1,dst1[i][j]=0;
	while(!q.empty())
	{
		Node t=q.front();int x=t.x,y=t.y;q.pop();
		for(int i=0,gX,gY;i<4;++i)
		{
			gX=x+X[i];gY=y+Y[i];
			if(gX>0 && gX<=n && gY>0 && gY<=m && !vs[gX][gY])
				vs[gX][gY]=1,dst1[gX][gY]=dst1[x][y]+1,q.push((Node) {gX,gY});
		}
	}
} 
int main()
{
	scanf("%d %d %d",&n,&m,&c);lim=max(n,m);for(int i=1;i<=n;++i) scanf("%s",a[i]+1);
	bfs0();bfs1();
	for(int i=1,x,y,t0,t1,t;i<=c;++i)
	{
		ll q;scanf("%d %d %lld",&x,&y,&q);t0=dst0[x][y];t1=dst1[x][y];
		if(a[x][y]=='0') {if(~t0 && t0&1) ++t0;if(~t1 && !(t1&1)) ++t1;}
		else {if(~t0 && !(t0&1)) ++t0;if(~t1 && t1&1) ++t1;}
		if(~t0 && ~t1) t=min(t0,t1);else if(~t0) t=t0;else t=t1;
		if(t==-1 || q<t) printf("%c\n",a[x][y]);
		else {q-=t;if(a[x][y]=='0') puts(q&1?"1":"0");else puts(q&1?"0":"1");}
	}return 0;
}