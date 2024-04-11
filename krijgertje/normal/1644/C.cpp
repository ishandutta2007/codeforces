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
#include <functional>
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

const int MAXN = 5000;

int n, x;
int a[MAXN];
int ans[MAXN + 1];

int b[MAXN + 1];
int c[MAXN + 1];

void solve() {
	b[0] = 0;
	REP(i, n) b[i + 1] = b[i] + a[i];
	c[0] = 0;
	REP(i, n) c[i + 1] = c[i] + a[i] + x;
	REPE(k, n) {
		ans[k] = INT_MIN;
		{
			int best = INT_MAX;
			REPE(i, n) {
				if (i >= k) {
					best = min(best, b[i - k]);
				}
				if (best != INT_MAX) ans[k] = max(ans[k], b[i] - best + k * x);
			}
		}
		{
			deque<int> q;
			REPE(i, n) {
				while (!q.empty() && c[i] < c[q.back()]) q.pop_back();
				q.push_back(i);
				while (!q.empty() && q.front() < i - k) q.pop_front();
				if (!q.empty()) ans[k] = max(ans[k], c[i] - c[q.front()]);
			}
		}
	}
}

void run() {
	scanf("%d%d", &n, &x);
	REP(i, n) scanf("%d", &a[i]);
	solve();
	REPE(i, n) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}