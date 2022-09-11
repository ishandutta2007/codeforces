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

const int MAXN = 1000000;
const int MAXOPT = MAXN / 2;

int n, nopt;
int a[MAXN];
int opt[MAXOPT];

ll solve() {
	int g = 0;
	REP(i, nopt) g = gcd(g, opt[i]);
	assert(g >= 1);
	ll no = 0, yes = 0;
	REP(offset, g) {
		vector<int> b;
		for (int i = offset; i < n; i += g) b.PB(a[i]);
		int cnt = 0, mn = INT_MAX;
		for (int x : b) {
			if (x < 0) ++cnt;
			mn = min(mn, abs(x));
		}
		if (cnt % 2 == 0) {
			yes += mn;
		} else {
			no += mn;
		}
	}
	ll sum = 0; REP(i, n) sum += abs(a[i]);
	return sum - 2 * min(no, yes);
}

void run() {
	scanf("%d%d", &n, &nopt);
	REP(i, n) scanf("%d", &a[i]);
	REP(i, nopt) scanf("%d", &opt[i]);
	printf("%lld\n", solve());
}

void research() {
	int a = 7, b = 9;
	int n = 18;
	vector<bool> seen(1 << n, false);
	queue<int> q;
	auto relax = [&](int mask) { if (!seen[mask]) seen[mask] = true, q.push(mask); };
	relax(0);
	int cnt = 0;
	while (!q.empty()) {
		int mask = q.front(); q.pop();
		++cnt;
		REPE(i, n - a) {
			int amask = (1 << a) - 1;
			relax(mask ^ (amask << i));
		}
		REPE(i, n - b) {
			int bmask = (1 << b) - 1;
			relax(mask ^ (bmask << i));
		}
	}
	printf("%d vs %d\n", cnt, 1 << n);
}

int main() {
	//research();
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}