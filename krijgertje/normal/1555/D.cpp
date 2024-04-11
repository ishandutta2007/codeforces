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
const int MAXQ = 200000;

int n, nq;
char s[MAXN + 1];
int ql[MAXQ], qr[MAXQ];
int qans[MAXQ];

int cnt[3][MAXN + 3];

void solve() {
	REP(x, 3) { REP(i, 3) cnt[x][i] = 0; REP(i, n) cnt[x][i + 3] = cnt[x][i] + (s[i] == 'a' + x ? 1 : 0); }

	REP(i, nq) {
		string perm = "abc";
		int best = INT_MAX;
		int l = ql[i], r = qr[i];
		do {
			int cur = r - l + 1;
			REP(i, 3) if(i<=r-l) {
				int x = perm[i] - 'a';
				int t = (r - l - i) / 3;
				cur -= cnt[x][l + i + (t + 1) * 3] - cnt[x][l + i];
			}
			best = min(best, cur);
		} while (next_permutation(perm.begin(), perm.end()));
		qans[i] = best;
	}
}

void run() {
	scanf("%d%d", &n, &nq);
	scanf("%s", s);
	REP(i, nq) scanf("%d%d", &ql[i], &qr[i]), --ql[i], --qr[i];
	solve();
	REP(i, nq) printf("%d\n", qans[i]);
}

int main() {
	run();
	return 0;
}