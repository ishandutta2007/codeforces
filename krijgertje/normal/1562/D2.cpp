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

const int MAXN = 300000;
const int MAXQ = 300000;

int n, nq;
char s[MAXN + 1];
int ql[MAXQ], qr[MAXQ];
vector<int> qans[MAXQ];

int sum[MAXN + 1];

void solve() {
	sum[0] = 0;
	REP(i, n) sum[i + 1] = sum[i] + (i % 2 == 0 ? +1 : -1) * (s[i] == '+' ? +1 : -1);
	//printf("sum:"); REPE(i, n) printf(" %d", sum[i]); puts("");
	int lo = 0, hi = 0;
	REPE(i, n) lo = min(lo, sum[i]), hi = max(hi, sum[i]);
	vector<vector<int>> pos(hi - lo + 1);
	REPE(i, n) pos[sum[i] - lo].PB(i);
	REP(i, nq) {
		int l = ql[i], r = qr[i];
		int len = r - l + 1;
		int diff = sum[r + 1] - sum[l];
		if (diff == 0) { qans[i] = vector<int>(0); continue; }
		qans[i] = { -1 };
		if (len % 2 == 0) {
			qans[i].PB(r);
			--r, --len;
			diff = sum[r + 1] - sum[l];
		}
		assert(diff % 2 != 0);
		int search = diff > 0 ? (diff + 1) / 2 : (diff - 1) / 2;
		int key = sum[l] + search - lo;
		int idx = lower_bound(pos[key].begin(), pos[key].end(), l) - pos[key].begin();
		assert(idx >= 0 && idx<SZ(pos[key]) && pos[key][idx]>l && pos[key][idx] <= r + 1);
		qans[i][0] = pos[key][idx] - 1;
	}
}

void run() {
	scanf("%d%d", &n, &nq);
	scanf("%s", s);
	REP(i, nq) scanf("%d%d", &ql[i], &qr[i]), --ql[i], --qr[i];
	solve();
	REP(i, nq) {
		printf("%d\n", SZ(qans[i]));
		REPSZ(j, qans[i]) { if (j != 0) printf(" "); printf("%d", qans[i][j] + 1); } puts("");
	}
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}