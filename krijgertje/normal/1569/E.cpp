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

const int MOD = 998244353;
int pw(int x, int n) { int ret = 1; while (true) { if (n & 1) ret = (ll)ret * x % MOD; if ((n >>= 1) == 0) return ret; x = (ll)x * x % MOD; } };

int k, A, have;
vector<int> ans;

bool solve() {

	vector<int> place(k + 1);
	place[k] = 1;
	REP(i, k) place[k - i - 1] = (1 << i) + 1;
	//printf("place:"); REPE(i, k) printf(" %d", place[i]); puts("");
	vector<int> score(k + 1);
	REPE(i, k) score[i] = pw(A, place[i]);
	//printf("score:"); REPE(i, k) printf(" %d", score[i]); puts("");

	int nteam = 1 << k;
	int hteam = 1 << (k - 1);
	ans = vector<int>(nteam, -1);

	map<int, vector<int>> winmp;
	map<int, vector<int>> losemp;

	REP(mask, 1 << (hteam - 1)) {
		deque<int> q; REP(i, hteam) q.PB(i);
		int at = 0;
		vector<int> wins(hteam, 0);
		while (SZ(q) >= 2) {
			int x = q.front(); q.pop_front();
			int y = q.front(); q.pop_front();
			assert(at < hteam - 1);
			int res = (mask >> at) & 1;
			++at;
			if (res == 1) swap(x, y);
			++wins[x];
			q.PB(x);
		}
		assert(at == hteam - 1);

		int cur;
		cur = 0; REP(i, hteam) cur = (cur + (ll)(i + 1) * score[wins[i]]) % MOD;
		//printf("mask=%x lose=%d\n", mask, cur); printf("wins:"); REP(i, hteam) printf(" %d", wins[i]); puts("");
		if (!losemp.count(cur)) losemp[cur] = wins;
		++wins[q.front()];
		cur = 0; REP(i, hteam) cur = (cur + (ll)(i + 1) * score[wins[i]]) % MOD;
		//printf("mask=%x win=%d\n", mask, cur); printf("wins:"); REP(i, hteam) printf(" %d", wins[i]); puts("");
		if (!winmp.count(cur)) winmp[cur] = wins;
	}

	REP(mask, 1 << (hteam - 1)) {
		deque<int> q; REP(i, hteam) q.PB(i);
		int at = 0;
		vector<int> wins(hteam, 0);
		while (SZ(q) >= 2) {
			int x = q.front(); q.pop_front();
			int y = q.front(); q.pop_front();
			assert(at < hteam - 1);
			int res = (mask >> at) & 1;
			++at;
			if (res == 1) swap(x, y);
			++wins[x];
			q.PB(x);
		}
		assert(at == hteam - 1);

		int cur, want;
		cur = 0; REP(i, hteam) cur = (cur + (ll)(i + hteam + 1) * score[wins[i]]) % MOD;
		want = (have + MOD - cur) % MOD;
		//printf("mask=%x lose=%d want=%d\n", mask, cur, want); printf("wins:"); REP(i, hteam) printf(" %d", wins[i]); puts("");
		if (winmp.count(want)) { vector<int> firstwins = winmp[want]; REP(i, hteam) ans[i] = place[firstwins[i]]; REP(i, hteam) ans[hteam + i] = place[wins[i]]; return true; }
		++wins[q.front()];
		cur = 0; REP(i, hteam) cur = (cur + (ll)(i + hteam + 1) * score[wins[i]]) % MOD;
		want = (have + MOD - cur) % MOD;
		//printf("mask=%x win=%d want=%d\n", mask, cur, want); printf("wins:"); REP(i, hteam) printf(" %d", wins[i]); puts("");
		if (losemp.count(want)) { vector<int> firstwins = losemp[want]; REP(i, hteam) ans[i] = place[firstwins[i]]; REP(i, hteam) ans[hteam + i] = place[wins[i]]; return true; }
	}
	return false;
}

void run() {
	scanf("%d%d%d", &k, &A, &have);
	if (!solve()) { printf("-1\n"); return; }
	REPSZ(i, ans) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}