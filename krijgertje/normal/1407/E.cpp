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

const int MAXN = 500000;
struct E { int from, to, col; };

int n, m;
vector<E> in[MAXN];
int ans[MAXN];

int d[MAXN][2];
priority_queue<pair<int, int>> pq;

int calc(int at) { return max(d[at][0], d[at][1]); }

int solve() {
	REP(i, n) REP(j, 2) d[i][j] = INT_MAX;
	d[n - 1][0] = d[n - 1][1] = 0;
	pq.push(MP(-calc(n - 1), n - 1));
	while (!pq.empty()) {
		int cost = -pq.top().first; int at = pq.top().second; pq.pop();
		if (calc(at) != cost) continue;
		REPSZ(i, in[at]) {
			int from = in[at][i].from, col = in[at][i].col;
			int was = calc(from);
			d[from][col] = min(d[from][col], cost + 1);
			int became = calc(from);
			if (became < was) pq.push(MP(-became, from));
		}
	}
	REP(i, n) ans[i] = d[i][0] >= d[i][1] ? 0 : 1;
	int ret = calc(0);
	return ret == INT_MAX ? -1 : ret;
}

void run() {
	scanf("%d%d", &n, &m);
	REP(i, m) { E e; scanf("%d%d%d", &e.from, &e.to, &e.col); --e.from, --e.to; in[e.to].PB(e); }
	int anslen = solve();
	printf("%d\n", anslen);
	REP(i, n) printf("%d", ans[i]); puts("");
}

int main() {
	run();
	return 0;
}