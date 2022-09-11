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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=100000;
const int MAXABSCOORD=100000;

int n;
int px[MAXN],py[MAXN],can[MAXN][4];
int ansx,ansy;

bool solve() {
	int lx=-MAXABSCOORD,hx=+MAXABSCOORD,ly=-MAXABSCOORD,hy=+MAXABSCOORD;
	REP(i,n) {
		if(can[i][0]==0) lx=max(lx,px[i]);
		if(can[i][1]==0) hy=min(hy,py[i]);
		if(can[i][2]==0) hx=min(hx,px[i]);
		if(can[i][3]==0) ly=max(ly,py[i]);
	}
	if(lx>hx||ly>hy) return false;
	ansx=lx+(hx-lx)/2,ansy=ly+(hy-ly)/2;
	return true;
}

void run() {
	scanf("%d",&n);
	REP(i,n) { scanf("%d%d",&px[i],&py[i]); REP(j,4) scanf("%d",&can[i][j]); }
	if(!solve()) { printf("0\n"); return; }
	printf("1 %d %d\n",ansx,ansy);
}

int main() {
	int ncase; scanf("%d",&ncase); FORE(i,1,ncase) run();
	return 0;
}