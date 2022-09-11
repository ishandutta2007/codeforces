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

const int MAXN = 100000;
const int MAXQ = 1000000;

int n;
int a[MAXN];
int nq;
int qx[MAXQ], qy[MAXQ];
int qans[MAXQ];

vector<vector<int>> b;

vector<pair<int, int>> calcminsuffixes(const vector<int> &a) {
	int n = SZ(a);
	vector<pair<int, int>> ret(n); // (length, repeats)

	struct State {
		int lyndonlen;
		pair<int, int> lastfail; // (length, repeats)
		State() {} State(int lyndonlen, pair<int, int> lastfail) :lyndonlen(lyndonlen), lastfail(lastfail) {}
	};


	vector<State> state;
	state.PB(State(0, MP(0, 0)));
	int len = 0;
	REP(i, n) {
		while (true) {
			int lyndonlen = state[len].lyndonlen;
			int x = a[i - lyndonlen], y = a[i];
			if (len == 0 || y > x) { ++len; state.PB(State(len, MP(len, 1))); break; }
			if (y < x) { len %= lyndonlen; while (len + 1 < SZ(state)) state.pop_back(); continue; }
			++len; pair<int, int> lastfail = state[len - lyndonlen].lastfail; if (len % lyndonlen == 0) ++lastfail.second;
			state.PB(State(lyndonlen, lastfail)); break;
		}
		assert(SZ(state) == len + 1);
		//printf("\t%d:", i); FORSZ(j, 1, state) printf(" (%d,%d,%d)", state[j].lyndonlen, state[j].lastfail.first, state[j].lastfail.second); puts("");
		ret[i] = state[len].lastfail;
	}

	return ret;
}

vector<int> sim(const vector<int> &a, const vector<int> &use) {
	int n = SZ(a);
	vector<int> ret(n, -1);
	int at = 0;
	REP(i, n) {
		int len = min(n - at, i - use[i] + 1);
		REP(j, len) ret[at++] = a[use[i] + j];
	}
	return ret;
}

vector<int> calc(const vector<int> &a) {
	int n = SZ(a);
	vector<pair<int, int>> minsuff = calcminsuffixes(a);
	//printf("minsuff:"); REPSZ(i, minsuff) printf(" %d*%d", minsuff[i].second, minsuff[i].first); puts("");
	vector<int> use(n);
	for (int i = n - 1; i >= 0; --i) {
		int len = minsuff[i].first, times = minsuff[i].second;
		use[i] = i + 1 - (i + 1 >= n || use[i + 1] == i + 1 ? 1 : times) * len;
	}
	//printf("use:"); REPSZ(i, use) printf(" %d", use[i]); puts("");
	vector<int> ret = sim(a, use);
	//printf("ret:"); REPSZ(i, ret) printf(" %d", ret[i]); puts("");
	return ret;
}

void solve() {
	b.clear();
	b.push_back(vector<int>(a, a + n));
	while (true) {
		vector<int> d = calc(b.back());
		if (d == b.back()) break;
		b.push_back(d);
	}
	//REPSZ(i, b) { printf("b%d:", i); REPSZ(j, b[i]) printf(" %d", b[i][j] + 1); puts(""); }
	REP(i, nq) {
		int x = min(qx[i], SZ(b) - 1), y = qy[i];
		qans[i] = b[x][y];
	}
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]), --a[i];
	scanf("%d", &nq);
	REP(i, nq) scanf("%d%d", &qx[i], &qy[i]), qx[i], --qy[i];
	solve();
	REP(i, nq) printf("%d\n", qans[i] + 1);
}

int main() {
	run();
	return 0;
}