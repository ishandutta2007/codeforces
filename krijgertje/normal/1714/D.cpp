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

const int MAXSLEN = 100;
const int MAXP = 10;
const int MAXPLEN = 10;

char s[MAXSLEN + 1]; int slen;
int np;
char p[MAXP][MAXPLEN + 1]; int plen[MAXP];
vector<pair<int, int>> ans;

bool solve() {
	vector<pair<int, int>> bestat(slen, MP(-1, 0));
	REP(i, slen) REP(j, np) {
		int k = 0;
		while (i + k < slen && k < plen[j] && s[i + k] == p[j][k]) ++k;
		if (k == plen[j] && k > bestat[i].second) bestat[i] = MP(j, k);
	}
	vector<int> bestfrom(slen, -1);
	REP(i, slen) REPE(j, i) if (j + bestat[j].second > i && (bestfrom[i] == -1 || j + bestat[j].second > bestfrom[i] + bestat[bestfrom[i]].second)) bestfrom[i] = j;
	ans.clear();
	int matched = 0;
	while (matched < slen) {
		if (bestfrom[matched] == -1) return false;
		ans.PB(MP(bestat[bestfrom[matched]].first, bestfrom[matched]));
		matched = bestfrom[matched] + bestat[bestfrom[matched]].second;
	}
	return true;
}

void run() {
	scanf("%s", s); slen = strlen(s);
	scanf("%d", &np);
	REP(i, np) { scanf("%s", p[i]); plen[i] = strlen(p[i]); }
	if (!solve()) { printf("-1\n"); return; }
	printf("%d\n", SZ(ans));
	REPSZ(i, ans) printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}