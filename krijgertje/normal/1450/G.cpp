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

const int MAXN = 5000;
const int MAXC = 20;

int n, num, den;
char s[MAXN + 1];
vector<char> ans;

int mp[26];
char c[MAXC]; int nc;
int a[MAXN];

int fst[MAXC], lst[MAXC], cnt[MAXC];

bool ok[1 << MAXC];
bool can[1 << MAXC];

void solve() {
	nc = 0; REP(i, 26) mp[i] = -1;
	REP(i, n) { int x = s[i] - 'a'; if (mp[x] == -1) c[nc] = 'a' + x, mp[x] = nc, nc++; a[i] = mp[x]; }

	REP(i, nc) fst[i] = INT_MAX, lst[i] = INT_MIN, cnt[i] = 0;
	REP(i, n) fst[a[i]] = min(fst[a[i]], i), lst[a[i]] = max(lst[a[i]], i), ++cnt[a[i]];

	//printf("c:"); REP(i, nc) printf(" %c", c[i]); puts("");
	FOR(mask, 1, 1 << nc) { 
		int maskfst = INT_MAX, masklst = INT_MIN, maskcnt = 0;
		REP(i, nc) if (mask&(1 << i)) maskfst = min(maskfst, fst[i]), masklst = max(masklst, lst[i]), maskcnt += cnt[i];
		ok[mask] = num*(masklst - maskfst + 1) <= maskcnt*den;
		//printf("%s[%x] [%d..%d] cnt=%d\n", ok[mask] ? "ok" : "fail", mask, maskfst, masklst, maskcnt);
	}
	can[0] = true;
	FOR(mask, 1, 1 << nc) {
		can[mask] = false;
		if (ok[mask]) REP(i, nc) if ((mask&(1 << i)) != 0 && can[mask ^ (1 << i)]) {
			can[mask] = true;
		}
		REP(i, nc) {
			int lmask = mask&((2 << i) - 1), rmask = mask^lmask;
			if (can[lmask] && can[rmask]) can[mask] = true;
		}
	}

	ans.clear();
	REP(i, nc) if (can[(1 << nc) - 1 - (1 << i)]) ans.PB(c[i]);
	sort(ans.begin(), ans.end());
}

void run() {
	scanf("%d%d%d", &n, &num, &den);
	scanf("%s", s); assert(strlen(s) == n);
	solve();
	printf("%d", SZ(ans)); REPSZ(i, ans) printf(" %c", ans[i]); puts("");
}

int main() {
	//int ncase; scanf("%d", &ncase); FORE(i, 1, ncase)
	run();
	return 0;
}