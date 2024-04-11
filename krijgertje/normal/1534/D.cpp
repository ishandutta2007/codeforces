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

const int MAXN = 2000;

int n;
vector<pair<int, int>> ans;

vector<int> query(int root) {
	printf("? %d\n", root + 1);
	fflush(stdout);
	vector<int> ret(n);
	REP(i, n) scanf("%d", &ret[i]);
	return ret;
}

void solve() {
	vector<int> dep = query(0);
	vector<int> parcnt(2, 0);
	REP(i, n) if (i != 0) ++parcnt[dep[i] % 2];
	int par = parcnt[0] <= parcnt[1] ? 0 : 1;
	ans.clear();
	REP(i, n) if (dep[i] == 1) ans.PB(MP(0, i));
	REP(i, n) if (i != 0 && dep[i] % 2 == par) {
		vector<int> cur = query(i);
		REP(j, n) if (j != 0 && cur[j] == 1) ans.PB(MP(i, j));
	}
	assert(SZ(ans) == n - 1);
}

void run() {
	scanf("%d", &n);
	solve();
	printf("!\n");
	REPSZ(i, ans) printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
	fflush(stdout);
}

int main() {
	run();
	return 0;
}