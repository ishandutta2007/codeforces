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

const int MAXN = 1000;
struct P { int x, y; };

int n;
P p[MAXN];
vector<int> ans;

void solve() {
	P orig = p[0];
	REP(i, n) p[i].x -= orig.x, p[i].y -= orig.y;
	//printf("p:"); REP(i, n) printf(" (%d,%d)", p[i].x, p[i].y); puts("");
	while (true) {
		bool anyodd = false; REP(i, n) if ((p[i].x + p[i].y) % 2 != 0) anyodd = true; if (anyodd) break;
		REP(i, n) { int nx = (p[i].x + p[i].y) / 2, ny = (p[i].x - p[i].y) / 2; p[i].x = nx, p[i].y = ny; }
		//printf("p:"); REP(i, n) printf(" (%d,%d)", p[i].x, p[i].y); puts("");
	}
	ans.clear();
	REP(i, n) if ((p[i].x + p[i].y) % 2 == 0) ans.PB(i);
	assert(SZ(ans) > 0 && SZ(ans) < n);
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d%d", &p[i].x, &p[i].y);
	solve();
	printf("%d\n", SZ(ans));
	REPSZ(i, ans) { if (i != 0) printf(" "); printf("%d", ans[i] + 1); } puts("");
}

int main() {
	run();
	return 0;
}