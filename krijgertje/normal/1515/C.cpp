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

int nblock, ntower, lim;
int a[MAXN];
int ans[MAXN];

bool solve() {
	vector<int> sum(ntower, 0);
	priority_queue<pair<int, int>> pq;
	REP(i, ntower) pq.push(MP(-sum[i], i));
	REP(i, nblock) {
		int at = pq.top().second; pq.pop();
		ans[i] = at;
		sum[at] += a[i];
		pq.push(MP(-sum[at], at));
	}
	return true;
}

void run() {
	scanf("%d%d%d", &nblock, &ntower, &lim);
	REP(i, nblock) scanf("%d", &a[i]);
	if (!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	REP(i, nblock) { if (i != 0) printf(" "); printf("%d", ans[i] + 1); } puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}