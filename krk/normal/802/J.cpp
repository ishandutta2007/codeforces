#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>
using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLEN(i, line) for (int i = 0, l = strlen(line); i < l; i++)

typedef pair<int, int> pii;	

const int INF = 0x7FFFFFFF;	

void solve() {
	int n; scanf("%d ", &n);
	vector<vector<pii> > G(n);
	REP(i, n - 1) {
		int a, b, w; scanf("%d %d %d ", &a, &b, &w);
		G[a].push_back(pii(b, w));
		G[b].push_back(pii(a, w));
	}
	queue<int> q;
	q.push(0);
	vector<int> cost(n, INF);
	cost[0] = 0;
	int best = 0;
	while (!q.empty()) {
		int x = q.front(); q.pop();
		REP(i, G[x].size()) {
			int y = G[x][i].first;
			int w = G[x][i].second;
			if (cost[y] == INF) {
				cost[y] = cost[x] + w;
				best = max(best, cost[y]);
				q.push(y);
			}
		}
	}
	cout << best << endl;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.in", "rt", stdin);
		freopen("test.out", "wt", stdout);
	#endif
	solve();
	return 0;
}