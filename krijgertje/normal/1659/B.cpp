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

const int MAXN = 200000;

int n, nround;
char s[MAXN + 1];
char ans[MAXN + 1];
int cnt[MAXN];

void solve() {
	REPE(i, n) ans[i] = s[i];
	if (nround % 2 == 1) REP(i, n) ans[i] ^= 1;
	REP(i, n) cnt[i] = 0;
	int rem = nround;
	REP(i, n) if (rem > 0 && ans[i] == '0') {
		ans[i] ^= 1;
		++cnt[i];
		--rem;
	}
	if (rem % 2 == 1) ans[n - 1] ^= 1;
	cnt[n - 1] += rem;
	rem = 0;
}

void run() {
	scanf("%d%d", &n, &nround);
	scanf("%s", s);
	solve();
	printf("%s\n", ans);
	REP(i, n) { if (i != 0) printf(" "); printf("%d", cnt[i]); } puts("");

}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}