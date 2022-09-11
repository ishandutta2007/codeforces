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

const int MAXLEN = 100000;

char s[MAXLEN + 1]; int slen;
pair<int, string> ans[MAXLEN];

int nxtdiff[MAXLEN];
char firstcharinans[MAXLEN], nxtdiffcharinans[MAXLEN];

string reduce(string s) { if (SZ(s) <= 10) return s; return s.substr(0, 5) + "..." + s.substr(SZ(s) - 2); }

void solve() {
	for (int i = slen - 1; i >= 0; --i) nxtdiff[i] = s[i] == s[i + 1] ? nxtdiff[i + 1] : i + 1;
	for (int i = slen - 1; i >= 0; --i) {
		char c = s[i];
		int to = nxtdiff[i];
		int cnt = to - i;
		if (to == slen) {
			int keep = cnt % 2;
			ans[i] = MP(keep, string(keep, c));
			firstcharinans[i] = keep == 0 ? '-' : c, nxtdiffcharinans[i] = '-';
		} else {
			int keep;
			if (firstcharinans[to] == '-' || c > firstcharinans[to] || c == firstcharinans[to] && (nxtdiffcharinans[to] == '-' || c > nxtdiffcharinans[to])) {
				keep = cnt % 2;
			} else {
				keep = cnt;
			}
			ans[i] = MP(keep + ans[to].first, reduce(string(min(keep, 10), c) + ans[to].second));
			firstcharinans[i] = keep == 0 ? firstcharinans[to] : c, nxtdiffcharinans[i] = keep == 0 || c == firstcharinans[to] ? nxtdiffcharinans[to] : firstcharinans[to];
		}
	}
}


void run() {
	scanf("%s", s); slen = strlen(s);
	solve();
	REP(i, slen) printf("%d %s\n", ans[i].first, ans[i].second.c_str());
}


int main() {
	run();
	return 0;
}