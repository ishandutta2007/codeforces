#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
using namespace std;  

#define PB push_back  
#define MP make_pair  
#define SZ(v) ((int)(v).size())  
#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
#define REPE(i,n) FORE(i,0,n)  
#define FORSZ(i,a,v) FOR(i,a,SZ(v))  
#define REPSZ(i,v) REP(i,SZ(v))  
typedef long long ll;
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

int h,w;
int s[30][30];
int t[30][30];

int ret[1000001][2],nret;

void up(int &x,int &y,int &xx,int &yy) { int nx=x-1,ny=y; ret[nret][0]=nx,ret[nret][1]=ny,++nret; swap(s[x][y],s[nx][ny]); if(nx==xx&&ny==yy) swap(x,xx),swap(y,yy); else x=nx,y=ny; }
void down(int &x,int &y,int &xx,int &yy) { int nx=x+1,ny=y; ret[nret][0]=nx,ret[nret][1]=ny,++nret; swap(s[x][y],s[nx][ny]); if(nx==xx&&ny==yy) swap(x,xx),swap(y,yy); else x=nx,y=ny; }
void left(int &x,int &y,int &xx,int &yy) { int nx=x,ny=y-1; ret[nret][0]=nx,ret[nret][1]=ny,++nret; swap(s[x][y],s[nx][ny]); if(nx==xx&&ny==yy) swap(x,xx),swap(y,yy); else x=nx,y=ny; }
void right(int &x,int &y,int &xx,int &yy) { int nx=x,ny=y+1; ret[nret][0]=nx,ret[nret][1]=ny,++nret; swap(s[x][y],s[nx][ny]); if(nx==xx&&ny==yy) swap(x,xx),swap(y,yy); else x=nx,y=ny; }
void dl(int &x,int &y,int &xx,int &yy) { int nx=x+1,ny=y-1; ret[nret][0]=nx,ret[nret][1]=ny,++nret; swap(s[x][y],s[nx][ny]); if(nx==xx&&ny==yy) swap(x,xx),swap(y,yy); else x=nx,y=ny; }
void dr(int &x,int &y,int &xx,int &yy) { int nx=x+1,ny=y+1; ret[nret][0]=nx,ret[nret][1]=ny,++nret; swap(s[x][y],s[nx][ny]); if(nx==xx&&ny==yy) swap(x,xx),swap(y,yy); else x=nx,y=ny; }
void ul(int &x,int &y,int &xx,int &yy) { int nx=x-1,ny=y-1; ret[nret][0]=nx,ret[nret][1]=ny,++nret; swap(s[x][y],s[nx][ny]); if(nx==xx&&ny==yy) swap(x,xx),swap(y,yy); else x=nx,y=ny; }
void ur(int &x,int &y,int &xx,int &yy) { int nx=x-1,ny=y+1; ret[nret][0]=nx,ret[nret][1]=ny,++nret; swap(s[x][y],s[nx][ny]); if(nx==xx&&ny==yy) swap(x,xx),swap(y,yy); else x=nx,y=ny; }
void pushdleft(int &x,int &y,int &xx,int &yy) { assert(x==xx-1&&y==yy); dl(x,y,xx,yy); right(x,y,xx,yy); up(x,y,xx,yy); }
void pushdright(int &x,int &y,int &xx,int &yy) { assert(x==xx-1&&y==yy); dr(x,y,xx,yy); left(x,y,xx,yy); up(x,y,xx,yy); }
void pushuright(int &x,int &y,int &xx,int &yy) { assert(x==xx+1&&y==yy); ur(x,y,xx,yy); left(x,y,xx,yy); down(x,y,xx,yy); }
void pushldown(int &x,int &y,int &xx,int &yy) { assert(x==xx&&y==yy+1); dl(x,y,xx,yy); up(x,y,xx,yy); right(x,y,xx,yy); }
void pushrdown(int &x,int &y,int &xx,int &yy) { assert(x==xx&&y==yy-1); dr(x,y,xx,yy); up(x,y,xx,yy); left(x,y,xx,yy); }
void pushrup(int &x,int &y,int &xx,int &yy) { assert(x==xx&&y==yy-1); ur(x,y,xx,yy); down(x,y,xx,yy); left(x,y,xx,yy); }

void print() {
//	REP(i,nret) printf("(%d,%d)",ret[i][0],ret[i][1]); puts("");
	REP(i,h) { REP(j,w) printf("%2d ",s[i][j]); puts(""); } puts("");
}

