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
#include <chrono>
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
std::mt19937 rnd((int)std::chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

const int MAXN = 2000;
struct P { int x, y; };

int nrobber, nlight;
P probber[MAXN];
P plight[MAXN];

int solve() {
	int mxx = 0; REP(i, nlight) mxx = max(mxx, plight[i].x);
	vector<int> lim(mxx + 2, 0);
	REP(i, nrobber) REP(j, nlight) {
		if (plight[j].x < probber[i].x) continue;
		if (plight[j].y < probber[i].y) continue;
		int dx = plight[j].x - probber[i].x;
		int dy = plight[j].y - probber[i].y;
		lim[dx] = max(lim[dx], dy + 1);
	}
	for (int i = mxx; i >= 0; --i) lim[i] = max(lim[i], lim[i + 1]);
	//printf("lim:"); REPSZ(i, lim) printf(" %d", lim[i]); puts("");
	int ret = INT_MAX;
	REPSZ(i, lim) ret = min(ret, i + lim[i]);
	return ret;
}

void run() {
	scanf("%d%d", &nrobber, &nlight);
	REP(i, nrobber) scanf("%d%d", &probber[i].x, &probber[i].y);
	REP(i, nlight) scanf("%d%d", &plight[i].x, &plight[i].y);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}