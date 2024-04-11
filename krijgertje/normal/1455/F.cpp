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

const int MAXN = 500;

int n, k;
char s[MAXN + 1];
char ans[MAXN + 1];

char cycimprove(char c) { if (c == 'a' || c == 'a' + k - 1) return 'a'; else return c - 1; }

void solve() {
	REP(i, n) ans[i] = '?'; ans[n] = '\0';
	int at = 0;
	while (at < n) {
		if (at - 1 >= 0) {
			if (s[at] < ans[at - 1] && (at + 1 >= n || s[at] <= s[at + 1])) {
				ans[at] = ans[at - 1], ans[at - 1] = s[at];
				++at;
				continue;
			} else if (at + 1 < n && s[at + 1] < ans[at - 1]) {
				ans[at] = ans[at - 1], ans[at - 1] = s[at + 1], ans[at + 1] = s[at];
				at += 2;
				continue;
			}
		}
		if (at + 1 >= n || cycimprove(s[at]) <= cycimprove(s[at + 1]) && (at + 2 >= n || cycimprove(s[at]) <= s[at + 2])) {
			ans[at] = cycimprove(s[at]);
			++at;
			continue;
		} else if (s[at + 1] == 'a') {
			ans[at + 1] = cycimprove(s[at]), ans[at] = s[at + 1];
			at += 2;
			continue;
		} else if (at + 2 >= n || cycimprove(s[at + 1]) <= s[at + 2]) {
			ans[at + 1] = s[at], ans[at] = cycimprove(s[at + 1]);
			at += 2;
			continue;
		} else {
			ans[at] = s[at + 2], ans[at + 1] = cycimprove(s[at]), ans[at + 2] = s[at + 1];
			at += 3;
			continue;
		}
	}
}

void run() {
	scanf("%d%d", &n, &k);
	scanf("%s", s); assert(strlen(s) == n);
	solve();
	printf("%s\n", ans);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}