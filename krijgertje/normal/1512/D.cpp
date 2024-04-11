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
int b[MAXN + 2];
int a[MAXN];

bool solve() {
	ll sum = 0;
	REP(i, n + 2) sum += b[i];
	map<ll, int> cnt;
	REP(i, n + 2) ++cnt[b[i]];
	REP(i, n + 2) {
		ll cur = sum - b[i];
		if (cur % 2 != 0) continue;
		cur /= 2;
		auto it = cnt.find(cur);
		if (it == cnt.end() || it->second == 1 && cur == b[i]) continue;
		int at = 0;
		bool seencur = false;
		REP(j, n + 2) {
			if (j == i) continue;
			if (b[j] == cur && !seencur) { seencur = true; continue; }
			a[at++] = b[j];
		}
		return true;
	}
	return false;
}

void run() {
	scanf("%d", &n);
	REP(i, n + 2) scanf("%d", &b[i]);
	if (!solve()) { printf("-1\n"); return; }
	REP(i, n) { if (i != 0) printf(" "); printf("%d", a[i]); } puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}