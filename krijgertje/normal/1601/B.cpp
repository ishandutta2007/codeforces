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

int n;
int a[MAXN + 1];
int b[MAXN + 1];
vector<int> ans;

bool solve() {
	set<int> todo;
	REP(i, n) todo.insert(i);
	queue<int> q;
	vector<int> dist(n + 1, INT_MAX);
	vector<int> prev(n + 1, -1);
	auto relax = [&](int to, int d, int at) { if (d >= dist[to]) return; dist[to] = d, prev[to] = at, q.push(to); };
	relax(n, 0, -1);
	while (!q.empty()) {
		int at = q.front(); q.pop();
		int mid = at + b[at]; assert(mid <= n);
		int l = max(0, mid - a[mid]), r = mid;
		while (true) {
			auto it = todo.lower_bound(l);
			if (it == todo.end() || *it > r) break;
			int to = *it;
			todo.erase(it);
			relax(to, dist[at] + 1, at);
		}
	}
	if (dist[0] == INT_MAX) return false;
	{
		ans.clear();
		int at = 0;
		while (at != n) {
			ans.PB(at);
			at = prev[at];
		}
		reverse(ans.begin(), ans.end());
	}
	return true;
}

void run() {
	scanf("%d", &n);
	FORE(i, 1, n) scanf("%d", &a[i]);
	FORE(i, 1, n) scanf("%d", &b[i]);
	if (!solve()) { printf("-1\n"); return; }
	printf("%d\n", SZ(ans));
	REPSZ(i, ans) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}