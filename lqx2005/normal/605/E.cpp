#include <bits/stdc++.h>
#define par pair<int, int>
#define x first
#define y second
#define mp make_pair
#define sz(a) int((a).size())
#define poly vector<int>
using namespace std;
typedef double db;
typedef long long i64;
const int N = 1e3 + 10;
int n, vis[N];
db p[N][N], dp[N], sum[N], prod[N];

void release(int u) {
	for(int i = 1; i <= n; i++) {
		sum[i] += prod[i] * p[i][u] * dp[u];
		prod[i] *= 1 - p[i][u];
	}
	return;
}

db f(int u) {return (sum[u] + 1) / (1 - prod[u]); }

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	cout << fixed, cout.precision(20);
	for(int i = 1; i <= n; i++) prod[i] = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			int x;
			cin >> x;
			p[i][j] = x / 100.0;
		}
	}
	vis[n] = 1, dp[n] = 0;
	release(n);
	for(; !vis[1];) {
		int id = 1;
		for(int j = 2; j <= n; j++) if(!vis[j] && f(j) < f(id)) id = j;
		dp[id] = f(id);
		vis[id] = 1;
		release(id);
	}
	cout << dp[1] << endl;
    return 0;
}