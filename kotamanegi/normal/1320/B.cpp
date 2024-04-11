#define  _CRT_SECURE_NO_WARNINGS
#pragma comment (linker, "/STACK:526000000")

#include "bits/stdc++.h"

using namespace std;
typedef string::const_iterator State;
#define eps 1e-11L
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL

#define MOD 998244353LL
#define seg_size 262144 * 2LL
#define pb push_back
#define mp make_pair
typedef long long ll;
#define REP(a,b) for(long long (a) = 0;(a) < (b);++(a))
#define ALL(x) (x).begin(),(x).end()

unsigned long xor128() {
	static unsigned long x = 123456789, y = 362436069, z = 521288629, w = time(NULL);
	unsigned long t = (x ^ (x << 11));
	x = y; y = z; z = w;
	return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}
void init() {
	iostream::sync_with_stdio(false);
	cout << fixed << setprecision(20);
}

#define int ll
int dp[300000];
vector<int> vertexs[300000];
vector<int> can_go[300000];
void solve(){
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> edges;
	REP(i, m) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		edges.push_back(mp(a, b));
	}
	vector<int> route;
	int query;
	cin >> query;
	REP(tea, query) {
		int a;
		cin >> a;
		a--;
		route.push_back(a);
	}
	REP(i, n) {
		dp[i] = 1e18;
	}
	dp[route.back()] = 0;
	REP(i, edges.size()) {
		vertexs[edges[i].second].push_back(edges[i].first);
		can_go[edges[i].first].push_back(edges[i].second);
	}
	queue<int> next_go;
	next_go.push(route.back());
	while (next_go.empty() == false) {
		int now = next_go.front();
		next_go.pop();
		for (auto x : vertexs[now]) {
			if (dp[x] > dp[now] + 1) {
				dp[x] = dp[now] + 1;
				next_go.push(x);
			}
		}
	}
	int ans[2] = {};
	for (int q = 0; q < route.size() - 1; ++q) {
		int now_min = 1e9;
		int cnt = 0;
		for (auto x : can_go[route[q]]) {
			if (now_min > dp[x]) {
				now_min = min(now_min, dp[x]);
				cnt = 0;
			}
			if (now_min == dp[x])cnt++;
		}
		if (dp[route[q + 1]] > now_min) {
			ans[0]++;
			ans[1]++;
			continue;
		}
		if (cnt > 1) {
			ans[1]++;
		}
	}
	cout << ans[0] << " " << ans[1] << endl;
}

#undef int

int main() {
	init();
	solve();
}