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
const int ALPH = 20;

int n;
char a[MAXN + 1];
char b[MAXN + 1];

vector<int> out[ALPH];
vector<int> in[ALPH];
int comp[ALPH], ncomp;

int x[ALPH], nx;
int tox[ALPH];
int xoutmask[ALPH];
bool isdag[1 << ALPH];

int calccomp(int c) {
	nx = 0; REP(i, ALPH) tox[i] = -1;
	REP(i, ALPH) if (comp[i] == c) x[nx] = i, tox[i] = nx, ++nx;
	REP(i, nx) xoutmask[i] = 0;
	REP(i, nx) { int at = x[i]; REPSZ(j, out[at]) { int to = out[at][j]; int k = tox[to]; assert(k != -1); xoutmask[i] |= 1 << k; } }
	REP(mask, 1 << nx) {
		isdag[mask] = mask == 0;
		REP(i, nx) if (mask&(1 << i)) if ((mask&xoutmask[i]) == 0) isdag[mask] |= isdag[mask ^ (1 << i)];
		//if(nx>=3) printf("\t%x: %s\n", mask, isdag[mask] ? "ok" : "cyc");
	}
	int mxsz = 0;
	REP(mask, 1 << nx) if (isdag[mask]) { int cnt = 0; REP(i, nx) if (mask&(1 << i)) ++cnt; mxsz = max(mxsz, cnt); }
	//printf("%d (%d)\n", 2 * nx - 1 - mxsz, nx);
	//REP(i, nx) printf("\t%d: %x\n", i, xoutmask[i]);
	return 2 * nx - 1 - mxsz;
}

int solve() {
	REP(i, ALPH) out[i].clear(), in[i].clear();
	REP(i, n) {
		int x = a[i] - 'a', y = b[i] - 'a'; if (x == y) continue;
		out[x].PB(y); in[y].PB(x);
	}
	ncomp = 0; REP(i, ALPH) comp[i] = -1;
	REP(s, ALPH) if (comp[s] == -1) {
		comp[s] = ncomp++;
		queue<int> q; q.push(s);
		while (!q.empty()) {
			int at = q.front(); q.pop();
			REPSZ(i, out[at]) { int to = out[at][i]; if (comp[to] == -1) comp[to] = comp[at], q.push(to); }
			REPSZ(i, in[at]) { int to = in[at][i]; if (comp[to] == -1) comp[to] = comp[at], q.push(to); }
		}
	}
	int ret = 0;
	REP(i, ncomp) ret += calccomp(i);
	return ret;
}

void run() {
	scanf("%d", &n);
	scanf("%s", a); assert(strlen(a) == n);
	scanf("%s", b); assert(strlen(b) == n);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}