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

const int MAXN = 300000;

int n, len;
int x[MAXN];
char dir[MAXN];
int ans[MAXN];

int a[MAXN];
pair<int, int> b[MAXN]; int nb;

void solve() {
	REP(i, n) a[i] = dir[i] == 'R' ? x[i] : len + (len - x[i]);
	//printf("a:"); REP(i, n) printf(" %d", a[i]); puts("");

	REP(i, n) ans[i] = -1;
	REP(par, 2) {
		nb = 0;
		REP(i, n) if (a[i] % 2 == par) b[nb++] = MP(x[i], i);
		sort(b, b + nb);
		vector<int> stck;
		REP(i, nb) {
			int at = b[i].second;
			if (dir[at] == 'R'||SZ(stck)==0) {
				stck.push_back(at);
			} else {
				int to = stck.back();
				stck.pop_back();
				ans[at] = ans[to] = dir[to] == 'R' ? (x[at] - x[to]) / 2 : (x[at] + x[to]) / 2;
			}
		}
		while (SZ(stck) >= 2) {
			int at = stck.back();
			stck.pop_back();
			int to = stck.back();
			stck.pop_back();
			ans[at] = ans[to] = dir[to] == 'R' ? ((len - x[at]) + (len - x[to])) / 2 : ((len - x[at]) + x[to] + len) / 2;
		}
	}
}

void run() {
	scanf("%d%d", &n, &len);
	REP(i, n) scanf("%d", &x[i]);
	REP(i, n) scanf(" %c", &dir[i]);
	solve();
	REP(i, n) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}