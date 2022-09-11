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
char s[3][2*MAXN + 1];
char ans[3 * MAXN + 1];

void solve() {
	vector<vector<int>> who(2);
	REP(i, 3) {
		vector<int> cnt(2, 0);
		REP(j, 2 * n) ++cnt[s[i][j] - '0'];
		REP(par, 2) if (cnt[par] >= n) who[par].PB(i);
	}
	REP(par, 2) if (SZ(who[par]) >= 2) {
		int a = who[par][0], b = who[par][1];
		vector<vector<int>> amid(n + 1);
		int aat = 0;
		REP(i, 2 * n) if (aat < n && s[a][i] == '0' + par) ++aat; else amid[aat].PB(s[a][i] - '0');
		vector<vector<int>> bmid(n + 1);
		int bat = 0;
		REP(i, 2 * n) if (bat < n && s[b][i] == '0' + par) ++bat; else bmid[bat].PB(s[b][i] - '0');
		int anslen = 0;
		REPE(i, n) { 
			for (int x : amid[i]) ans[anslen++] = '0' + x; 
			for (int x : bmid[i]) ans[anslen++] = '0' + x;
			if (i < n) ans[anslen++] = '0' + par;
		}
		ans[anslen] = '\0';
		return;
	}
	assert(false);
}

void run() {
	scanf("%d", &n);
	REP(i, 3) scanf("%s", s[i]);
	solve();
	printf("%s\n", ans);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}