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

const int MAXN = 500000;
const int MAXQ = 300000;
const int DX[] = { -1,0,+1,0 };
const int DY[] = { 0,+1,0,-1 };

int n;
char s[3][MAXN + 1];
int nq;
int ql[MAXQ], qr[MAXQ];
int qans[MAXQ];

int bad[MAXN], nbad;
int comp[3][MAXN], ncomp;
int prvcomp[MAXN], nxtcomp[MAXN];
int prvbad[MAXN], nxtbad[MAXN];
int wbad[MAXN];
int wbadsum[MAXN + 1];

void solve() {
	nbad = 0;
	REP(col, n) bad[col] = -1;
	REP(col, n) if (s[0][col] == '1' && s[1][col] == '0' && s[2][col] == '1') bad[col] = col - 1 >= 0 && bad[col - 1] >= 0 ? bad[col - 1] : nbad++;
	//printf("bad:"); REP(col, n) printf(" %d", bad[col]); puts("");

	ncomp = 0;
	REP(row, 3) REP(col, n) comp[row][col] = -1;
	REP(col, n) REP(row, 3) if (bad[col] == -1 && s[row][col] == '1' && comp[row][col] == -1) {
		queue<pair<int, int>> q;
		q.push(MP(row, col));
		comp[row][col] = ncomp++;
		//printf("(%d,%d)\n", row, col);
		while (!q.empty()) {
			int x = q.front().first, y = q.front().second; q.pop();
			//printf("\t(%d,%d)\n", x, y);
			REP(k, 4) {
				int nx = x + DX[k], ny = y + DY[k];
				if (nx < 0 || nx >= 3 || ny < 0 || ny >= n) continue;
				if (bad[ny] != -1 || s[nx][ny] != '1') continue;
				if (comp[nx][ny] != -1) continue;
				comp[nx][ny] = comp[x][y], q.push(MP(nx, ny));
			}
		}
	}
	REP(col, n) {
		prvcomp[col] = col - 1 >= 0 ? prvcomp[col - 1] : -1;
		REP(row, 3) if (comp[row][col] != -1) prvcomp[col] = col;
		prvbad[col] = col - 1 >= 0 ? prvbad[col - 1] : -1;
		if (bad[col] != -1) prvbad[col] = col;
	}
	for (int col = n - 1; col >= 0; --col) {
		nxtcomp[col] = col + 1 < n ? nxtcomp[col + 1] : n;
		REP(row, 3) if (comp[row][col] != -1) nxtcomp[col] = col;
		nxtbad[col] = col + 1 < n ? nxtbad[col + 1] : n;
		if (bad[col] != -1) nxtbad[col] = col;
	}
	//REP(row, 3) { printf("comp:"); REP(col, n) printf(" %2d", comp[row][col]); puts(""); }
	//printf("prvcomp:"); REP(col, n) printf(" %d", prvcomp[col]); puts("");
	//printf("nxtcomp:"); REP(col, n) printf(" %d", nxtcomp[col]); puts("");
	REP(col, n) if (bad[col] >= 0 && (col - 1 < 0 || bad[col - 1] == -1)) {
		int l = prvcomp[col], r = nxtcomp[col], id = bad[col];
		int top = (l != -1 && bad[l + 1] == id && s[0][l] == '1' ? 1 : 0) + (r != n && bad[r - 1] == id && s[0][r] == '1' ? 1 : 0);
		int bot = (l != -1 && bad[l + 1] == id && s[2][l] == '1' ? 1 : 0) + (r != n && bad[r - 1] == id && s[2][r] == '1' ? 1 : 0);
		//printf("id=%d l=%d r=%d top=%d bot=%d\n", id, l, r, top, bot);
		wbad[id] = (1 - top) + (1 - bot) + (top == 2 && bot == 2 ? 1 : 0);
	}
	wbadsum[0] = 0; REP(i, nbad) wbadsum[i + 1] = wbadsum[i] + wbad[i];
	//printf("wbad:"); REP(i, nbad) printf(" %d", wbad[i]); puts("");

	REP(i, nq) {
		int l = ql[i], r = qr[i];
		l = min(nxtbad[l], nxtcomp[l]);
		r = max(prvbad[r], prvcomp[r]);
		//printf("%d: %d..%d\n", i, l, r);
		if (l > r) { qans[i] = 0; continue; }
		int lbad = bad[l];
		int rbad = bad[r];
		if (nxtcomp[l] > r) {
			assert(bad[l] != -1 && bad[r] != -1);
			qans[i] = 2 * (bad[r] - bad[l] + 1);
			continue;
		}
		l = nxtcomp[l];
		r = prvcomp[r];
		assert(l <= r && bad[l] == -1 && bad[r] == -1);
		if (lbad != -1) {
			int m = prvbad[l];
			assert(m != -1 && bad[m]!=-1&& lbad <= bad[m]);
			qans[i] += 2 * (bad[m] - lbad);
			if (m != l - 1) {
				qans[i] += 2;
			} else {
				if (s[0][l] != '1') ++qans[i];
				if (s[2][l] != '1') ++qans[i];
			}
		}
		if (rbad != -1) {
			int m = nxtbad[r];
			assert(m != n && bad[m] != -1 && bad[m] <= rbad);
			qans[i] += 2 * (rbad - bad[m]);
			if (m != r + 1) {
				qans[i] += 2;
			} else {
				if (s[0][r] != '1') ++qans[i];
				if (s[2][r] != '1') ++qans[i];
			}
		}
		int lcomp = -1; REP(row, 3) if (comp[row][l] != -1) { if (lcomp != -1) assert(lcomp == comp[row][l]); lcomp = comp[row][l]; } assert(lcomp != -1);
		int rcomp = -1; REP(row, 3) if (comp[row][r] != -1) { if (rcomp != -1) assert(rcomp == comp[row][r]); rcomp = comp[row][r]; } assert(rcomp != -1);
		qans[i] += rcomp - lcomp + 1;
		lbad = nxtbad[l];
		rbad = prvbad[r];
		if (lbad <= rbad) qans[i] += wbadsum[bad[rbad] + 1] - wbadsum[bad[lbad]];
	}


}

void run() {
	scanf("%d", &n);
	REP(i, 3) scanf("%s", s[i]);
	scanf("%d", &nq);
	REP(i, nq) scanf("%d%d", &ql[i], &qr[i]), --ql[i], --qr[i];
	solve();
	REP(i, nq) printf("%d\n", qans[i]);
}

int main() {
	run();
	return 0;
}