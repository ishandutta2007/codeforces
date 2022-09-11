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

const int MAXN = 100000;

int n;
char s[MAXN + 1];
char ans[MAXN + 1];

void solve() {
	REP(i, n) ans[i] = '?'; ans[n] = '\0';
	if (s[0] != '9') {
		REP(i, n) ans[i] = '0' + (9 - (s[i] - '0'));
	} else {
		int carry = 0;
		for (int i = n - 1; i >= 0; --i) {
			int have = s[i] - '0' + carry;
			if (have <= 1) {
				ans[i] = '0' + (1 - have);
				carry = 0;
			} else {
				ans[i] = '0' + (11 - have);
				carry = 1;
			}
		}
		assert(carry == 1);
	}
}

void run() {
	scanf("%d", &n);
	scanf("%s", s);
	solve();
	printf("%s\n", ans);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}