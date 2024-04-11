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

int cap[2];
int cnt[2];
int w[2];

int solve() {
	if (w[0] > w[1]) swap(cnt[0], cnt[1]), swap(w[0], w[1]);
	int ret = 0;
	for (int i = 0; i <= cnt[0] && (ll)i * w[0] <= cap[0]; ++i) {
		int ii = min(cnt[1], (cap[0] - i * w[0]) / w[1]);
		int j = min(cnt[0] - i, cap[1] / w[0]);
		int jj = min(cnt[1] - ii, (cap[1] - j * w[0]) / w[1]);
		int cur = i + ii + j + jj;
		ret = max(ret, cur);
	}
	return ret;
}

void run() {
	scanf("%d%d", &cap[0], &cap[1]);
	scanf("%d%d", &cnt[0], &cnt[1]);
	scanf("%d%d", &w[0], &w[1]);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}