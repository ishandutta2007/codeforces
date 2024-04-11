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

int n, len;
char s[MAXN + 1];
vector<pair<int, int>> ans;

int sum[MAXN + 1];

bool solve() {
	ans.clear();

	sum[0] = 0; REP(i, n) sum[i + 1] = sum[i] + (s[i] == '1' ? 1 : 0);
	int have = sum[n];
	ll num = (ll)len * have;
	int den = n;
	if (num % den != 0) return false;
	int want = num / den;

	REPE(i, n - len) if(sum[i+len]-sum[i]==want) {
		ans.PB(MP(i, i + len - 1));
		return true;
	}
	FOR(i, n - len + 1, n) if (sum[n] - sum[i] + sum[i + len - n] - sum[0] == want) {
		ans.PB(MP(0, i + len - n - 1));
		ans.PB(MP(i, n - 1));
		return true;
	}
	assert(false);
	return false;
}

void run() {
	scanf("%d%d", &n, &len);
	scanf("%s", s);
	if (!solve()) { printf("-1\n"); return; }
	printf("%d\n", SZ(ans));
	REPSZ(i, ans) printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}