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
#include <stack>
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
typedef vector<int> VI; typedef vector<VI> VVI; typedef vector<VVI> VVVI;

typedef struct X { int h,r,R; double x; } X;

void run() {
	int n; scanf("%d",&n);
	vector<X> bowl(n); REP(i,n) scanf("%d%d%d",&bowl[i].h,&bowl[i].r,&bowl[i].R);
	bowl[0].x=0;
	FOR(i,1,n) {
		bowl[i].x=0;
		#define CHECK(val) { /*printf("%d %d -> %lf\n",i,j,bowl[j].x+(val));*/ if(bowl[j].x+(val)>bowl[i].x) bowl[i].x=bowl[j].x+(val); }
		REP(j,i) {
			int r1=bowl[j].r,R1=bowl[j].R,h1=bowl[j].h;
			int r2=bowl[i].r,R2=bowl[i].R,h2=bowl[i].h;
			// bottom touches something
			if(r2<=r1) { CHECK(0); }
			else if(r2<R1) { CHECK(1.0*(r2-r1)/(R1-r1)*h1); }
			else { CHECK(h1); }
			// top touches something
			if(R2<=r1) { CHECK(0-h2); }
			else if(R2<R1) { CHECK(1.0*(R2-r1)/(R1-r1)*h1-h2); }
			else { CHECK(h1-h2); }
			// sides touch
			if(r2<R1&&R1<R2) { CHECK(h1-1.0*(R1-r2)/(R2-r2)*h2); }
		}
	}
	double ret=0;
	REP(i,n) { double cur=bowl[i].x+bowl[i].h; if(cur>ret) ret=cur; }
	printf("%.9lf\n",ret);
}

int main() {
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);
//	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}