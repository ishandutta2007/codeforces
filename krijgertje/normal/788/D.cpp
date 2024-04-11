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
#include <random>
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
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXCOORD=100000000;
const int MAXX=10000;
const int MAXY=10000;

std::random_device rd;     // only used once to initialise (seed) engine
std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
std::uniform_int_distribution<int> uni(-MAXCOORD,+MAXCOORD); // guaranteed unbiased

int randcoord() { 
	return uni(rng);
}

bool local=false; set<int> lx,ly; int nq;
int dst(set<int> &vals,int val) { set<int>::iterator it=vals.lower_bound(val); int ret=it==vals.end()?INT_MAX:abs(val-*it); if(it!=vals.begin()) { --it; ret=min(ret,abs(val-*it)); } return ret; }
int query(int qx,int qy) {
	assert(-MAXCOORD<=qx&&qx<=+MAXCOORD&&-MAXCOORD<=qy&&qy<=+MAXCOORD); ++nq;
	if(local) {
		return min(dst(lx,qx),dst(ly,qy));
	} else {
		printf("0 %d %d\n",qx,qy); fflush(stdout); int ret; scanf("%d",&ret); if(ret==-1) exit(0); return ret;
	}
}
bool inv;
int queryinv(int qx,int qy) { return !inv?query(qx,qy):query(qy,qx); }


int x[MAXX],nx;
int y[MAXY],ny;

void solverange(int xx,int have,int ly,int hy) {
	if(hy-ly<=1) return;
	int my=ly+(hy-ly)/2;
	int dl=my-ly,dh=hy-my; assert(dl<=have&&dh<=have); assert(dl<=dh); assert(dh-dl<=1);
	int cur=queryinv(xx,my);
	if(cur>=dh) return;
	if(cur>=dl) { int extra=queryinv(xx,hy-1); if(extra==0) y[ny++]=hy-1; return; }
	int resy;
	if(queryinv(xx,my-cur)==0) resy=my-cur; else resy=my+cur;
	solverange(xx,have,ly,resy); y[ny++]=resy; solverange(xx,have,resy,hy);
}
void solve(int xx,int have) {
	ny=0;
	int cy=-MAXCOORD; bool before=false;
	while(cy<=MAXCOORD) {
		if(!before) {
			int cur=queryinv(xx,cy);
			if(cur<have) {
				y[ny++]=cy+cur; cy=y[ny-1]+1; before=true;
			} else {
				cy+=cur; before=false;
			}
		} else {
			int qy=min(MAXCOORD,cy+have-1);
			int cur=queryinv(xx,qy);
			if(cur<have&&cur<qy-cy+1) {
				int resy;
				if(queryinv(xx,qy-cur)==0) resy=qy-cur; else resy=qy+cur;
				solverange(xx,have,cy-1,resy);
				y[ny++]=resy; cy=y[ny-1]+1; before=true;
			} else {
				cy=qy+cur; before=false;
			}
		}
	}
}

void solve() {
	nx=ny=nq=0;
	int have,want=5000,sx,sy;
	do { sx=randcoord(),sy=randcoord(); have=query(sx,sy); } while(have<=want);
	inv=true; solve(sy,have); nx=ny; REP(i,nx) x[i]=y[i];
	inv=false; solve(sx,have);
}

void run() {
	local=false; solve();
	printf("1 %d %d\n",nx,ny);
	REP(i,nx) { if(i!=0) printf(" "); printf("%d",x[i]); } puts("");
	REP(i,ny) { if(i!=0) printf(" "); printf("%d",y[i]); } puts("");
}

void stress() {
	while(true) {
		lx.clear(); ly.clear();
		//lx.insert(2); ly.insert(0); ly.insert(-3);
		//REP(i,MAXX) lx.insert(-MAXCOORD+20000*i); REP(i,MAXY) ly.insert(-MAXCOORD+20000*i);
		//REP(i,1000) lx.insert(MAXCOORD-i),ly.insert(MAXCOORD-i),lx.insert(-MAXCOORD+i),ly.insert(-MAXCOORD+i); REP(i,100) lx.insert(randcoord()),ly.insert(randcoord());
		while(SZ(lx)!=MAXX) lx.insert(randcoord()); while(SZ(ly)!=MAXY) ly.insert(randcoord());

		local=true; solve();
		printf("nq=%d\n",nq);
		bool ok=true;
		if(nx!=SZ(lx)||ny!=SZ(ly)) ok=false;
		if(ok) { set<int>::iterator it=lx.begin(); REP(i,nx) { if(x[i]!=*it) ok=false; ++it; } }
		if(ok) { set<int>::iterator it=ly.begin(); REP(i,ny) { if(y[i]!=*it) ok=false; ++it; } }
		if(!ok) {
			printf("error\n");
		}
		break;
	}
}

int main() {
	//stress();
	run();
	return 0;
}