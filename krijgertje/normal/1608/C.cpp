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

const int MAXN = 100000;

int n;
int a[MAXN];
int b[MAXN];
bool ans[MAXN];

int aord[MAXN];
int bord[MAXN];
int apos[MAXN];
int bpos[MAXN];

void solve() {
	REP(i, n) aord[i] = i;
	sort(aord, aord + n, [&](int i, int j) { return a[i] < a[j]; });
	REP(i, n) apos[aord[i]] = i;
	REP(i, n) bord[i] = i;
	sort(bord, bord + n, [&](int i, int j) { return b[i] < b[j]; });
	REP(i, n) bpos[bord[i]] = i;

	REP(i, n) ans[i] = false;
	int aat = n, ato = n - 1;
	int bat = n, bto = n - 1;
	while (aat > ato || bat > bto) {
		if (aat > ato) {
			--aat;
			int me = aord[aat];
			ans[me] = true;
			bto = min(bto, bpos[me]);
		} else {
			--bat;
			int me = bord[bat];
			ans[me] = true;
			ato = min(ato, apos[me]);
		}
	}
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	REP(i, n) scanf("%d", &b[i]);
	solve();
	REP(i, n) printf("%c", ans[i] ? '1' : '0'); puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}