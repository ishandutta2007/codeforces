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
int a[MAXN];
vector<pair<pair<int, int>, vector<ll>>> ans;

ll x[MAXN];

void solve() {
	ans.clear();
	if (n == 1) { ans.PB(MP(MP(0, 0), vector<ll>(1, 0))); ans.PB(MP(MP(0, 0), vector<ll>(1, 0))); ans.PB(MP(MP(0, 0), vector<ll>(1, -a[0]))); return; }
	REP(i, n) {
		x[i] = (ll)(a[i] % n) * (n - 1);
		assert((a[i] + x[i]) % n == 0);
	}
	vector<ll> d1(n - 1); REP(i, n - 1) d1[i] = x[i];
	vector<ll> d2(n - 1, 0); d2[n - 2] = x[n - 1];
	vector<ll> d3(n); REP(i, n) d3[i] = -(a[i] + x[i]);
	ans.PB(MP(MP(0, n - 2), d1));
	ans.PB(MP(MP(1, n - 1), d2));
	ans.PB(MP(MP(0, n - 1), d3));
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	solve();
	assert(SZ(ans) == 3);
	REPSZ(i, ans) { printf("%d %d\n", ans[i].first.first + 1, ans[i].first.second + 1); REPSZ(j, ans[i].second) { if (j != 0) printf(" "); printf("%lld", ans[i].second[j]); } puts(""); }
}

int main() {
	run();
	return 0;
}