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

char buff[10];

void read(int &x,int &y) { scanf("%s",buff); x=buff[0]-'a',y=buff[1]-'1'; }
bool canrook(int x,int y) { return x==0||y==0; }
bool canknight(int x,int y) { return x*x+y*y==5; }

void run() {
	int rx,ry; read(rx,ry);
	int kx,ky; read(kx,ky);
	int ret=0;
	REP(x,8) REP(y,8) {
		if(x==rx&&y==ry) continue;
		if(x==kx&&y==ky) continue;
		if(canrook(x-rx,y-ry)) continue;
		if(canknight(x-kx,y-ky)) continue;
		if(canknight(rx-x,ry-y)) continue;
		if(canknight(kx-x,ky-y)) continue;
		++ret;
	}
	printf("%d\n",ret);
}


int main() {
//	freopen ("input.txt","r",stdin);
//	freopen ("output.txt","w",stdout);
//	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}