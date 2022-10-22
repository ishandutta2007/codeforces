#include <bits/stdc++.h>
using namespace std;
#define N 305
#define Q 2000005
#define set(a,v) memset(a,v,sizeof(a))
const int X[]={1,-1,0,0},Y[]={0,0,1,-1};
int n,m,q,lim,ans[Q],fa[N*N],nw[N][N];struct Query {int id,x,y;};
vector<Query> q1[Q],q2[Q];
int f(int x,int y) {return (x-1)*m+y;}
bool chk(int x,int y) {return x>0 && x<=n && y>0 && y<=m;}
void clear(int n) {for(int i=1;i<=n;++i) fa[i]=i;}
int rt(int x) {return x==fa[x]?x:fa[x]=rt(fa[x]);}
bool merge(int x,int y) {x=rt(x);y=rt(y);if(x==y) return 0;fa[x]=y;return 1;}
int main()
{
	scanf("%d %d %d",&n,&m,&q);
	for(int i=1,x,y,c;i<=q;++i)
	{
		scanf("%d %d %d",&x,&y,&c);lim=c;
		q2[nw[x][y]].push_back((Query) {i,x,y});
		q1[nw[x][y]=c].push_back((Query) {i,x,y});
	}
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j)
		q2[nw[i][j]].push_back((Query) {0,i,j});set(nw,-1);
	for(int i=0,sz,id,x,y;i<=lim;++i)
	{
		sz=q1[i].size();if(!sz) continue;clear(n*m);
		for(int j=0;j<sz;++j)
		{
			id=q1[i][j].id;x=q1[i][j].x;y=q1[i][j].y;nw[x][y]=i;++ans[id];
			for(int k=0,gX,gY;k<4;++k)
			{
				gX=x+X[k];gY=y+Y[k];
				if(chk(gX,gY) && nw[gX][gY]==i) ans[id]-=merge(f(x,y),f(gX,gY));
			}
		}
	}set(nw,-1);
	for(int i=0,sz,x,y,id;i<=lim;++i)
	{
		sz=q2[i].size();if(!sz) continue;clear(n*m);
		for(int j=sz-1;j>=0;--j)
		{
			x=q2[i][j].x;y=q2[i][j].y;id=q2[i][j].id;nw[x][y]=i;--ans[id];
			for(int k=0,gX,gY;k<4;++k)
			{
				gX=x+X[k];gY=y+Y[k];
				if(chk(gX,gY) && nw[gX][gY]==i) ans[id]+=merge(f(x,y),f(gX,gY));
			}
		}
	}ans[0]=1;for(int i=1;i<=q;++i) printf("%d\n",ans[i]+=ans[i-1]);return 0;
}