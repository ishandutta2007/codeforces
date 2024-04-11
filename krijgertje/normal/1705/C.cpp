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

const int MAXLEN = 200000;
const int MAXOP = 40;
const int MAXQ = 10000;

int slen, nop, nq;
char s[MAXLEN + 1];
ll op[MAXOP][2];
ll qidx[MAXQ];
char qans[MAXQ];

ll len[MAXOP + 1];

void solve() {
	len[0] = slen;
	REP(i, nop) len[i + 1] = len[i] + (op[i][1] - op[i][0] + 1);
	//printf("len:"); REPE(i, nop) printf(" %lld", len[i]); puts("");
	REP(i, nq) {
		ll idx = qidx[i];
		int at = nop;
		while (at > 0) {
			if (idx < len[at - 1]) { --at; continue; }
			ll offset = idx - len[at - 1];
			//printf("at=%d idx=%lld offset=%lld\n", at, idx, offset);
			ll opl = op[at - 1][0], opr = op[at - 1][1];
			assert(offset >= 0 && offset < opr - opl + 1);
			idx = opl + offset;
			assert(idx < len[at - 1]);
		}
		assert(idx >= 0 && idx < slen);
		qans[i] = s[idx];
	}
}

void run() {
	scanf("%d%d%d", &slen, &nop, &nq);
	scanf("%s", s);
	REP(i, nop) REP(j, 2) scanf("%lld", &op[i][j]), --op[i][j];
	REP(i, nq) scanf("%lld", &qidx[i]), --qidx[i];
	solve();
	REP(i, nq) printf("%c\n", qans[i]);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}