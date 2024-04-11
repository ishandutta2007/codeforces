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
const int MAXBIT = 60;

int n, nbit, mxone;
char s[MAXN][MAXBIT + 1];
char ans[MAXBIT + 1];



void solve() {
	int anscnt = 0;
	REP(i, nbit) ans[i] = '0';
	ans[nbit] = '\0';
	REP(rep, 30) {
		int who = rnd() % n;
		vector<int> lst;
		REP(bit, nbit) if (s[who][bit] == '1') lst.PB(bit);
		int m = SZ(lst);
		vector<int> cnt(1 << m, 0);
		REP(i, n) {
			int mask = 0;
			REPSZ(j, lst) if (s[i][lst[j]] == '1') mask |= 1 << j;
			++cnt[mask];
		}
		REP(bit, m) REP(mask, 1 << m) if (mask & (1 << bit)) cnt[mask ^ (1 << bit)] += cnt[mask];
		REP(mask, 1 << m) if (cnt[mask] >= (n + 1) / 2) {
			int maskcnt = 0;
			REP(i, m) if (mask & (1 << i)) ++maskcnt;
			if (maskcnt > anscnt) {
				anscnt = maskcnt;
				REP(i, nbit) ans[i] = '0';
				REP(i, m) if (mask & (1 << i)) ans[lst[i]] = '1';
			}
		}
	}
}

void run() {
	scanf("%d%d%d", &n, &nbit, &mxone);
	REP(i, n) scanf("%s", s[i]);
	solve();
	printf("%s\n", ans);
}

int main() {
	run();
	return 0;
}