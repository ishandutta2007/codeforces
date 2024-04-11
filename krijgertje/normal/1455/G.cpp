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

const int MAXLINE = 200000;

int nline, forbidden;
string lineop[MAXLINE]; int lineval[MAXLINE], linecost[MAXLINE];

int match[MAXLINE];

struct State {
	map<int, ll> mp; ll delta;
	set<pair<ll, int>> ord;
	void init(int val, ll cost) { mp.clear(); ord.clear(); delta = 0; mp[val] = cost, ord.insert(MP(cost, val)); }
	void relax(int val, ll cost) { cost -= delta; auto it = mp.find(val); if (it != mp.end() && cost >= it->second) return; if (it != mp.end()) ord.erase(MP(it->second, it->first)); mp[val] = cost, ord.insert(MP(cost, val)); }
	void addglobal(ll cost) { delta += cost; }
	ll getmin() { if (SZ(ord) == 0) return LLONG_MAX; return ord.begin()->first + delta; }
	ll get(int val) { auto it = mp.find(val); if (it == mp.end()) return LLONG_MAX; return it->second + delta; }
	void remove(int val) { auto it = mp.find(val); if (it == mp.end()) return; ord.erase(MP(it->second, it->first)); mp.erase(it); }
};

State state[MAXLINE];

int merge(int a, int b) {
	if (SZ(state[a].mp) < SZ(state[b].mp)) swap(a, b);
	for (auto it = state[b].mp.begin(); it != state[b].mp.end(); ++it) state[a].relax(it->first, state[b].delta + it->second);
	return a;
}

void print(int a) {
	for (auto it = state[a].mp.begin(); it != state[a].mp.end(); ++it) printf(" %d=%lld", it->first, state[a].delta + it->second);
}

int go(int l, int r,int sval,ll scost) {
	int ret = l;
	state[ret].init(sval, scost);
	int at = l;
	while (at <= r) {
		if (lineop[at] == "set") {
			int cval = lineval[at]; ll dcost = linecost[at];
			ll cbest = state[ret].getmin();
			state[ret].addglobal(dcost);
			if (cval != forbidden) state[ret].relax(cval, cbest);
			++at;
		} else if (lineop[at] == "if") {
			int cval = lineval[at];  ll ccost = state[ret].get(cval);
			if (ccost != LLONG_MAX) {
				int sub = go(at + 1, match[at] - 1, cval, ccost);
				state[ret].remove(cval);
				ret = merge(ret, sub);
			}
			at = match[at] + 1;
		} else {
			assert(false);
		}
	}
	//printf("go(%d..%d,%d=%lld):", l, r, sval, scost); print(ret); puts("");
	return ret;
}


ll solve() {
	vector<int> stck;
	REP(i, nline) match[i] = -1;
	REP(i, nline) {
		if (lineop[i] == "if") stck.PB(i);
		if (lineop[i] == "end") { assert(SZ(stck) >= 1); int oth = stck.back(); stck.pop_back(); match[i] = oth, match[oth] = i; }
	}
	assert(SZ(stck) == 0);
	//printf("match:"); REP(i, nline) printf(" %d", match[i]); puts("");

	int res = go(0, nline - 1, 0, 0);
	return state[res].getmin();
}

void run() {
	scanf("%d%d", &nline, &forbidden);
	REP(i, nline) { cin >> lineop[i]; if (lineop[i] == "set") scanf("%d%d", &lineval[i], &linecost[i]); if (lineop[i] == "if") scanf("%d", &lineval[i]); }
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}