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
#include <array>
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
vector<array<int, 3>> ans;

int b[MAXN];

bool solve() {
	int sum = 0;
	REP(i, n) sum ^= a[i];
	if (n % 2 == 0 && sum != 0) return false;

	ans.clear();
	REP(i, n) b[i] = a[i];
	int at = 0;
	while (at + 2 < n) {
		ans.PB({ at,at + 1,at + 2 });
		int cur = b[at] ^ b[at + 1] ^ b[at + 2];
		b[at] = b[at + 1] = b[at + 2] = cur;
		at += 2;
	}
	if (at + 1 < n) assert(b[at] == b[at + 1]);
	while (at >= 2) {
		assert(b[at - 2] == b[at - 1]);
		ans.PB({ at - 2,at - 1,at });
		int cur = b[at - 2] ^ b[at - 1] ^ b[at];
		b[at - 2] = b[at - 1] = b[at] = cur;
		at -= 2;
	}
	//printf("b:"); REP(i, n) printf(" %d", b[i]); puts("");
	return true;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	if (!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	printf("%d\n", SZ(ans));
	REPSZ(i, ans) printf("%d %d %d\n", ans[i][0] + 1, ans[i][1] + 1, ans[i][2] + 1);
}

int main() {
	run();
	return 0;
}