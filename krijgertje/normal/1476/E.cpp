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

const int MAXPAT = 100000;
const int MAXQ = 100000;
const int MAXLEN = 4;

int npat, nq, len;
char pat[MAXPAT][MAXLEN + 1];
char qs[MAXQ][MAXLEN + 1]; int qwant[MAXQ];
int ans[MAXPAT];

vector<int> adj[MAXPAT];

int top[MAXPAT], topidx[MAXPAT], ntop;
bool dfstop(int at) {
	topidx[at] = -2;
	REPSZ(i, adj[at]) {
		int to = adj[at][i];
		if (topidx[to] == -2) return false;
		if (topidx[to] == -1) if (!dfstop(to)) return false;
	}
	topidx[at] = ntop, top[ntop] = at, ++ntop;
	return true;
}

bool solve() {
	REP(i, npat) adj[i].clear();
	map<string, int> mp;
	REP(i, npat) mp[pat[i]] = i;
	REP(i, nq) {
		bool found = false;
		REP(mask, 1 << len) {
			string cur = qs[i];
			REP(j, len) if (mask & (1 << j)) cur[j] = '_';
			auto it = mp.find(cur);
			int idx = it == mp.end() ? -1 : it->second;
			if (idx == -1) continue;
			//printf("i=%d mask=%x -> idx=%d (want=%d)\n", i + 1, mask, idx + 1, qwant[i] + 1);
			if (idx == qwant[i]) found = true; else adj[idx].PB(qwant[i]);
		}
		if (!found) return false;
	}
	//REP(at, npat) for (int to : adj[at]) printf("%d->%d\n", at + 1, to + 1);

	ntop = 0; REP(i, npat) topidx[i] = -1;
	REP(i, npat) if (topidx[i] == -1) if (!dfstop(i)) return false;
	REP(i, npat) ans[i] = top[i];
	return true;
}

void run() {
	scanf("%d%d%d", &npat, &nq, &len);
	REP(i, npat) scanf("%s", pat[i]);
	REP(i, nq) scanf("%s%d", &qs[i], &qwant[i]), --qwant[i];
	if (!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	REP(i, npat) { if (i != 0) printf(" "); printf("%d", ans[i] + 1); } puts("");

}

int main() {
	//int ncase; scanf("%d", &ncase); FORE(i, 1, ncase)
	run();
	return 0;
}