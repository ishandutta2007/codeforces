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
struct Exam { int kind, mandatoryat; };
bool operator<(const Exam& a, const Exam& b) { return a.mandatoryat < b.mandatoryat; }

int n, tmx, cost[2];
Exam exam[MAXN];

int cnt[2];

int solve() {
	sort(exam, exam + n);

	cnt[0] = cnt[1] = 0;
	REP(i, n) ++cnt[exam[i].kind];

	ll need = 0; int ret = 0;
	REPE(i, n) { // leave just before exam[i] becomes mandatory
		int t = i == n ? tmx : exam[i].mandatoryat - 1;
		if (need <= t) {
			int rem = t - need;
			int cur = i;
			int x = min(cnt[0], rem / cost[0]); cur += x; rem -= x * cost[0];
			int y = min(cnt[1], rem / cost[1]); cur += y; rem -= y * cost[1];
			ret = max(ret, cur);
		}
		if (i < n) {
			--cnt[exam[i].kind];
			need += cost[exam[i].kind];
		}
	}
	return ret;

}

void run() {
	scanf("%d%d%d%d", &n, &tmx, &cost[0], &cost[1]);
	REP(i, n) scanf("%d", &exam[i].kind);
	REP(i, n) scanf("%d", &exam[i].mandatoryat);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}