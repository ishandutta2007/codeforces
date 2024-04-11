#include<bits/stdc++.h>
#define sz(a) int((a).size())
#define x first
#define y second
#define PI pair<int, int> 
#define VI vector<int>
#define db double
#define i64 long long
#define u64 unsigned long long
using namespace std;
const int N = 3000 + 10;
int n, k;
vector<i64> s[N];
i64 dp[N << 2][N];
i64 ans = 0;
void dfs(int p, int l, int r) {
	if(l == r) {
		for(int i = 0; i <= k && i < sz(s[l]); i++) {
			ans = max(ans, s[l][i] + dp[p][k - i]);
		}
		return;
	}
	int mid = (l + r) / 2;
	int ls = p << 1, rs = p << 1 | 1;
	memcpy(dp[rs], dp[p], sizeof(dp[p]));
	memcpy(dp[ls], dp[p], sizeof(dp[p]));
	for(int i = l; i <= mid; i++) {
		for(int j = k; j >= sz(s[i]) - 1; j--) {
			dp[rs][j] = max(dp[rs][j], dp[rs][j - (sz(s[i]) - 1)] + s[i].back());
		}
	}
	for(int i = mid + 1; i <= r; i++) {
		for(int j = k; j >= sz(s[i]) - 1; j--) {
			dp[ls][j] = max(dp[ls][j], dp[ls][j - (sz(s[i]) - 1)] + s[i].back());
		}
	}
	dfs(ls, l, mid), dfs(rs, mid + 1, r);
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		int m;
		cin >> m;
		s[i].resize(m + 1);
		for(int j = 1; j <= m; j++) {
			cin >> s[i][j];
			s[i][j] += s[i][j - 1];
		}
	}
	dfs(1, 1, n);
	cout << ans << endl;
	return 0;
}