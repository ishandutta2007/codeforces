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

const int MAXQEXTRA = 420;

int h;
int n;

int query(int a, int b, int c) {
	printf("? %d %d %d\n", a + 1, b + 1, c + 1);
	fflush(stdout);
	int ret; scanf("%d", &ret); if (ret == -1) exit(0); else --ret;
	return ret;

}

int solve() {
	n = (1 << h) - 1;
	map<int, int> cntmap;
	REP(i, MAXQEXTRA) {
		int a, b, c;
		while (true) { a = rnd() % n, b = rnd() % n, c = rnd() % n; if (a == b || a == c || b == c) continue; break; }
		int x = query(a, b, c);
		++cntmap[x];
	}
	vector<pair<int, int>> cntlst;
	for (const pair<int, int>& x : cntmap) cntlst.PB(MP(x.second, x.first));
	sort(cntlst.begin(), cntlst.end());
	assert(SZ(cntlst) >= 2);
	int a = cntlst[SZ(cntlst) - 2].second, b = cntlst[SZ(cntlst) - 1].second;
	REP(i, n) if (i != a && i != b && query(a, b, i) == i) return i;
	assert(false); return -1;
}

void run() {
	scanf("%d", &h);
	int ans = solve();
	printf("! %d\n", ans + 1);
	fflush(stdout);
}

int main() {
	run();
	return 0;
}