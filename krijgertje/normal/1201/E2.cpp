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
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
#include <bitset>
#include <tuple>
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


struct P { int x,y; P() {} P(int x,int y):x(x),y(y) {} };
bool operator==(const P &a,const P &b) { return a.x==b.x&&a.y==b.y; }
bool operator!=(const P &a,const P &b) { return a.x!=b.x||a.y!=b.y; }
P operator-(const P &a,const P &b) { return P(a.x-b.x,a.y-b.y); }

int h,w;
P sw;
P sb;


P tw,tb;
vector<vector<int>> wdist; vector<vector<P>> wprv;
vector<vector<int>> bdist; vector<vector<P>> bprv;


pair<vector<vector<int>>,vector<vector<P>>> getdist(int h,int w,int tx,int ty) {
	vector<vector<int>> dist(h,vector<int>(w,-1)); queue<P> q; 
	vector<vector<P>> prv(h,vector<P>(w,P(-2,-2)));
	dist[tx][ty]=0,prv[tx][ty]=P(-1,-1),q.push(P(tx,ty));
	while(!q.empty()) {
		int x=q.front().x,y=q.front().y; q.pop();
		FORE(dx,-2,+2) FORE(dy,-2,+2) if(dx*dx+dy*dy==5) { int nx=x+dx,ny=y+dy; if(nx<0||nx>=h||ny<0||ny>=w||dist[nx][ny]!=-1) continue; dist[nx][ny]=dist[x][y]+1,prv[nx][ny]=P(x,y),q.push(P(nx,ny)); }
	}
	return MP(dist,prv);
}

void outputcol(int col) { printf("%s\n",col==0?"WHITE":"BLACK"); fflush(stdout); }
void outputmove(P p) { printf("%d %d\n",p.x+1,p.y+1); fflush(stdout); }
P inputmove() { int x,y; scanf("%d%d",&x,&y); if(x==-1&&y==-1) exit(0); --x,--y; return P(x,y); }

void movetomine(int col) {
	P c[2]; c[0]=sw,c[1]=sb; int turn=0;
	vector<vector<P>> myprv=col==0?wprv:bprv; P mydst=col==0?tw:tb;
	outputcol(col);
	while(c[col]!=mydst) {
		if(turn==col) {
			P at=c[col],to=myprv[at.x][at.y]; assert(to!=P(-1,-1));
			c[col]=to; outputmove(to);
			assert(c[col]!=c[1-col]);
		} else {
			c[turn]=inputmove();
			assert(c[col]!=c[1-col]);
		}
		turn=1-turn;
	}
}

void movetoopp(int col) {
	P c[2]; c[0]=sw,c[1]=sb; int turn=0;
	vector<vector<P>> oppprv=col==0?bprv:wprv,myprv=col==0?wprv:bprv; P mydst=col==0?tw:tb;
	outputcol(col);
	while(true) {
		if(turn==col) {
			P at=c[col],to=oppprv[at.x][at.y]; if(to==P(-1,-1)) break;
			c[col]=to; outputmove(to);
			if(c[col]==c[1-col]) return; // WON
		} else {
			c[turn]=inputmove();
			assert(c[col]!=c[1-col]);
		}
		turn=1-turn;
	}
	// my turn and on opponents square
	while(c[col]!=mydst) {
		if(turn==col) {
			P at=c[col];
			P dopp=c[1-col]-at; if(dopp.x*dopp.x+dopp.y*dopp.y==5) { outputmove(c[1-col]); return; } // WIN DIRECT
			P to=myprv[at.x][at.y]; assert(to!=P(-1,-1));
			c[col]=to; outputmove(to);
			if(c[col]==c[1-col]) return; // WON
		} else {
			c[turn]=inputmove();
			assert(c[col]!=c[1-col]);
		}
		turn=1-turn;
	}
}

void solve() {
	tw=P(h/2-1,w/2-1),tb=P(h/2,w/2-1);
	tie(wdist,wprv)=getdist(h,w,tw.x,tw.y);
	tie(bdist,bprv)=getdist(h,w,tb.x,tb.y);
	int swpar=(sw.x+sw.y)%2,sbpar=(sb.x+sb.y)%2;
	//printf("swpar=%d sbpar=%d\n",swpar,sbpar);
	if(swpar!=sbpar) { // white attacks
		if(bdist[sw.x][sw.y]<=bdist[sb.x][sb.y]+1) movetoopp(0); else if(bdist[sb.x][sb.y]<wdist[sw.x][sw.y]) movetomine(1); else movetomine(0);
	} else { // black attacks
		if(wdist[sb.x][sb.y]<=wdist[sw.x][sw.y]) movetoopp(1); else if(wdist[sw.x][sw.y]<=bdist[sb.x][sb.y]) movetomine(0); else movetomine(1);
	}
}


void run() {
	scanf("%d%d",&h,&w);
	scanf("%d%d%d%d",&sw.x,&sw.y,&sb.x,&sb.y); --sw.x,--sw.y,--sb.x,--sb.y;
	solve();
}


int main() {
	run();
	return 0;
}