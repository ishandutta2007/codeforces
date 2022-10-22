#include <bits/stdc++.h>
#define broken cerr << "running on " << __FUNCTION__ <<" "<< __LINE__ << endl
#define x first
#define y second
#define sz(a) int((a).size())
#define pi pair<int, int>
#define i64 long long
#define u64 unsigned long long
#define db double
using namespace std;
const int N = 2e5 + 10;
int T, n, deg[N], dp[N];
vector<int> g[N];

int topsort() {
	static queue<int> q;
	for(int i = 1; i <= n; i++) {
		dp[i] = 0;
		if(deg[i] == 0) q.push(i);
	}
	int cnt = 0;
	for(; !q.empty(); ) {
		int u = q.front();
		q.pop();
		cnt++;
		for(int &v : g[u]) {
			dp[v] = max(dp[v], dp[u] + (u > v));
			deg[v]--;
			if(deg[v] == 0) q.push(v); 
		}
	}
	return cnt == n;
}

void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		g[i].clear(), deg[i] = 0;
	}
	for(int i = 1; i <= n; i++) {
		int m;
		cin >> m;
		deg[i] = m;
		for(int pre; m--; ) {
			cin >> pre;
			g[pre].push_back(i);
		}
	}
	if(!topsort()) cout << -1 << endl;
	else {
		int mx = 0;
		for(int i = 1; i <= n; i++) mx = max(mx, dp[i]);
		cout << mx + 1<< endl;
	}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	for(cin >> T; T--; ) solve();
	return 0;
}