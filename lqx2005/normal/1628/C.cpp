#include <bits/stdc++.h>
#define x first
#define y second
#define sz(a) int((a).size())
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define mid ((l + r) >> 1)
#define ls (p + 1)
#define rs (p + ((mid - l + 1) << 1))
using namespace std;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;
typedef double db;
const int N = 1e3 + 10;
int n, a[N][N], vis[N * N], id[N][N], tot = 0, order[N * N];
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
vector<int> s[N * N];
void solve() {
	cin >> n;
	for(int i = 1; i <= n * n; i++) vis[i] = 0, s[i].clear();
	tot = 0;
	for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) cin >> a[i][j], id[i][j] = ++tot;
	for(int x = 1; x <= n; x++) {
		for(int y = 1; y <= n; y++) {
			for(int k = 0; k < 4; k++) {
				int nx = x + dx[k], ny = y + dy[k];
				if(nx < 1 || nx > n || ny < 1 || ny > n) continue;
				s[id[x][y]].push_back(id[nx][ny]);
			}
			sort(s[id[x][y]].begin(), s[id[x][y]].end());
		}
	}
	for(int i = 1; i <= tot; i++) order[i] = i;
	sort(order + 1, order + tot + 1, [&](int a, int b) {return s[a] < s[b]; });
	int ans = 0;
	for(int i = 1; i <= tot; i++) {
		int u = order[i];
		int x = (u - 1) / n + 1, y = (u - 1) % n + 1;
		if(vis[s[u].front()]) continue;
		ans ^= a[x][y];
		for(int x : s[u]) vis[x] ^= 1;
	}
	// for(int i = 1; i <= n * n; i++) cout << vis[i] <<" ";
	// cout << endl;
	cout << ans << endl;
	return;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t;
	for(cin >> t; t--; solve());
	return 0;
}