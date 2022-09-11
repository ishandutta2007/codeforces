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

const int MAXQ = 200000;
const int MAXDIM = 1000000;

int h, w;
vector<string> g;
int nq;
int ql[MAXQ], qr[MAXQ];
bool qans[MAXQ];

bool bad[MAXDIM];
int cntbad[MAXDIM + 1];

void solve() {
	REP(y, w) bad[y] = false;
	REP(x, h) REP(y, w) if (x - 1 >= 0 && g[x - 1][y] == 'X' && y - 1 >= 0 && g[x][y - 1] == 'X') bad[y] = true;
	cntbad[0] = 0; REP(y, w) cntbad[y + 1] = cntbad[y] + (bad[y] ? 1 : 0);
	REP(i, nq) {
		int l = ql[i], r = qr[i];
		qans[i] = cntbad[r + 1] - cntbad[l + 1] == 0;
	}
}

void run() {
	scanf("%d%d", &h, &w);
	g = vector<string>(h);
	REP(x, h) cin >> g[x];
	scanf("%d", &nq);
	REP(i, nq) scanf("%d%d", &ql[i], &qr[i]), --ql[i], --qr[i];
	solve();
	REP(i, nq) printf("%s\n", qans[i] ? "YES" : "NO");
}

int main() {
	run();
	return 0;
}