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

const int MAXN = 200000;

int n;
int a[MAXN];
char s[MAXN + 1];
pair<int, char> ans[MAXN];

bool solve() {
	sort(a, a + n);
	int nflip = 1;
	REP(i, n - 1) if (s[i] != s[i + 1]) ++nflip;
	int atsmall = n - nflip - 1, atbig = n - nflip;
	ll pos = 0;
	REP(i, n) {
		if (pos <= 0 && s[i] == 'R') {
			assert(atbig < n);
			int cur = a[atbig++];
			ans[i] = MP(cur, 'R');
			pos += cur;
			assert(pos > 0);
		} else if (pos >= 0 && s[i] == 'L') {
			assert(atbig < n);
			int cur = a[atbig++];
			ans[i] = MP(cur, 'L');
			pos -= cur;
			assert(pos < 0);
		} else if (pos > 0) {
			assert(atsmall >= 0);
			int cur = a[atsmall--];
			assert(atbig >= n || pos <= a[atbig] - cur - 1 || pos >= cur + 1);
			if (atbig >= n || pos <= a[atbig] - cur - 1) {
				ans[i] = MP(cur, 'R');
				pos += cur;
			} else {
				ans[i] = MP(cur, 'L');
				pos -= cur;
			}
			assert(pos > 0);
		} else {
			assert(atsmall >= 0);
			int cur = a[atsmall--];
			assert(atbig >= n || -pos <= a[atbig] - cur - 1 || -pos >= cur + 1);
			if (atbig >= n || -pos <= a[atbig] - cur - 1) {
				ans[i] = MP(cur, 'L');
				pos -= cur;
			} else {
				ans[i] = MP(cur, 'R');
				pos += cur;
			}
			assert(pos < 0);
		}
	}
	return true;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	scanf("%s", s);
	if (!solve()) { printf("-1\n"); return; }
	REP(i, n) printf("%d %c\n", ans[i].first, ans[i].second);
}

void stress() {
	REP(rep, 100000) {
		n = rnd() % 100 + 1;
		REP(i, n) a[i] = rnd() % 1000 + 1000;
		sort(a, a + n);
		REP(i, n) a[i] += i;
		REP(i, n) s[i] = rnd() % 2 == 0 ? 'L' : 'R';
		s[n] = '\0';
		solve();
		printf(".");
	}
}

int main() {
	run();
	//stress();
	return 0;
}