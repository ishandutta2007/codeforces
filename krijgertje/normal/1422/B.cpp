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

int h, w;
vector<vector<int>> a;

ll solve() {
	ll ret = 0;
	REP(x, h) REP(y, w) {
		int xx = h - x - 1, yy = w - y - 1;
		if (x > xx || y > yy) continue;
		vector<int> cur;
		cur.PB(a[x][y]);
		if (yy != y) cur.PB(a[x][yy]);
		if (xx != x) cur.PB(a[xx][y]);
		if (xx != x && yy != y) cur.PB(a[xx][yy]);
		sort(cur.begin(), cur.end());
		int use = cur[SZ(cur) / 2];
		REPSZ(i, cur) ret += abs(cur[i] - use);
	}
	return ret;
}

void run() {
	scanf("%d%d", &h, &w);
	a = vector<vector<int>>(h, vector<int>(w)); REP(x, h) REP(y, w) scanf("%d", &a[x][y]);
	printf("%lld\n", solve());
}


int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}