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

const int MAXFLAT=150000;
const int MAXCELL=9*MAXFLAT;
const int DX[]={-1,-1,-1,0,+1,+1,+1,0},DY[]={-1,0,+1,+1,+1,0,-1,-1};
struct P { int x,y; P() {} P(int x,int y):x(x),y(y) {} };
bool operator<(const P &a,const P &b) { if(a.x!=b.x) return a.x<b.x; return a.y<b.y; }
bool operator==(const P &a,const P &b) { return a.x==b.x&&a.y==b.y; }

int nflat,subtask;
P flat[MAXFLAT];
int ans[MAXFLAT];

P cell[MAXCELL]; int ncell;
vector<int> adj8[MAXCELL],adj4[MAXCELL];
int flatid[MAXCELL],cellid[MAXFLAT];

int comp[MAXCELL],ncomp; // 8-connected components of empty cells
int outsidecomp;
vector<int> cells[MAXCELL];

int q[MAXCELL],qhead,qtail;

bool isreachable[MAXFLAT],isarticulation[MAXFLAT],isavailable[MAXFLAT];
set<int> available;

void recalc(int fid) {
	//printf("recalc(%d)\n",fid);
	int at=cellid[fid];
	isreachable[fid]=false; REPSZ(i,adj4[at]) { int to=adj4[at][i]; if(comp[to]==outsidecomp) isreachable[fid]=true; }
	isarticulation[fid]=false;
	REPSZ(i,adj8[at]) {
		int fst=adj8[at][i]; if(comp[fst]!=-1) continue;
		int last=-1; bool added=false; vector<int> seen; REPSZ(j,adj8[at]) { int to=adj8[at][(i+j+1)%SZ(adj8[at])]; if(last!=comp[to]) last=comp[to],added=false; if((i+j+1)%2==1&&!added&&last!=-1) seen.PB(last),added=true; }
		//printf("seen:"); REPSZ(j,seen) printf(" %d",seen[j]); puts("");
		REPSZ(j,seen) FORSZ(k,j+1,seen) if(seen[j]==seen[k]) isarticulation[fid]=true;
		break;
	}
	//printf("recalc(%d) -> %s %s\n",fid,isreachable[fid]?"reachable":"no",isarticulation[fid]?"articulation":"ok");
	if((isreachable[fid]&&!isarticulation[fid])!=isavailable[fid]) { isavailable[fid]=!isavailable[fid]; if(isavailable[fid]) available.insert(fid); else available.erase(fid); }
}

void mergecomp(int a,int b) {
	if(SZ(cells[a])<SZ(cells[b])) swap(a,b);
	if(b==outsidecomp) swap(a,b);
	REPSZ(i,cells[b]) { int at=cells[b][i]; comp[at]=a; cells[a].PB(at); }
	REPSZ(i,cells[b]) { int at=cells[b][i]; REPSZ(j,adj8[at]) { int to=adj8[at][j]; if(comp[to]!=-1) continue; assert(flatid[to]!=-1); recalc(flatid[to]); } }
	cells[b].clear();
}

bool solve() {
	ncell=0; REP(i,nflat) FORE(dx,-1,+1) FORE(dy,-1,+1) cell[ncell++]=P(flat[i].x+dx,flat[i].y+dy);
	sort(cell,cell+ncell); ncell=unique(cell,cell+ncell)-cell;
	//printf("cell:"); REP(i,ncell) printf(" (%d,%d)",cell[i].x,cell[i].y); puts("");
	
	REP(i,ncell) { adj4[i].clear(),adj8[i].clear(); REP(k,8) { P pj=P(cell[i].x+DX[k],cell[i].y+DY[k]); int j=lower_bound(cell,cell+ncell,pj)-cell; if(j>=ncell||!(cell[j]==pj)) continue; adj8[i].PB(j); if(DX[k]==0||DY[k]==0) adj4[i].PB(j); } }
	//REP(i,ncell) { printf("adj4[%d]:",i); REPSZ(j,adj4[i]) printf(" %d",adj4[i][j]); puts(""); }
	//REP(i,ncell) { printf("adj8[%d]:",i); REPSZ(j,adj8[i]) printf(" %d",adj8[i][j]); puts(""); }
	
	REP(i,ncell) flatid[i]=-1; REP(i,nflat) cellid[i]=lower_bound(cell,cell+ncell,flat[i])-cell,flatid[cellid[i]]=i;
	ncomp=0; REP(i,ncell) comp[i]=flatid[i]==-1?-1:-2;
	REP(i,ncell) if(comp[i]==-2) { comp[i]=ncomp++; qhead=qtail=0; q[qhead++]=i; while(qtail<qhead) { int at=q[qtail++]; REPSZ(j,adj8[at]) { int to=adj8[at][j]; if(comp[to]==-2) comp[to]=comp[at],q[qhead++]=to; } } }
	if(ncomp>=2) return false;
	ncomp=0; REP(i,ncell) comp[i]=flatid[i]==-1?-2:-1;
	REP(i,ncell) if(comp[i]==-2) { comp[i]=ncomp++; qhead=qtail=0; q[qhead++]=i; while(qtail<qhead) { int at=q[qtail++]; REPSZ(j,adj4[at]) { int to=adj4[at][j]; if(comp[to]==-2) comp[to]=comp[at],q[qhead++]=to; } } }
	REP(i,ncomp) cells[i].clear(); REP(i,ncell) if(comp[i]!=-1) cells[comp[i]].PB(i);
	assert(ncell>=1&&flatid[0]==-1); outsidecomp=comp[0];
	
	
	available.clear();
	REP(i,nflat) isavailable[i]=false,recalc(i);
	REP(i,nflat) {
		assert(SZ(available)>=1);
		int fid=*available.rbegin(),at=cellid[fid]; available.erase(fid); ans[nflat-i-1]=fid;
		//printf("at=%d (fid=%d)\n",at,fid);
		REPSZ(j,adj4[at]) { int to=adj4[at][j]; if(comp[to]==-1) continue; comp[at]=comp[to],cells[comp[at]].PB(at); break; } assert(comp[at]!=-1);
		REPSZ(j,adj8[at]) { int to=adj8[at][j]; if(comp[to]!=-1) continue; assert(flatid[to]!=-1); recalc(flatid[to]); }
		REPSZ(j,adj4[at]) { int to=adj4[at][j]; if(comp[to]==-1||comp[to]==comp[at]) continue; mergecomp(comp[at],comp[to]); }
	}
	return true;
}

void run() {
	scanf("%d%d",&nflat,&subtask);
	REP(i,nflat) scanf("%d%d",&flat[i].x,&flat[i].y);
	if(!solve()) { printf("NO\n"); return; }
	printf("YES\n"); REP(i,nflat) printf("%d\n",ans[i]+1);
}

int main() {
	run();
	return 0;
}