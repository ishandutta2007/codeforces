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
char a[MAXN + 1];
char b[MAXN + 1];
vector<int> ans;

void solve() {
	ans.clear();
	int l = 0, r = n - 1, at = n - 1; bool flipped = false, inverted = false;
	while (at >= 0) {
		assert(l <= r);
		//printf("\tl=%d r=%d at=%d flipped=%s inverted=%s a=%s\n", l, r, at, flipped ? "yes" : "no", inverted ? "yes" : "no", a);
		int front, back;
		if (!flipped) front = l, back = r; else front = r, back = l;
		int have = a[back] - '0'; if (inverted) have = 1 - have;
		int want = b[at] - '0';
		if (have == want) { --at; if (!flipped) --r; else ++l; continue; }
		if (at == 0) { assert(l == r); ans.PB(1); flipped = !flipped; inverted = !inverted; continue; }
		int oth = a[front] - '0'; if (inverted) oth = 1 - oth;
		if (oth != want) { ans.PB(at + 1); if (!flipped) ++l; else --r; flipped = !flipped; inverted = !inverted; --at; } else { ans.PB(1); if (!flipped) a[l] ^= 1; else a[r] ^= 1; }
	}
}

void run() {
	scanf("%d", &n);
	scanf("%s", a); assert(strlen(a) == n);
	scanf("%s", b); assert(strlen(b) == n);
	solve();
	printf("%d", SZ(ans)); REPSZ(i, ans) printf(" %d", ans[i]); puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}