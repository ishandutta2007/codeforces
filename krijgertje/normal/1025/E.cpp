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

const int MAXSZ=50;
const int MAXN=MAXSZ;
const int MAXMOVE=10800;
struct Move { int sx,sy,ex,ey; Move() {} Move(int sx,int sy,int ex,int ey):sx(sx),sy(sy),ex(ex),ey(ey) {} };


int sz,n;
int sx[MAXN],sy[MAXN];
int ex[MAXN],ey[MAXN];
Move ret[MAXMOVE]; int nret;

int cx[MAXN],cy[MAXN];
int erowsum[MAXSZ];

void solve() {
	nret=0;
	if(sz==1) return;
	REP(i,n) cx[i]=sx[i],cy[i]=sy[i];
	REP(i,sz) erowsum[i]=0; REP(i,n) ++erowsum[ex[i]];
	//printf("sum:"); REP(i,sz) printf(" %d",erowsum[i]); puts("");
	int ax=-1; REP(i,sz-1) if(erowsum[i]+erowsum[i+1]<=2) { ax=i; break; }
	bool special=false;
	if(ax==-1) { assert(sz==3&&n==3&&erowsum[1]==3); special=true; ax=0; }

	// move everyone to positions on row ax
	int acnt=0;
	while(true) {
		int cur=-1; REP(i,n) if(cx[i]==ax&&cy[i]>=acnt&&(cur==-1||cy[i]<cy[cur])) cur=i; if(cur==-1) break;
		while(cy[cur]>acnt) { ret[nret++]=Move(cx[cur],cy[cur],cx[cur],cy[cur]-1); --cy[cur]; }
		++acnt;
	}
	while(true) {
		int cur=-1; REP(i,n) if(cx[i]<ax&&(cur==-1||cx[i]>cx[cur]||cx[i]==cx[cur]&&cy[i]>cy[cur])) cur=i; if(cur==-1) break;
		while(cy[cur]<acnt) { ret[nret++]=Move(cx[cur],cy[cur],cx[cur],cy[cur]+1); ++cy[cur]; }
		while(cx[cur]<ax) { ret[nret++]=Move(cx[cur],cy[cur],cx[cur]+1,cy[cur]); ++cx[cur]; }
		while(cy[cur]>acnt) { ret[nret++]=Move(cx[cur],cy[cur],cx[cur],cy[cur]-1); --cy[cur]; }
		++acnt;
	}
	while(true) {
		int cur=-1; REP(i,n) if(cx[i]>ax&&(cur==-1||cx[i]<cx[cur]||cx[i]==cx[cur]&&cy[i]>cy[cur])) cur=i; if(cur==-1) break;
		while(cy[cur]<acnt) { ret[nret++]=Move(cx[cur],cy[cur],cx[cur],cy[cur]+1); ++cy[cur]; }
		while(cx[cur]>ax) { ret[nret++]=Move(cx[cur],cy[cur],cx[cur]-1,cy[cur]); --cx[cur]; }
		while(cy[cur]>acnt) { ret[nret++]=Move(cx[cur],cy[cur],cx[cur],cy[cur]-1); --cy[cur]; }
		++acnt;
	}
	assert(acnt==n);
	if(special) {
		REP(i,n) { int cur=i; while(cx[cur]<i) { ret[nret++]=Move(cx[cur],cy[cur],cx[cur]+1,cy[cur]); ++cx[cur]; } }
		REP(i,n) {
			int cur=i;
			while(cy[cur]<ey[cur]) { ret[nret++]=Move(cx[cur],cy[cur],cx[cur],cy[cur]+1); ++cy[cur]; }
			while(cy[cur]>ey[cur]) { ret[nret++]=Move(cx[cur],cy[cur],cx[cur],cy[cur]-1); --cy[cur]; }
		}
		REP(i,n) {
			int cur=i;
			while(cx[cur]<ex[cur]) { ret[nret++]=Move(cx[cur],cy[cur],cx[cur]+1,cy[cur]); ++cx[cur]; }
			while(cx[cur]>ex[cur]) { ret[nret++]=Move(cx[cur],cy[cur],cx[cur]-1,cy[cur]); --cx[cur]; }
		}
		return;
	}

	// move everyone not on row ax or ax+1 to the final positions
	while(true) {
		int cur=-1; REP(i,n) if(cx[i]==ax&&ex[i]>ax+1&&(cur==-1||ex[i]>ex[cur])) cur=i; if(cur==-1) break;
		{ ret[nret++]=Move(cx[cur],cy[cur],cx[cur]+1,cy[cur]); ++cx[cur]; }
		while(cy[cur]<ey[cur]) { ret[nret++]=Move(cx[cur],cy[cur],cx[cur],cy[cur]+1); ++cy[cur]; }
		while(cy[cur]>ey[cur]) { ret[nret++]=Move(cx[cur],cy[cur],cx[cur],cy[cur]-1); --cy[cur]; }
		while(cx[cur]<ex[cur]) { ret[nret++]=Move(cx[cur],cy[cur],cx[cur]+1,cy[cur]); ++cx[cur]; }
	}
	REP(i,n) if(cx[i]==ax) { int cur=i; ret[nret++]=Move(cx[cur],cy[cur],cx[cur]+1,cy[cur]); ++cx[cur]; }
	while(true) {
		int cur=-1; REP(i,n) if(cx[i]==ax+1&&ex[i]<ax&&(cur==-1||ex[i]<ex[cur])) cur=i; if(cur==-1) break;
		{ ret[nret++]=Move(cx[cur],cy[cur],cx[cur]-1,cy[cur]); --cx[cur]; }
		while(cy[cur]<ey[cur]) { ret[nret++]=Move(cx[cur],cy[cur],cx[cur],cy[cur]+1); ++cy[cur]; }
		while(cy[cur]>ey[cur]) { ret[nret++]=Move(cx[cur],cy[cur],cx[cur],cy[cur]-1); --cy[cur]; }
		while(cx[cur]>ex[cur]) { ret[nret++]=Move(cx[cur],cy[cur],cx[cur]-1,cy[cur]); --cx[cur]; }
	}

	// move those on row ax or ax to the final positions
	vector<int> rem; REP(i,n) if(cx[i]==ax+1) rem.PB(i);
	assert(SZ(rem)<=2);
	if(SZ(rem)==0) return;
	if(ex[rem[0]]==ax) { int cur=rem[0]; ret[nret++]=Move(cx[cur],cy[cur],cx[cur]-1,cy[cur]); --cx[cur]; }
	else if(SZ(rem)==2) { int cur=rem[1]; ret[nret++]=Move(cx[cur],cy[cur],cx[cur]-1,cy[cur]); --cx[cur]; }
	REPSZ(i,rem) {
		int cur=rem[i];
		//printf("cur=%d (%d)\n",cur,nret);
		while(cy[cur]<ey[cur]) { ret[nret++]=Move(cx[cur],cy[cur],cx[cur],cy[cur]+1); ++cy[cur]; }
		while(cy[cur]>ey[cur]) { ret[nret++]=Move(cx[cur],cy[cur],cx[cur],cy[cur]-1); --cy[cur]; }
		while(cx[cur]<ex[cur]) { ret[nret++]=Move(cx[cur],cy[cur],cx[cur]+1,cy[cur]); ++cx[cur]; }
		while(cx[cur]>ex[cur]) { ret[nret++]=Move(cx[cur],cy[cur],cx[cur]-1,cy[cur]); --cx[cur]; }
	}
	REP(i,n) assert(cx[i]==ex[i]&&cy[i]==ey[i]);
}

