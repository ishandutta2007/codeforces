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

int r, step;

bool solve() {
	// a<=r/step/sqrt(2)
	int a = 1.0*r / step / sqrt(2.0);
	while ((ll)2 * (a + 1) * (a + 1) * step * step <= (ll)r * r) ++a;
	while ((ll)2 * a * a * step * step > (ll)r * r) --a;
	//printf("a=%d\n", a);
	return (ll)a * a * step * step + (ll)(a + 1) * (a + 1) * step * step <= (ll)r * r;
}

void run() {
	scanf("%d%d", &r, &step);
	printf("%s\n", solve() ? "Ashish" : "Utkarsh");
}

void research() {
	double r = 15441.0 / 33;
	int lim = ceil(r);
	vector<vector<int>> res(lim + 1, vector<int>(lim + 1, -1));
	for (int x = lim; x >= 0; --x) for (int y = lim; y >= 0; --y) {
		if (x * x + y * y > r * r + 1e-12) continue;
		bool win = false;
		if (x + 1 <= lim && res[x + 1][y] == 0) win = true;
		if (y + 1 <= lim && res[x][y + 1] == 0) win = true;
		res[x][y] = win ? 1 : 0;
	}
	for (int x = lim; x >= 0; --x) {
		REPE(y, lim) printf("%c", res[x][y] == -1 ? '.' : '0' + res[x][y]); puts("");
	}
}

int main() {
	//research();
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}