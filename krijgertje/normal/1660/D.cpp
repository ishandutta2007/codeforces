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
#include <functional>
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

const int MAXN = 200000;

int n;
int a[MAXN];

pair<int, int> solve() {
	pair<int, int> ret = MP(n, 0); int lgret = 0;
	for (int l = 0, r = l; l < n; l = r) {
		while (r < n && (a[r] == 0) == (a[l] == 0)) ++r;
		if (a[l] == 0) continue;
		int cntneg = 0;
		FOR(i, l, r) if (a[i] < 0) ++cntneg;
		if (cntneg % 2 == 0) {
			int lgcur = 0;
			FOR(i, l, r) if (abs(a[i]) == 2) ++lgcur;
			if (lgcur > lgret) lgret = lgcur, ret = MP(l, n - r);
		} else {
			for (int dir = -1; dir <= +1; dir += 2) {
				int rem = dir == +1 ? l : r - 1;
				while (a[rem] > 0) rem += dir;
				int lgcur = 0;
				int cl = dir == +1 ? rem + 1 : l;
				int cr = dir == +1 ? r : rem;
				assert(cl <= cr);
				FOR(i, cl, cr) if (abs(a[i]) == 2) ++lgcur;
				if (lgcur > lgret) lgret = lgcur, ret = MP(cl, n - cr);
			}
		}
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	pair<int, int> ans = solve();
	printf("%d %d\n", ans.first, ans.second);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}