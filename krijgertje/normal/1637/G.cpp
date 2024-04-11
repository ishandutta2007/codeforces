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

const int MAXN = 50000;

int n;
vector<pair<int, int>> ans;

vector<pair<int, int>> reduce_to_powers_of_two(int n) {
	if (n == 0) return vector<pair<int, int>>();
	int mid = 1;
	while (2 * mid <= n) mid *= 2;
	int r = n, l = 2 * mid - r;
	vector<pair<int, int>> ret = reduce_to_powers_of_two(l - 1);
	int cnt = (r - l) / 2;
	REP(i, cnt) ret.PB(MP(l + i, r - i));
	vector<pair<int, int>> sub = reduce_to_powers_of_two(cnt);
	for (auto z : sub) ret.PB(MP(z.first * 2, z.second * 2));
	return ret;
}

bool solve() {
	if (n == 2) return false;
	int target = 1;
	while (target < n) target *= 2;

	ans = reduce_to_powers_of_two(n);
	multiset<int> have;
	FORE(i, 1, n) have.insert(i);
	for (auto z : ans) {
		int a = z.first, b = z.second;
		auto ait = have.find(a); assert(ait != have.end()); have.erase(ait);
		auto bit = have.find(b); assert(bit != have.end()); have.erase(bit);
		have.insert(a + b);
		have.insert(abs(a - b));
	}
	//printf("have:"); for (auto x : have) printf(" %d", x); puts("");

	vector<int> havelst(have.begin(), have.end());
	bool found = false;
	FORSZ(i, 1, havelst) if (havelst[i - 1] == havelst[i] && havelst[i] < target) {
		int x = havelst[i];
		ans.PB(MP(x, x));
		auto ait = have.find(x); assert(ait != have.end()); have.erase(ait);
		auto bit = have.find(x); assert(bit != have.end()); have.erase(bit);
		have.insert(2 * x);
		found = true;
		break;
	}
	if (!found) return false;

	while (!have.empty()) {
		int x = *have.begin();
		have.erase(have.begin());
		assert(x <= target);
		while (x < target) {
			ans.PB(MP(0, x));
			ans.PB(MP(x, x));
			x *= 2;
		}
		assert(x == target);
	}
	ans.PB(MP(0, target));
	
	return true;
}

void run() {
	scanf("%d", &n);
	if (!solve()) { printf("-1\n"); return; }
	printf("%d\n", SZ(ans));
	for (auto z : ans) printf("%d %d\n", z.first, z.second);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}