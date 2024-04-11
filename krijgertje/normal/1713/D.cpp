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

const int MAXROUND = 17;
const int MAXPLAYER = 1 << MAXROUND;

int nround;

bool local = false;
int localwins[MAXPLAYER];
int nq;

int query(int a, int b) {
	++nq;
	if (!local) {
		printf("? %d %d\n", a + 1, b + 1); fflush(stdout);
		int ret; scanf("%d", &ret); if (ret == -1) exit(0); return ret;
	} else {
		int aa = localwins[a], bb = localwins[b];
		if (aa != bb) return aa > bb ? 1 : 2; else return 0;
	}
}

int solve() {
	queue<pair<int, int>> q;
	int nplayer = 1 << nround;
	REP(i, nplayer / 2) q.push(MP(2 * i, 2 * i + 1));
	vector<int> opt;
	while (SZ(q) >= 2) {
		pair<int, int> a = q.front(); q.pop();
		pair<int, int> b = q.front(); q.pop();
		int res = query(a.first, b.first);
		if (res == 1) q.push(MP(a.first, b.second));
		if (res == 2) q.push(MP(b.first, a.second));
		if (res == 0) q.push(MP(a.second, b.second));
	}
	assert(SZ(q) == 1);
	{
		int a = q.front().first;
		int b = q.front().second;
		int res = query(a, b);
		if (res == 1) return a;
		if (res == 2) return b;
		assert(false);
		return -1;
	}
}

void run() {
	scanf("%d", &nround); if (nround == -1) exit(0);
	int ans = solve();
	printf("! %d\n", ans + 1); fflush(stdout);
}

void stress() {
	int mxn = 17;
	local = true;
	REP(rep, 10000) {
		nround = rnd() % mxn + 1;
		int nplayer = 1 << nround;
		queue<int> q;
		REP(i, nplayer) localwins[i] = 0, q.push(i);
		while (SZ(q) >= 2) {
			int a = q.front(); q.pop();
			int b = q.front(); q.pop();
			if (rnd() % 2 == 0) ++localwins[a], q.push(a); else ++localwins[b], q.push(b);
		}
		assert(SZ(q) == 1);
		int want = q.front();
		nq = 0;
		int have = solve();
		int lim = ((1 << (nround + 1)) + 2) / 3;
		if (have == want && nq <= lim) { printf("."); continue; }
		printf("err nq=%d lim=%d nround=%d nplayer=%d\n", nq, lim, nround, nplayer);
	}
}

int main() {
	//stress();
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}