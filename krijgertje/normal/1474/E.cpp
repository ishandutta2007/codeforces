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

int n;
int p[MAXN];
vector<pair<int, int>> moves;
ll ans;

int cur[MAXN];

void verify() {
	REP(i, n) cur[i] = p[i];
	ll chk = 0;
	REPSZ(i, moves) {
		int a = moves[i].first, b = moves[i].second;
		//printf("checking %d %d\n", a + 1, b + 1);
		assert(cur[b] == a);
		chk += (ll)(b - a) * (b - a);
		swap(cur[a], cur[b]);
	}
	assert(chk == ans);
}

void solve() {
	// n-1-x>=x-1 -> x<=n/2
	if (n == 2) { p[0] = 1, p[1] = 0; moves.clear(); moves.PB(MP(1, 0)); ans = 1; return; }
	int x = n / 2;
	REP(i, n) p[i] = i - 1;
	p[0] = n - 2;
	p[x] = n - 1;
	p[n - 1] = x - 1;
	moves.clear();
	ans = 0;
	for (int a = n - 2; a >= x; --a) {
		moves.PB(MP(a, 0));
		ans += (ll)(a - 0) * (a - 0);
	}
	for (int a = x - 1; a >= 0; --a) {
		moves.PB(MP(a, n - 1));
		ans += (ll)(n - 1 - a) * (n - 1 - a);
	}
}

void run() {
	scanf("%d", &n);
	solve();
	printf("%lld\n", ans);
	REP(i, n) { if (i != 0) printf(" "); printf("%d", p[i] + 1); } puts("");
	printf("%d\n", SZ(moves));
	REPSZ(i, moves) printf("%d %d\n", moves[i].first + 1, moves[i].second + 1);
	//verify();
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}