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

const int MAXR=666;
const int MAXDIM=999;

int nr=MAXR,h=MAXDIM,w=MAXDIM;
int skx,sky;
int srx[MAXR],sry[MAXR];

int kx,ky;
int rx[MAXR],ry[MAXR];
bool hasrook[MAXDIM][MAXDIM];

bool local=false; int nq;

bool move(int nkx,int nky) {
	assert(0<=nkx&&nkx<h&&0<=nky&&nky<w&&!hasrook[nkx][nky]); ++nq;
	if(!local) {
		kx=nkx,ky=nky; printf("%d %d\n",kx+1,ky+1); fflush(stdout);
		int idx,nrx,nry; scanf("%d%d%d",&idx,&nrx,&nry); if(idx==-1&&nrx==-1&&nry==-1) return true; if(idx==0&&nrx==0&&nry==0) return true; --idx,--nrx,--nry;
		hasrook[rx[idx]][ry[idx]]=false; rx[idx]=nrx,ry[idx]=nry; hasrook[rx[idx]][ry[idx]]=true;
	} else {
		kx=nkx,ky=nky;
		REP(i,nr) assert(kx!=rx[i]||ky!=ry[i]);
		REP(i,nr) if(kx==rx[i]||ky==ry[i]) return true;
		int idx=0; REP(i,nr) if(min(abs(rx[i]-kx),abs(ry[i]-ky))<min(abs(rx[idx]-kx),abs(ry[idx]-ky))) idx=i;
		int nrx=-1,nry=-1; REP(x,h) REP(y,w) if(x==rx[idx]&&y==ry[idx]||!hasrook[x][y]) if(nrx==-1||nry==-1||min(abs(x-kx),abs(y-ky))>min(abs(nrx-kx),abs(nry-ky))) nrx=x,nry=y;
		hasrook[rx[idx]][ry[idx]]=false; rx[idx]=nrx,ry[idx]=nry; hasrook[rx[idx]][ry[idx]]=true;
	}
	return false;
}

void solve() {
	kx=skx,ky=sky; REP(i,nr) rx[i]=srx[i],ry[i]=sry[i];
	REP(x,h) REP(y,w) hasrook[x][y]=false;
	REP(i,nr) hasrook[rx[i]][ry[i]]=true;

	int tx=(h-1)/2,ty=(w-1)/2;
	while(kx!=tx||ky!=ty) {
		int nkx=kx; if(kx<tx) ++nkx; else if(kx>tx) --nkx;
		int nky=ky; if(ky<ty) ++nky; else if(ky>ty) --nky;
		if(hasrook[nkx][nky]) nkx=kx;
		if(move(nkx,nky)) return;
	}
	vector<vector<int>> cnt(2,vector<int>(2,0));
	REP(i,nr) { int a=rx[i]<kx?0:1,b=ry[i]<kx?0:1; ++cnt[a][b]; }
	int A=0,B=0; REP(a,2) REP(b,2) if(cnt[a][b]<cnt[A][B]) A=a,B=b;
	int dx=A==0?+1:-1,dy=B==0?+1:-1;
	while(true) {
		int nkx=kx+dx,nky=ky+dy; assert(0<=nkx&&nkx<h&&0<=nky&&nky<w);
		if(hasrook[nkx][nky]) nkx=kx;
		if(move(nkx,nky)) return;
	}
}

void run() {
	scanf("%d%d",&skx,&sky),--skx,--sky;
	REP(i,nr) scanf("%d%d",&srx[i],&sry[i]),--srx[i],--sry[i];
	solve();
}

void solvelocal() {
	local=true; nq=0;
	solve();
	printf("(%d)",nq);
}

void stress() {
	REP(rep,1000) {
		skx=rand()%h,sky=rand()%w;
		set<pair<int,int>> seen; REP(i,nr) while(true) { srx[i]=rand()%h,sry[i]=rand()%w; if(seen.count(MP(srx[i],sry[i]))||abs(srx[i]-skx)<5||abs(sry[i]-sky)<5) continue; seen.insert(MP(srx[i],sry[i])); break; }
		solvelocal();
	}
}

int main() {
	run();
	//stress();
	return 0;
}