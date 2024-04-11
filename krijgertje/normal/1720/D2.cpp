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

const int MAXBIT = 29;
const int MAXN = 300000;
struct TNode { int ch[2]; int dp[2][2]; };

int n;
int a[MAXN];

TNode t[MAXN * (MAXBIT + 1)];
int nt, root;
int tmake() { int ret = nt++; t[ret].ch[0] = t[ret].ch[1] = -1; memset(t[ret].dp, 0, sizeof(t[ret].dp)); return ret; }

int dp[MAXN];

int solve() {
	nt = 0;
	root = tmake();
	REP(i, n) {
		int at = root;
		dp[i] = 1;
		for (int bit = MAXBIT; bit >= 0; --bit) {
			int xme = (i >> bit) & 1, yme = (a[i] >> bit) & 1, zme = xme ^ yme;
			int xhe = yme ^ 1, yhe = xme;
			dp[i] = max(dp[i], t[at].dp[xhe][yhe] + 1);
			at = t[at].ch[zme];
			if (at == -1) break;
		}
		at = root;
		for (int bit = MAXBIT; bit >= 0; --bit) {
			int xme = (i >> bit) & 1, yme = (a[i] >> bit) & 1, zme = xme ^ yme;
			t[at].dp[xme][yme] = max(t[at].dp[xme][yme], dp[i]);
			if (bit != 0 && t[at].ch[zme] == -1) t[at].ch[zme] = tmake();
			at = t[at].ch[zme];
		}
	}
	int ret = 0;
	REP(i, n) ret = max(ret, dp[i]);
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}