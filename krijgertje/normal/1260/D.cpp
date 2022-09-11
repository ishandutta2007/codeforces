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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXSOLDIER = 200000;
const int MAXX = 200000;
const int MAXTRAP = 200000;
const int MAXS = 4 * MAXX;

struct Trap { int l, r, danger; };
bool operator<(const Trap& a, const Trap& b) { return a.danger > b.danger; }

int nsoldier, nx, ntrap, tmax;
int a[MAXSOLDIER];
Trap t[MAXTRAP];

int sval[MAXS];
bool slazy[MAXS];

void sapply(int x) { sval[x] = 0, slazy[x] = true; }
void spush(int x) { if (slazy[x]) sapply(2 * x + 1), sapply(2 * x + 2), slazy[x] = false; }
void spull(int x) { sval[x] = sval[2 * x + 1] + sval[2 * x + 2]; }
void sinit(int x, int l, int r) {
	slazy[x] = false;
	if (l == r) {
		sval[x] = 1;
	} else {
		int m = l + (r - l) / 2;
		sinit(2 * x + 1, l, m); sinit(2 * x + 2, m + 1, r);
		spull(x);
	}
}
int sget(int x, int l, int r, int L, int R) {
	if (L <= l && r <= R) {
		return sval[x];
	} else {
		int m = l + (r - l) / 2; int ret = 0; spush(x);
		if (L <= m) ret += sget(2 * x + 1, l, m, L, R);
		if (m + 1 <= R) ret += sget(2 * x + 2, m + 1, r, L, R);
		return ret;
	}
}
void smod(int x, int l, int r, int L, int R) {
	if (L <= l && r <= R) {
		sapply(x);
	} else {
		int m = l + (r - l) / 2; spush(x);
		if (L <= m) smod(2 * x + 1, l, m, L, R);
		if (m + 1 <= R) smod(2 * x + 2, m + 1, r, L, R);
		spull(x);
	}
}

int solve() {
	sort(a, a + nsoldier); reverse(a, a + nsoldier);
	sort(t, t + ntrap); 
	int ret = 0;
	while (ret < nsoldier && (ntrap == 0 || a[ret] >= t[0].danger)) ++ret;
	int rem = tmax - (nx + 1);
	sinit(0, 1, nx);
	REP(i, ntrap) {
		int need = 2 * sget(0, 1, nx, t[i].l, t[i].r);
		//printf("[%d..%d] danger=%d -> need=%d\n", t[i].l, t[i].r, t[i].danger, need);
		if (need > rem) break;
		rem -= need;
		smod(0, 1, nx, t[i].l, t[i].r);
		while (ret < nsoldier && (i + 1 >= ntrap || a[ret] >= t[i + 1].danger)) ++ret;
	}
	return ret;
}

void run() {
	scanf("%d%d%d%d", &nsoldier, &nx, &ntrap, &tmax);
	REP(i, nsoldier) scanf("%d", &a[i]);
	REP(i, ntrap) scanf("%d%d%d", &t[i].l, &t[i].r, &t[i].danger);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}