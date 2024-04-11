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

int n, k;
char s[MAXN + 1];
char t[MAXN + 1];
vector<pair<int, int>> ans;

int ones;

void domove(string& s, vector<pair<int, int>>& moves, int l, int r) {
	//printf("\t%s (%d,%d)\n", s.c_str(), l, r);
	moves.PB(MP(l, r));
	int cnt = 0; FORE(i, l, r) if (s[i] == '1') ++cnt; assert(cnt == k);
	reverse(s.begin() + l, s.begin() + r + 1);
}

void doblockmove(string& s, vector<pair<int, int>>& moves, int leftblock, int zerodir) {
	//printf("\tblockmove %d %d\n", leftblock, zerodir);
	int l = 0;
	REP(i, leftblock) while (true) { assert(l < SZ(s)); char c = s[l++]; if (c == '1') break; } 
	int r = l;
	REP(i, k) while (true) { assert(r < SZ(s)); char c = s[r++]; if (c == '1') break; } 
	if (zerodir == -1) {
		while (s[l] == '0') ++l;
		while (r < SZ(s) && s[r] == '0') ++r;
	}
	domove(s, moves, l, r - 1);
}

void norm(string& s, vector<pair<int, int>> &moves) {
	if (k == 0) return;
	if (k > ones) return;
	if (k == ones) {
		doblockmove(s, moves, 0, -1);
		assert(s.back() == '1');
		int l = 0; while (s[l] == '0') ++l;
		int r = SZ(s) - 1;
		string after = s; reverse(after.begin() + l, after.begin() + r + 1);
		if (after < s) {
			moves.PB(MP(l, r));
			s = after;
		}
		return;
	}
	REP(i, ones - k - 1) doblockmove(s, moves, ones - k - i, -1);
	//printf("here\n");
	if (k % 2 == 0) {
		REP(i, k) doblockmove(s, moves, i % 2, i % 2 == 0 ? -1 : +1);
	} else {
		REP(i, max(k + 2, 2 * k - 1)) doblockmove(s, moves, i % 2, -1);
	}
	//printf("%s\n", s.c_str());
}

bool solve() {
	int sones = 0; REP(i, n) if (s[i] == '1') ++sones;
	int tones = 0; REP(i, n) if (t[i] == '1') ++tones;
	if (sones != tones) return false;
	ones = sones;

	string a = s;
	string b = t;
	vector<pair<int, int>> amove;
	vector<pair<int, int>> bmove;
	norm(a, amove);
	norm(b, bmove);

	REP(i, n) if (a[i] != b[i]) return false;
	ans.clear();
	REPSZ(i, amove) ans.PB(amove[i]);
	REPSZ(i, bmove) ans.PB(bmove[SZ(bmove) - i - 1]);
	return true;
}

void run() {
	scanf("%d%d", &n, &k);
	scanf("%s", s);
	scanf("%s", t);
	if (!solve()) { printf("-1\n"); return; }
	printf("%d\n", SZ(ans));
	REPSZ(i, ans) printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
}

bool solvestupid() {
	string a = s;
	string b = t;
	set<string> seen;
	queue<string> q;
	auto relax = [&](const string& s) { if (seen.count(s)) return; seen.insert(s); q.push(s); };
	relax(a);
	while (!q.empty()) {
		string at = q.front(); q.pop();
		if (at == b) return true;
		REP(i, n) {
			int cnt = 0;
			FOR(j,i, n) {
				if (at[j] == '1') ++cnt;
				if (cnt > k) break;
				if (cnt == k) {
					string to = at;
					reverse(to.begin() + i, to.begin() + j + 1);
					relax(to);
				}
			}
		}
	}
	return false;
}

void stress() {
	for (n = 1; n <= 10; ++n) for (k = 0; k <= n; ++k) {
		REP(smask, 1 << n) REP(tmask, 1 << n) {
			REP(i, n) s[i] = (smask & (1 << i)) == 0 ? '0' : '1'; s[n] = '\0';
			REP(i, n) t[i] = (tmask & (1 << i)) == 0 ? '0' : '1'; t[n] = '\0';
			bool have = solve();
			bool want = solvestupid();
			if (have == want) { printf("."); continue; }
			printf("err\n");
			printf("%d %d\n%s\n%s\n", n, k, s, t);
			return;
		}
	}
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	//stress();
	return 0;
}