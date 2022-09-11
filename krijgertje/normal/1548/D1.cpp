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

const int MAXN = 6000;
struct P { int x, y; };

int n;
P p[MAXN];


ll two(ll x) { return x * (x - 1) / 2; }
ll three(ll x) { return x * (x - 1) * (x - 2) / 6; }

ll solve() {
	vector<vector<int>> cnt(4, vector<int>(4, 0));
	REP(i, n) ++cnt[p[i].x % 4][p[i].y % 4];
	ll ret = 0;
	REP(i, 4) REP(j, 4) {
		ret += two(cnt[i][j]) * (n - cnt[i][j]);
		ret += three(cnt[i][j]);
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d%d", &p[i].x, &p[i].y);
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}