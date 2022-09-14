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

const int DX[]={-1,0,+1,0},DY[]={0,+1,0,-1}; const char DC[]={'L','U','R','D'};

int size;

int np;
int px[100000];
int py[100000];
int ppx[100000];
int ppy[100000];
int pd[100000];

int nq;
int qx[100000];
int qy[100000];
int qd[100000];
ll qt[100000];

int pnextnode[100000];
int pnextdist[100000];
int pnextpos[100000];
int qnextnode[100000];
int qnextdist[100000];
int qnextpos[100000];

int stepnode[50][100000];
ll steppos[50][100000];

void simulate(int &at,ll &pos,ll cnt,int maxstep) {
	pos+=cnt;
	while(pnextnode[at]!=-1&&pos>=pnextdist[at]) {
		while(maxstep>=0&&(1LL<<maxstep)>pos) --maxstep;
		int to; ll npos; char type;
		if(maxstep>=0&&(1LL<<maxstep)>=pnextdist[at]) {
			to=stepnode[maxstep][at],npos=pos-(1LL<<maxstep)+steppos[maxstep][at]; type='A';
		} else {
			to=pnextnode[at],npos=pos-pnextdist[at]+pnextpos[at]; type='B';
		}
		at=to,pos=npos;
	}
}

// temporary for part 1+2
int gnode[1001][1001];
ll gpos[1001][1001];
void calcnext(int x,int y,int d,int &nextnode,int &nextdist,int &nextpos,int skip) {
	nextdist=0;
	while(x>=0&&x<=size&&y>=0&&y<=size) { if(gnode[x][y]!=-1&&gnode[x][y]!=skip) { nextnode=gnode[x][y]; nextpos=gpos[x][y]; return; } x+=DX[d],y+=DY[d],++nextdist; }
	nextnode=-1;
}

void run(int casenr) {
	//input
	cin>>np>>size;
	REP(i,np) cin>>ppx[i]>>ppy[i]>>px[i]>>py[i];
	REP(i,np) { int dx=px[i]-ppx[i],dy=py[i]-ppy[i]; if(dx<0) dx=-1; if(dx>0) dx=+1; if(dy<0) dy=-1; if(dy>0) dy=+1; pd[i]=-1; REP(k,4) if(DX[k]==dx&&DY[k]==dy) pd[i]=k; }
	cin>>nq;
	REP(i,nq) { char tmp,dc; cin>>qx[i]>>qy[i]>>dc>>qt[i]; qd[i]=-1; REP(k,4) if(DC[k]==dc) qd[i]=k; }

	//calc nextinfo
	memset(gnode,-1,sizeof(gnode)); memset(gpos,-1,sizeof(gpos));
	REP(i,np) for(int x=ppx[i],y=ppy[i];;x+=DX[pd[i]],y+=DY[pd[i]]) { gnode[x][y]=i; gpos[x][y]=-abs(x-px[i])-abs(y-py[i]); if(x==px[i]&&y==py[i]) break; }
//	for(int y=size;y>=0;--y) { REPE(x,size) if(gnode[x][y]==-1) printf("---- "); else printf("%d,%2d ",gnode[x][y],gpos[x][y]); puts(""); }
	REP(i,np) calcnext(px[i],py[i],pd[i],pnextnode[i],pnextdist[i],pnextpos[i],i);
	REP(i,nq) calcnext(qx[i],qy[i],qd[i],qnextnode[i],qnextdist[i],qnextpos[i],-1);

//	REP(i,np) { printf("p[%d] = (%d,%d) -> %c -> (%d,%d)",i,ppx[i],ppy[i],DC[pd[i]],px[i],py[i]); if(pnextnode[i]==-1) puts(""); else printf(" -> %d -> (%d,%d)\n",pnextdist[i],pnextnode[i],pnextpos[i]); }
//	REP(i,nq) { printf("q[%d] = (%d,%d) -> %c [%lld]",i,qx[i],qy[i],DC[qd[i]],qt[i]); if(qnextnode[i]==-1) puts(""); else printf(" -> %d -> (%d,%d)\n",qnextdist[i],qnextnode[i],qnextpos[i]); }

	//calc stepinfo
	REP(j,np) {
		stepnode[0][j]=j; steppos[0][j]=0;
		simulate(stepnode[0][j],steppos[0][j],1,-1);
//		printf("step[%d][%d]=(%d,%lld)\n",0,j,stepnode[0][j],steppos[0][j]);
	}
	FOR(i,1,50) REP(j,np) {
		stepnode[i][j]=stepnode[i-1][j]; steppos[i][j]=steppos[i-1][j];
		simulate(stepnode[i][j],steppos[i][j],1LL<<(i-1),i-1);
//		printf("step[%d][%d]=(%d,%lld)\n",i,j,stepnode[i][j],steppos[i][j]);
	}

	//process queries
	REP(qi,nq) {
		ll x,y;
		if(qnextnode[qi]!=-1&&qt[qi]>=qnextdist[qi]) {
			int at=qnextnode[qi]; ll pos=qnextpos[qi];
			simulate(at,pos,qt[qi]-qnextdist[qi],50);
			x=px[at]+pos*DX[pd[at]],y=py[at]+pos*DY[pd[at]];
		} else {
			x=qx[qi]+qt[qi]*DX[qd[qi]],y=qy[qi]+qt[qi]*DY[qd[qi]];
		}
		if(x<0) x=0; if(x>size) x=size; if(y<0) y=0; if(y>size) y=size;
		cout<<x<<" "<<y<<endl;
	}
}


int main() {
//	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}