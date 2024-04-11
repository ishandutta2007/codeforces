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

struct BIT {
	int n; vector<int> bit; int sum;
	void init(int _n) { n = _n; bit = vector<int>(n, 0); sum = 0; }
	void add(int idx, int val) { sum += val; while (idx < n) { bit[idx] += val; idx |= idx + 1; } }
	int prefixsum(int idx) { int ret = 0; while (idx >= 0) { ret += bit[idx]; idx = (idx & (idx + 1)) - 1; } return ret; }
	int suffixsum(int idx) { return sum - prefixsum(idx - 1); }
};

const int MAXN = 500000;

int n, initheight;
int skill[MAXN], neat[MAXN];

int v[2 * MAXN + 1], nv;
int dp[2 * MAXN + 1];


int solve() {
	nv = 0; v[nv++] = initheight; REP(i, n) v[nv++] = skill[i], v[nv++] = neat[i];
	sort(v, v + nv); nv = unique(v, v + nv) - v;
	initheight = lower_bound(v, v + nv, initheight) - v; REP(i, n) skill[i] = lower_bound(v, v + nv, skill[i]) - v; REP(i, n) neat[i] = lower_bound(v, v + nv, neat[i]) - v;

	REP(i, n) neat[i] = max(neat[i], initheight);
	vector<vector<int>> in(nv);
	REP(i, n) if (skill[i] >= initheight && skill[i] < neat[i]) in[neat[i]].PB(skill[i]);
	vector<vector<int>> start(nv), end(nv);
	REP(i, n) if (skill[i] >= neat[i]) start[neat[i]].PB(i), end[skill[i]].PB(i);

	BIT bit;
	bit.init(nv);
	REP(i, nv) {
		for (int idx : start[i]) bit.add(neat[idx], +1); // , printf("start %d\n", v[neat[idx]]);
		dp[i] = bit.sum;
		if (i - 1 >= 0) dp[i] = max(dp[i], dp[i - 1] + bit.suffixsum(i));
		for (int j : in[i]) dp[i] = max(dp[i], dp[j] + bit.suffixsum(j + 1) + 1);
		//printf("dp[%d]=%d\n", v[i], dp[i]);
		for (int idx : end[i]) bit.add(neat[idx], -1); // , printf("end %d\n", v[neat[idx]]);
	}
	return dp[nv - 1];
}

void run() {
	scanf("%d%d", &n, &initheight);
	REP(i, n) scanf("%d%d", &skill[i], &neat[i]);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}