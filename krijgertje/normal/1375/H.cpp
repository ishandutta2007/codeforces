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

const int MAXN = 1 << 12;
const int MAXQ = 1 << 16;
const int MAXCNT = 2200000;
const int MAXB = MAXN;

int n, nq;
int a[MAXN];
int ql[MAXQ], qr[MAXQ], qans[MAXQ];
pair<int, int> how[MAXCNT]; int cnt;

int pos[MAXN];

int bsz, nb;
int bl[MAXB], br[MAXB];
int bfst[MAXB][MAXN], blst[MAXB][MAXN];
int id[MAXN];
vector<vector<int>> bseg[MAXB];

int merge(int a, int b) {
	assert(cnt < MAXCNT);
	int ret = cnt++;
	how[ret] = MP(a, b);
	return ret;
}

vector<vector<int>> rec(int b, int l, int r,const vector<int> &who) {
	int sz = SZ(who);
	vector<vector<int>> ret(sz, vector<int>(sz, -1));
	if (l == r) {
		assert(sz == 1 && a[who[0]] == l);
		ret[0][0] = who[0];
	} else {
		int m = l + (r - l) / 2;
		vector<int> lidx(sz, -1), ridx(sz, -1), lwho, rwho;
		REP(i, sz) { int id = who[i]; if (a[id] <= m) lidx[i] = SZ(lwho), lwho.PB(id); else ridx[i] = SZ(rwho), rwho.PB(id); }
		vector<vector<int>> lres = rec(b, l, m, lwho);
		vector<vector<int>> rres = rec(b, m + 1, r, rwho);
		REP(i, sz) {
			int lmn = SZ(lwho), lmx = -1, rmn = SZ(rwho), rmx = -1;
			FOR(j, i, sz) {
				int id = who[j];
				if (a[id] <= m) lmn = min(lmn, lidx[j]), lmx = max(lmx, lidx[j]); else rmn = min(rmn, ridx[j]), rmx = max(rmx, ridx[j]);
				int a = lmn <= lmx ? lres[lmn][lmx] : -1, b = rmn <= rmx ? rres[rmn][rmx] : -1;
				if (a != -1 && b != -1) ret[i][j] = merge(a, b); else if (a != -1) ret[i][j] = a; else if (b != -1) ret[i][j] = b; else assert(false);
			}
		}
	}
	//printf("rec(%d,%d,%d,[", b, l, r); REPSZ(i, who) { if (i != 0) printf(","); printf("%d", who[i]); } printf("])=["); REP(i, sz) FOR(j, i, sz) { if (i != 0 || j != 0) printf(","); printf("%d", ret[i][j]); } printf("]\n");
	return ret;
}

void solve() {
	cnt = n;
	REP(i, n) pos[a[i]] = i;
	bsz = min(n, (int)sqrt(2.0*nq));
	nb = (n + bsz - 1) / bsz;
	//printf("bsz=%d nb=%d\n", bsz, nb);
	REP(b, nb) bl[b] = b*bsz, br[b] = min((b + 1)*bsz, n) - 1;
	REP(b, nb) for (int i = n - 1; i >= 0; --i) bfst[b][i] = bl[b] <= a[i] && a[i] <= br[b] ? i : i + 1 < n ? bfst[b][i + 1] : n;
	REP(b, nb) REP(i, n) blst[b][i] = bl[b] <= a[i] && a[i] <= br[b] ? i : i - 1 >= 0 ? blst[b][i - 1] : -1;
	REP(b, nb) {
		vector<int> who; REP(i, n) if (bl[b] <= a[i] && a[i] <= br[b]) who.PB(i);
		REPSZ(i, who) id[who[i]] = i;
		bseg[b] = rec(b, bl[b], br[b], who);
	}

	REP(i, nq) {
		vector<int> parts;
		REP(b, nb) {
			int l = bfst[b][ql[i]];
			int r = blst[b][qr[i]];
			if (l > r) continue;
			//printf("q%d b%d: %d..%d -> %d..%d = %d\n", i, b, l, r, id[l], id[r], bseg[b][id[l]][id[r]]);
			parts.PB(bseg[b][id[l]][id[r]]);
		}
		assert(SZ(parts) >= 1);
		qans[i] = parts[0]; FORSZ(j, 1, parts) qans[i] = merge(qans[i], parts[j]);
	}
}

void run() {
	scanf("%d%d", &n, &nq);
	REP(i, n) scanf("%d", &a[i]), --a[i];
	REP(i, nq) scanf("%d%d", &ql[i], &qr[i]), --ql[i], --qr[i];
	solve();
	printf("%d\n", cnt);
	FOR(i, n, cnt) printf("%d %d\n", how[i].first + 1, how[i].second + 1);
	REP(i, nq) { if (i != 0) printf(" "); printf("%d", qans[i] + 1); } puts("");
}

int main() {
	run();
	return 0;
}