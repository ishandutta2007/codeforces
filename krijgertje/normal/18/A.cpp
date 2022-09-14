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
#include <cassert>
#include <climits>
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

const int DX[]={-1,0,+1,0},DY[]={0,+1,0,-1};
typedef struct P { int x,y; P(int x,int y):x(x),y(y) {} } P;
P operator-(const P &a,const P &b) { return P(a.x-b.x,a.y-b.y); }
int operator*(const P &a,const P &b) { return a.x*b.x+a.y*b.y; }
int operator^(const P &a,const P &b) { return a.x*b.y-a.y*b.x; }

bool ok(const P &a,const P &b,const P &c) {
	if(((b-a)^(c-a))==0) return false;
	if(((b-a)*(c-a))==0) return true;
	if(((a-b)*(c-b))==0) return true;
	if(((a-c)*(b-c))==0) return true;
	return false;
}

void run() {
	vector<P> p;
	REP(i,3) { int x,y; scanf("%d%d",&x,&y); p.PB(P(x,y)); }
	if(ok(p[0],p[1],p[2])) { printf("RIGHT\n"); return; }
	REP(i,3) REP(k,4) {
		vector<P> np=p; np[i].x+=DX[k],np[i].y+=DY[k];
		if(ok(np[0],np[1],np[2])) { printf("ALMOST\n"); return; }
	}
	printf("NEITHER\n");
}

int main() {
//	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}