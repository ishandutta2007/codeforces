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

int h, w, nhor;
vector<string> ans;

bool solve() {
	int hh = h, ww = w, havehor = 0;
	if (hh % 2 != 0) --hh, havehor += ww / 2;
	if (ww % 2 != 0) --ww;
	int remhor = nhor - havehor;
	if (remhor < 0 || remhor > hh * ww / 2 || remhor % 2 != 0) return false;
	ans = vector<string>(h, string(w, '?'));
	REP(x, hh / 2) REP(y, ww / 2) {
		char a = 'a' + 2 * ((x + y) % 2), b = a + 1;
		if (remhor > 0) {
			ans[2 * x][2 * y] = ans[2 * x][2 * y + 1] = a;
			ans[2 * x + 1][2 * y] = ans[2 * x + 1][2 * y + 1] = b;
			remhor -= 2;
		} else {
			ans[2 * x][2 * y] = ans[2 * x + 1][2 * y] = a;
			ans[2 * x][2 * y + 1] = ans[2 * x + 1][2 * y + 1] = b;
		}
	}
	FOR(x, hh, h) REP(y, ww / 2) {
		char a = 'e' + (y % 2);
		ans[x][2 * y] = ans[x][2 * y + 1] = a;
	}
	FOR(y, ww, w) REP(x, hh / 2) {
		char a = 'e' + (x % 2);
		ans[2 * x][y] = ans[2 * x + 1][y] = a;
	}
	return true;
}

void run() {
	scanf("%d%d%d", &h, &w, &nhor);
	if (!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	REPSZ(i, ans) printf("%s\n", ans[i].c_str());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}