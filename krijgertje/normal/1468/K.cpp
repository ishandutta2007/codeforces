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

const int MAXLEN = 5000;

char s[MAXLEN + 1]; int slen;

pair<int, int> visit[MAXLEN + 1];

pair<int, int> walk(pair<int, int> at, char c) {
	if (c == 'L') --at.first; else if (c == 'R') ++at.first; else if (c == 'D') --at.second; else if (c == 'U') ++at.second; else assert(false);
	return at;
}

pair<int, int> solve() {
	visit[0] = MP(0, 0);
	REP(i, slen) visit[i + 1] = walk(visit[i], s[i]);
	REPE(i, slen) if (visit[i] != MP(0, 0)) {
		pair<int, int> block = visit[i];
		pair<int, int> at = MP(0, 0);
		REP(j, slen) {
			pair<int, int> to = walk(at, s[j]);
			if (to != block) at = to;
		}
		if (at == MP(0, 0)) return block;
	}
	return MP(0, 0);
}

void run() {
	scanf("%s", s); slen = strlen(s);
	pair<int, int> ans = solve();
	printf("%d %d\n", ans.first, ans.second);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}