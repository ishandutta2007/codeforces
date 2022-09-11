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

const int H=10;
const int W=10;

char g[H][W+1];

void upd(bool &ok,int &cnt,char c) { if(c=='X') ++cnt; else if(c=='O') ok=false; }
bool solve() {
	REPE(x,H-5) REP(y,W) {
		bool ok=true; int cnt=0;
		REP(i,5) upd(ok,cnt,g[x+i][y]);
		if(ok&&cnt==4) return true;
	}
	REP(x,H) REPE(y,W-5) {
		bool ok=true; int cnt=0;
		REP(i,5) upd(ok,cnt,g[x][y+i]);
		if(ok&&cnt==4) return true;
	}
	REPE(x,H-5) REPE(y,W-5) {
		bool ok=true; int cnt=0;
		REP(i,5) upd(ok,cnt,g[x+i][y+i]);
		if(ok&&cnt==4) return true;
	}
	REPE(x,H-5) REPE(y,W-5) {
		bool ok=true; int cnt=0;
		REP(i,5) upd(ok,cnt,g[x+i][y+4-i]);
		if(ok&&cnt==4) return true;
	}
	return false;
}

void run() {
	REP(x,H) scanf("%s",g[x]);
	printf("%s\n",solve()?"YES":"NO");
}

int main() {
	run();
	return 0;
}