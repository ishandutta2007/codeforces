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
int a[MAXN];
int ql[MAXQ], qr[MAXQ];
int qans[MAXQ];

int calc(int len, int x) {
	//printf("calc(%d,%d)\n", len, x);
	// 2*x<=len+1 -> 2*(x-y)<=(len-y)+1 -> y>=2*x-len-1
	int y = max(0, 2 * x - len - 1);
	return y + 1;
}

void solve() {
	int bsz = sqrt(1.0 * n);
	struct Q { int id, l, r, lblock; };
	vector<Q> q(nq);
	REP(i, nq) q[i].id = i, q[i].l = ql[i], q[i].r = qr[i], q[i].lblock = q[i].l / bsz;
	sort(q.begin(), q.end(), [&](const Q& a, const Q& b) { if (a.lblock != b.lblock) return a.lblock < b.lblock; return a.lblock % 2 == 0 ? a.r < b.r : a.r > b.r; });
	int l = 0, r = -1;
	vector<int> cnt(n, 0);
	vector<int> freq(n + 1, 0); freq[0] = n;
	int mxfreq = 0;
	auto mod = [&](int v, int by) {
		--freq[cnt[v]];
		cnt[v] += by;
		++freq[cnt[v]];
		if (by == -1 && freq[mxfreq] == 0) --mxfreq;
		if (by == +1 && freq[mxfreq + 1] != 0) ++mxfreq;
		//printf("cnt[%d]=%d [%d]\n", v + 1, cnt[v], mxfreq);
	};
	REPSZ(i, q) {
		while (l > q[i].l) mod(a[--l], +1);
		while (r < q[i].r) mod(a[++r], +1);
		while (l < q[i].l) mod(a[l++], -1);
		while (r > q[i].r) mod(a[r--], -1);
		qans[q[i].id] = calc(q[i].r - q[i].l + 1, mxfreq);
	}
}

void run() {
	scanf("%d%d", &n, &nq);
	REP(i, n) scanf("%d", &a[i]), --a[i];
	REP(i, nq) scanf("%d%d", &ql[i], &qr[i]), --ql[i], --qr[i];
	solve();
	REP(i, nq) printf("%d\n", qans[i]);
}

int main() {
	run();
	return 0;
}