void verify() {
	vector<vector<int>> who(sz,vector<int>(sz,-1));
	REP(i,n) who[sx[i]][sy[i]]=i;
	REP(i,nret) {
		assert(who[ret[i].sx][ret[i].sy]!=-1);
		assert(who[ret[i].ex][ret[i].ey]==-1);
		assert(abs(ret[i].sx-ret[i].ex)+abs(ret[i].sy-ret[i].ey)==1);
		swap(who[ret[i].sx][ret[i].sy],who[ret[i].ex][ret[i].ey]);
	}
	REP(i,n) assert(who[ex[i]][ey[i]]==i);
}

void run() {
	scanf("%d%d",&sz,&n); REP(i,n) scanf("%d%d",&sx[i],&sy[i]),--sx[i],--sy[i]; REP(i,n) scanf("%d%d",&ex[i],&ey[i]),--ex[i],--ey[i];

	solve();
	printf("%d\n",nret);
	REP(i,nret) printf("%d %d %d %d\n",ret[i].sx+1,ret[i].sy+1,ret[i].ex+1,ret[i].ey+1);
	verify();
}

void stress() {
	REP(rep,100000) {
		sz=n=rand()%6+1;
		{ set<pair<int,int> > seen; REP(i,n) while(true) { int x=rand()%sz,y=rand()%sz; if(seen.count(MP(x,y))) continue; sx[i]=x,sy[i]=y; seen.insert(MP(x,y)); break; } }
		{ set<pair<int,int> > seen; REP(i,n) while(true) { int x=rand()%sz,y=rand()%sz; if(seen.count(MP(x,y))) continue; ex[i]=x,ey[i]=y; seen.insert(MP(x,y)); break; } }
		//printf("%d %d\n",sz,n);
		//REP(i,n) printf("%d %d\n",sx[i]+1,sy[i]+1);
		//REP(i,n) printf("%d %d\n",ex[i]+1,ey[i]+1);
		solve();
		//printf("%d\n",nret);
		//REP(i,nret) printf("%d %d %d %d\n",ret[i].sx+1,ret[i].sy+1,ret[i].ex+1,ret[i].ey+1);
		verify();
		printf(".");
	}
}

int main() {
	run();
	//stress();
	return 0;
}