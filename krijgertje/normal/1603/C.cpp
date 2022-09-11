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
const int MOD = 998244353;
void inc(int &a, int b) { if ((a += b) >= MOD) a -= MOD; }

int n;
int a[MAXN];

map<int, int> mem[MAXN];

int go(int idx, int val) {
	if (idx < 0) return 0;
	auto it = mem[idx].find(val);
	if (it != mem[idx].end()) return it->second;
	int parts = (a[idx] + val - 1) / val;
	int ret = (ll)(idx + 1) * (parts - 1) % MOD;
	int nval = a[idx] / parts;
	inc(ret, go(idx - 1, nval));
	return mem[idx][val] = ret;
}

int solve() {
	int ret = 0;
	int lim = sqrt(1.0 * a[0]);
	vector<int> dp1(lim + 1, 0);
	vector<int> dp2(lim + 1, 0);
	REP(i, n) {
		inc(ret, dp1[1]);
		if (i == n - 1) break;
		int nlim = sqrt(1.0 * a[i + 1]);
		vector<int> ndp1(nlim + 1);
		vector<int> ndp2(nlim + 1);
		FORE(j, 1, nlim) {
			int val = a[i + 1] / j;
			int parts = (a[i] + val - 1) / val;
			ndp1[j] = (ll)(i + 1) * (parts - 1) % MOD;
			if (parts > lim) assert(a[i] / parts <= lim);
			inc(ndp1[j], parts <= lim ? dp1[parts] : dp2[a[i] / parts]);
		}
		FORE(j, 1, nlim) {
			int val = j;
			int parts = (a[i] + val - 1) / val;
			ndp2[j] = (ll)(i + 1) * (parts - 1) % MOD;
			if (parts > lim) assert(a[i] / parts <= lim);
			inc(ndp2[j], parts <= lim ? dp1[parts] : dp2[a[i] / parts]);
		}
		lim = nlim, dp1 = ndp1, dp2 = ndp2;
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	printf("%d\n", solve());
}

void stress() {
	REP(rep, 1) {
		n = MAXN;
		//REP(i, n) a[i] = rnd() % 100000 + 1;
		REP(i, n) a[i] = 100000 - i;
		solve();
		printf(".");
	}
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	//stress();
	return 0;
}