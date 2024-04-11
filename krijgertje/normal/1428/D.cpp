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
vector<pair<int, int>> ans;



bool solve() {
	ans.clear();
	queue<int> one, two;
	vector<int> top(n, -1);
	int y = n - 1;
	for (int x = n - 1; x >= 0; --x) {
		if (a[x] == 0) {
		} else if (a[x] == 1) {
			assert(y >= 0); ans.PB(MP(x, y)); top[x] = y; --y;
			one.push(x);
		} else if (a[x] == 2) {
			if (one.empty()) return false;
			int xx = one.front(); one.pop();
			ans.PB(MP(x, top[xx])); top[x] = top[xx];
			two.push(x);
		} else if (a[x] == 3) {
			int xx; if (!two.empty()) { xx = two.front(); two.pop(); } else if (!one.empty()) { xx = one.front(); one.pop(); } else return false;
			assert(y >= 0); ans.PB(MP(x, y)); ans.PB(MP(xx, y)); top[x] = top[xx] = y; --y;
			two.push(x);
		} else {
			assert(false);
		}
	}
	return true;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	if (!solve()) { printf("-1\n"); return; }
	printf("%d\n", SZ(ans));
	REPSZ(i, ans) printf("%d %d\n", ans[i].second + 1, ans[i].first + 1);
}

int main() {
	run();
	return 0;
}