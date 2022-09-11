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

const int MAXN = 100000;
const int MAXQ = 100000;
const int MAXVAL = 100000;
const int MAXLG = 16;

int n, nq;
int a[MAXN];
int ql[MAXQ], qr[MAXQ];
int qans[MAXQ];

int pmn[MAXVAL + 1];
int pnxt[MAXVAL + 1];
int anxt[MAXN];
int step[MAXN + 1];
int jump[MAXN + 1][MAXLG + 1];

void solve() {
	memset(pmn, -1, sizeof(pmn));
	FORE(i, 2, MAXVAL) if (pmn[i] == -1) for (int j = i; j <= MAXVAL; j += i) if (pmn[j] == -1) pmn[j] = i;
	
	memset(pnxt, -1, sizeof(pnxt));
	for (int i = n - 1; i >= 0; --i) {
		anxt[i] = n;
		int x = a[i];
		while (x != 1) { 
			int p = pmn[x]; 
			while (x % p == 0) x /= p;  
			if (pnxt[p] != -1) anxt[i] = min(anxt[i], pnxt[p]);
			pnxt[p] = i;
		}
	}
	step[n] = n;
	for (int i = n - 1; i >= 0; --i) step[i] = min(step[i + 1], anxt[i]);

	REPE(i, n) jump[i][0] = step[i];
	REP(k, MAXLG) REPE(i, n) jump[i][k + 1] = jump[jump[i][k]][k];

	REP(i, nq) {
		int l = ql[i], r = qr[i];
		qans[i] = 0;
		int at = l;
		for (int k = MAXLG; k >= 0; --k) if (jump[at][k] <= r) qans[i] += 1 << k, at = jump[at][k];
		++qans[i];
	}
}

void run() {
	scanf("%d%d", &n, &nq);
	REP(i, n) scanf("%d", &a[i]);
	REP(i, nq) scanf("%d%d", &ql[i], &qr[i]), --ql[i], --qr[i];
	solve();
	REP(i, nq) printf("%d\n", qans[i]);
}

int main() {
	run();
	return 0;
}