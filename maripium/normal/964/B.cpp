#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, A, B, C, T;
int cnt[N];
int dp[N][N];

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(0);
	cin >> n >> A >> B >> C >> T;
	int ans = 0;
	for (int i = 1;i <= n;++i) {
		int t;	cin >> t;
		int cur = INT_MIN;
		for (int j = t;j <= T;++j) cur = max(cur, A + (C - B) * (j - t)); 
		ans += cur;	
	}
	cout << ans << endl;
}