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

const int MAXN = 200000;
const int MAXQ = 200000;

int n, nq;
int a[MAXN];
int qs[MAXQ], qt[MAXQ];
bool qans[MAXQ];

int lst[MAXN], nlst;
int b[MAXN];
int fst[MAXN], last[MAXN];

void solve() {
	nlst = 0;
	REP(i, n) lst[nlst++] = a[i];
	sort(lst, lst + nlst);
	nlst = unique(lst, lst + nlst) - lst;
	REP(i, n) b[i] = lower_bound(lst, lst + nlst, a[i]) - lst;
	REP(i, nlst) fst[i] = INT_MAX, last[i] = INT_MIN;
	REP(i, n) {
		if (fst[b[i]] == INT_MAX) fst[b[i]] = i;
		last[b[i]] = i;
	}
	//REP(i, nlst) printf("%d [%d]: %d/%d\n", i, lst[i], fst[i], last[i]);
	REP(i, nq) {
		qans[i] = false;
		if (qs[i] == qt[i]) { qans[i] = true; continue; }
		int s = lower_bound(lst, lst + nlst, qs[i]) - lst;
		int t = lower_bound(lst, lst + nlst, qt[i]) - lst;
		if (s >= nlst || t >= nlst || lst[s] != qs[i] || lst[t] != qt[i]) continue;
		//printf("\t%d vs %d\n", fst[s], last[t]);
		if (fst[s] < last[t]) qans[i] = true;
	}
}

void run() {
	scanf("%d%d", &n, &nq);
	REP(i, n) scanf("%d", &a[i]);
	REP(i, nq) scanf("%d%d", &qs[i], &qt[i]);
	solve();
	REP(i, nq) printf("%s\n", qans[i] ? "YES" : "NO");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}