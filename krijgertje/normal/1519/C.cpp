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
int uni[MAXN];
int skill[MAXN];
ll ans[MAXN + 1];

vector<ll> opt[MAXN];
vector<int> ord;

void solve() {
	REP(i, n) opt[i].clear();
	REP(i, n) opt[uni[i]].PB(skill[i]);
	REP(i, n) sort(opt[i].rbegin(), opt[i].rend());
	REP(i, n) { opt[i].insert(opt[i].begin(), 0); FORSZ(j, 1, opt[i]) opt[i][j] += opt[i][j - 1]; }
	//REP(i, n) { printf("opt%d:", i); REPSZ(j, opt[i]) printf(" %lld", opt[i][j]); puts(""); }
	ord = vector<int>(n);
	REP(i, n) ord[i] = i;
	sort(ord.begin(), ord.end(), [&](const int& a, const int& b) { return SZ(opt[a]) > SZ(opt[b]); });
	FORE(k, 1, n) {
		ans[k] = 0;
		for (int i : ord) {
			if (SZ(opt[i])-1 < k) break;
			int cnt = (SZ(opt[i]) - 1) / k * k;
			//printf("\t(%d,%d): cnt=%d -> %lld\n", k, i, cnt, opt[i][cnt]);
			ans[k] += opt[i][cnt];
		}
	}
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &uni[i]), --uni[i];
	REP(i, n) scanf("%d", &skill[i]);
	solve();
	FORE(i, 1, n) { if (i != 1) printf(" "); printf("%lld", ans[i]); } puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}