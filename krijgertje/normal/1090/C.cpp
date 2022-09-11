#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
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
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN = 100000;
struct Move { int from, to, kind; Move() {} Move(int from, int to, int kind) :from(from), to(to), kind(kind) {} };

int n, nkind;
vector<int> have[MAXN];
vector<Move> ans;

pair<int, int> o[MAXN];
int want[MAXN];

vector<int> calccanmove(vector<int> &a, vector<int> &b, int need) {
	vector<int> ret;
	int at = SZ(b) - 1;
	for (int i = SZ(a) - 1; i >= 0 && SZ(ret) < need; --i) {
		while (at >= 0 && b[at] > a[i]) --at;
		if (at >= 0 && b[at] == a[i]) continue;
		ret.PB(a[i]);
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

void remove(vector<int> &a, vector<int> &b) {
	if (SZ(b) == 0) return;
	int idx = SZ(a) - 1;
	while (idx > 0 && a[idx] >= b[0]) --idx;
	int n = idx;
	//printf("remove"); REPSZ(i, b) printf(" %d", b[i]); printf(" from"); REPSZ(i, a) printf(" %d", a[i]); puts("");
	//printf("idx=%d\n", idx);
	REPSZ(i,b) {
		while (idx < SZ(a) && a[idx] < b[i]) a[n++] = a[idx++];
		assert(idx < SZ(a) && a[idx] == b[i]);
		++idx;
	}
	while (idx < SZ(a)) a[n++] = a[idx++];
	a.resize(n);
}
vector<int> merge(vector<int> &a, vector<int> &b) {
	vector<int> ret;
	int ai = 0, bi = 0;
	while (ai < SZ(a) || bi < SZ(b)) {
		if (ai < SZ(a) && (bi >= SZ(b) || a[ai] <= b[bi])) ret.PB(a[ai++]); else ret.PB(b[bi++]);
	}
	return ret;
}

void solve() {
	REP(i, n) sort(have[i].begin(), have[i].end());
	REP(i, n) o[i] = MP(SZ(have[i]), i); sort(o, o + n);
	int tothave = 0; REP(i, n) tothave += SZ(have[i]);
	int each = tothave / n, extra = tothave%n; REP(i, n) want[i] = each; for (int i = 0; i < extra; ++i) ++want[n - i - 1];
	//printf("have:"); REP(i, n) printf(" %d", SZ(have[o[i].second])); puts("");
	//printf("want:"); REP(i, n) printf(" %d", want[i]); puts("");
	
	ans.clear();
	int lidx = 0, ridx = n - 1;
	while (lidx < ridx) {
		int l = o[lidx].second, r = o[ridx].second;
		if (SZ(have[l]) >= want[lidx]) { ++lidx; continue; }
		if (SZ(have[r]) <= want[ridx]) { --ridx; continue; }
		int nmove = min(want[lidx] - SZ(have[l]), SZ(have[r]) - want[ridx]);
		vector<int> tomove = calccanmove(have[r], have[l], nmove);
		//printf("move from %d to %d:", r + 1, l + 1); REPSZ(i, tomove) printf(" %d", tomove[i] + 1); puts("");
		REPSZ(i, tomove) ans.PB(Move(r, l, tomove[i]));
		remove(have[r], tomove);
		have[l] = merge(have[l], tomove);
	}
}

void run() {
	scanf("%d%d", &n, &nkind);
	REP(i, n) { int cnt; scanf("%d", &cnt); have[i] = vector<int>(cnt); REP(j, cnt) scanf("%d", &have[i][j]),--have[i][j]; }
	solve();
	printf("%d\n", SZ(ans));
	REPSZ(i, ans) printf("%d %d %d\n", ans[i].from + 1, ans[i].to + 1, ans[i].kind + 1);
}


int main() {
	run();
	return 0;
}