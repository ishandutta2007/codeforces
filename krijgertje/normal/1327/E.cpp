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

const int MAXN = 200000;
const int MOD = 998244353;
void inc(int& a, int b) { if ((a += b) >= MOD) a -= MOD; }
void dec(int& a, int b) { if ((a -= b) < 0) a += MOD; }

int n;
int ans[MAXN + 1];


int p10[MAXN + 1];

void solve() {
	p10[0] = 1; FORE(i, 1, n) p10[i] = (ll)p10[i - 1] * 10 % MOD;
	FORE(i, 1, n) ans[i] = (ll)(n - i + 1) * 10 % MOD * p10[n - i] % MOD;
	int sum = 0;
	int wsum = 0;
	for (int i = n; i >= 1; --i) {
		dec(ans[i], wsum);
		inc(wsum, sum);
		inc(wsum, ans[i]);
		inc(wsum, ans[i]);
		inc(sum, ans[i]);
	}
}

void run() {
	scanf("%d", &n);
	solve();
	FORE(i, 1, n) { if (i != 1) printf(" "); printf("%d", ans[i]); } puts("");
}


int main() {
	run();
	return 0;
}