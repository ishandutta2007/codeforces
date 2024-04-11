#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <climits>
#include <cassert>
#include <ctime>
#include <cstring>
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

int DX[]={-1,0,+1,0},DY[]={0,+1,0,-1}; char DC[]={'L','U','R','D'};

int mx,my,gx,gy;
bool g[203][203];
int lx,ly,hx,hy;

int mark[203][203];
int d[203][203];
int prv[203][203];

int nans;
char ans[1000001];

void move(int k, bool ghostmustmove) {
	int nmx=mx+DX[k],nmy=my+DY[k];
	if(nmx>=0&&nmx<203&&nmy>=0&&nmy<203&&g[nmx][nmy]) { assert(false); }
	if(gx==mx&&gy==my) return;
	if(nans<1000000) { ans[nans++]=DC[k]; ans[nans]='\0'; }
	mx=nmx; my=nmy;
	int ngx=gx+DX[k],ngy=gy+DY[k];
	if(ngx>=0&&ngx<203&&ngy>=0&&ngy<203&&g[ngx][ngy]) assert(!ghostmustmove); else { gx=ngx; gy=ngy; }
//	printf("%c (%d,%d) (%d,%d)\n",DC[k],mx,my,gx,gy);
}
void left(bool x) { move(0,x); } void rght(bool x) { move(2,x); } void upup(bool x) { move(1,x); } void down(bool x) { move(3,x); }

void run(int casenr) {
	int n; scanf("%d%d%d%d%d",&mx,&my,&gx,&gy,&n); mx+=101; my+=101; gx+=101; gy+=101;
	memset(g,false,sizeof(g));
	REP(i,n) { int x,y; scanf("%d%d",&x,&y); x+=101; y+=101; g[x][y]=true; }

	nans=0;

	if(n==0) { printf("-1\n"); return; }
	lx=INT_MAX,hx=INT_MIN,ly=INT_MAX,hy=INT_MIN;
	REP(x,203) REP(y,203) if(g[x][y]) { if(x<lx) lx=x; if(x>hx) hx=x; if(y<ly) ly=y; if(y>hy) hy=y; }
	
//	for(int y=max(gy,hy);y>=min(gy,ly);--y) { FORE(x,min(gx,lx),max(gx,hx)) printf("%c",g[x][y]?'#':x==mx&&y==my?'M':x==gx&&y==gy?'G':'.'); puts(""); }

	int curmark=0; memset(mark,0,sizeof(mark));
	while(lx<=mx&&mx<=hx&&ly<=my&&my<=hy || lx<=gx&&gx<=hx&&ly<=gy&&gy<=hy) {
		if(mx==gx&&my==gy) { printf("%s\n",ans); return; }
		if(mx<lx-1) { rght(false); continue; }
		if(mx>hx+1) { left(false); continue; }
		if(my<ly-1) { upup(false); continue; }
		if(my>hy+1) { down(false); continue; }
//		printf("here\n");

		int sx=gx<lx?lx-1:gx>hx?hx+1:gx, sy=gy<ly?ly-1:gy>hy?hy+1:gy; //printf("%d %d [%d %d] [%d %d] -> %d %d\n",sx,sy,lx,hx,ly,hy,mx,my);
		queue<pair<int,int> > q;
		d[sx][sy]=0; mark[sx][sy]=curmark++; prv[sx][sy]=-1; q.push(MP(sx,sy));
		while(!q.empty()) {
			int x=q.front().first,y=q.front().second; q.pop();
//			printf("(%d,%d)\n",x,y);
			if(x==mx&&y==my) break;
			REP(k,4) {
				int nx=x+DX[k],ny=y+DY[k]; if(nx<lx-1||nx>hx+1||ny<ly-1||ny>hy+1||g[nx][ny]) continue;
				if(mark[nx][ny]==curmark) continue;
//				printf("\t->(%d,%d)\n",nx,ny);
				d[nx][ny]=d[x][y]+1; mark[nx][ny]=curmark; prv[nx][ny]=k^2; q.push(MP(nx,ny));
			}
		}
		if(mark[mx][my]!=curmark) { printf("-1\n"); return; }
		move(prv[mx][my],false);
	}
	assert(nans<1000000);
//	printf("outside\n");

	if(mx<gx) {
		while(gx>=lx) { if(mx>=lx&&ly<=my&&my<=hy || ly<=gy&&gy<=hy) { if(my<ly) down(true); else upup(true); } else left(true); }
		int ty=my>=gy?hy:ly;
		while(gy!=ty) { if(gy<ty) upup(true); else down(true); }
		while(gx!=mx) { rght(false); }
		if(gy==ly) down(true); else upup(true);
	}
	if(mx>gx) {
		while(gx<=hx) { if(mx<=hx&&ly<=my&&my<=hy || ly<=gy&&gy<=hy) { if(my<ly) down(false); else upup(false); } else rght(false); }
		int ty=my>=gy?hy:ly;
		while(gy!=ty) { if(gy<ty) upup(false); else down(false); }
		while(gx!=mx) left(false);
		if(gy==ly) down(false); else upup(false);
	}
	if(my<gy) {
		while(gy>=ly) { if(my>=ly&&lx<=mx&&mx<=hx || lx<=gx&&gx<=hx) { if(mx<lx) left(false); else rght(false); } else down(false); }
		int tx=mx>=gx?hx:lx;
		while(gx!=tx) { if(gx<tx) rght(false); else left(false); }
		while(gy!=my) upup(false);
		if(gx==lx) left(false); else rght(false);
	}
	if(my>gy) {
		while(gy<=hy) { if(my<=hy&&lx<=mx&&mx<=hx || lx<=gx&&gx<=hx) { if(mx<lx) left(false); else rght(false); } else upup(false); }
		int tx=mx>=gx?hx:lx;
		while(gx!=tx) { if(gx<tx) rght(false); else left(false); }
		while(gy!=my) down(false);
		if(gx==lx) left(false); else rght(false);
	}

//	assert(gx==mx&&gy==my); 
	printf("%s\n",ans);
}


int main() {
//	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}