void greedy() {
	int x=-1,y=-1; REP(i,h) REP(j,w) if(s[i][j]==t[0][0]&&x==-1&&y==-1) x=i,y=j; if(x==-1||y==-1) return;
	ret[nret][0]=x,ret[nret][1]=y,++nret;
	for(int tx=h-1;tx>=2;--tx) REP(ty,w) {
		int sx=-1,sy=-1; REPE(i,tx) FOR(j,i<tx?0:ty,w) if(s[i][j]==t[tx][ty]&&sx==-1&&sy==-1&&(i!=x||j!=y)) sx=i,sy=j; if(sx==-1||sy==-1) return;
//		printf("(%d,%d): (%d,%d)->(%d,%d)\n",x,y,sx,sy,tx,ty); print();
		if(x==tx) up(x,y,sx,sy);
		while(y<sy-1||y<sy&&x!=sx) right(x,y,sx,sy);
		while(y>sy+1||y>sy&&x!=sx) left(x,y,sx,sy);
		if(y!=sy) { if(x==0) down(x,y,sx,sy); else up(x,y,sx,sy); if(y<sy) right(x,y,sx,sy); else left(x,y,sx,sy); }
		while(x<sx-1) down(x,y,sx,sy);
		while(x>sx) up(x,y,sx,sy);
		while(sy<ty) { pushdright(x,y,sx,sy); right(x,y,sx,sy); }
		while(sy>ty) { pushdleft(x,y,sx,sy); left(x,y,sx,sy); }
		if(y==0) right(x,y,sx,sy); else left(x,y,sx,sy);
		while(sx<tx) { down(x,y,sx,sy); if(y<sy) pushrdown(x,y,sx,sy); else pushldown(x,y,sx,sy); }
	}
	for(int ty=w-1;ty>=2;--ty) REP(tx,2) {
		int sx=-1,sy=-1; REPE(j,ty) FOR(i,j<ty?0:tx,2) if(s[i][j]==t[tx][ty]&&sx==-1&&sy==-1&&(i!=x||j!=y)) sx=i,sy=j; if(sx==-1||sy==-1) return;
//		printf("(%d,%d): (%d,%d)->(%d,%d)\n",x,y,sx,sy,tx,ty); print();
		if(y==ty) left(x,y,sx,sy);
		while(x<sx&&y!=sy) down(x,y,sx,sy);
		while(x>sx&&y!=sy) up(x,y,sx,sy);
		if(x!=sx) { if(y==0) right(x,y,sx,sy); else left(x,y,sx,sy); if(x<sx) down(x,y,sx,sy); else up(x,y,sx,sy); }
		while(y<sy-1) right(x,y,sx,sy);
		while(y>sy) left(x,y,sx,sy);
		while(sx<tx) { pushrdown(x,y,sx,sy); down(x,y,sx,sy); }
		while(sx>tx) { pushrup(x,y,sx,sy); up(x,y,sx,sy); }
		if(x==0) down(x,y,sx,sy); else up(x,y,sx,sy);
		while(sy<ty) { right(x,y,sx,sy); if(x<sx) pushdright(x,y,sx,sy); else pushuright(x,y,sx,sy); }
	}
	{
		int sx=-1,sy=-1;
		while(x>0) up(x,y,sx,sy);
		while(y>0) left(x,y,sx,sy);
		if(s[0][1]==t[1][1]) sx=0,sy=1,pushrdown(x,y,sx,sy);
		else if(s[1][0]==t[1][1]) sx=1,sy=0,pushdright(x,y,sx,sy);
		else if(s[1][1]!=t[1][1]) return;
		if(s[1][0]==t[0][1]) { sx=1,sy=0; right(x,y,sx,sy); dl(x,y,sx,sy); up(x,y,sx,sy); }
		else if(s[0][1]!=t[0][1]) return;
	}
}

void line(int dx,int dy) {
	int lx=0,ly=0; while(lx<h&&ly<w&&s[lx][ly]==t[lx][ly]) lx+=dx,ly+=dy; if(lx>=h||ly>=w) return;
	int hx=h-1,hy=w-1; while(hx>=0&&hy>=0&&s[hx][hy]==t[hx][hy]) hx-=dx,hy-=dy; if(hx<0||hy<0) return;
	bool back=true; for(int x=lx,y=ly;x+dx<=hx&&y+dy<=hy;x+=dx,y+=dy) if(s[x][y]!=t[x+dx][y+dy]) back=false;
	int cnt=hx-lx+hy-ly;
	ret[nret][0]=!back?lx:hx,ret[nret][1]=!back?ly:hy,++nret;
	if(!back) REP(i,cnt) if(dx==0) right(lx,ly,hx,hy); else down(lx,ly,hx,hy);
	else REP(i,cnt) if(dx==0) left(hx,hy,lx,ly); else up(hx,hy,lx,ly);
}

int p[900];

void run() {
	scanf("%d%d",&h,&w);
	REP(i,h) REP(j,w) scanf("%d",&s[i][j]);
	REP(i,h) REP(j,w) scanf("%d",&t[i][j]);
	nret=0;
	//h=30,w=30; REP(i,h*w) p[i]=i; REP(i,h*w) { int j=i+rand()%(h*w-i); swap(p[i],p[j]); } REP(i,h) REP(j,w) s[i][j]=p[i*w+j],t[i][j]=i*w+j;
	//print();
	if(h==1) {
		line(0,+1);
	} else if(w==1) {
		line(+1,0);
	} else {
		greedy();
	}
	//print();
	bool ok=true; REP(i,h) REP(j,w) if(s[i][j]!=t[i][j]) ok=false; if(!ok) { printf("-1\n"); return; }
	printf("%d\n",nret-1);
	REP(i,nret) printf("%d %d\n",ret[i][0]+1,ret[i][1]+1);
}

int main() {
	run();
	return 0;
}