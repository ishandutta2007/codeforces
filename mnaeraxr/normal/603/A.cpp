#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;

const double EPS = 1e-9;
const int oo = 0x3f3f3f3;
const int maxn = (int)1e5 + 10;

int dp[maxn][2][3];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	string s; cin >> s;

	int v = s[0] - '0';
	dp[0][v][0] = 1;
	dp[0][v ^ 1][1] = 1;

	int ans = 1;

	for (int i = 1; i < n; ++i){
		int cur = s[i] - '0';
		for (int c = 0; c <= 1; ++c){
			dp[i][c][0] = dp[i - 1][c][0];
			if (c == cur) dp[i][c][0] = max(dp[i][c][0], dp[i - 1][c ^ 1][0] + 1);

			dp[i][c][1] = dp[i - 1][c][1];
			if (c != cur){
				dp[i][c][1] = max(dp[i][c][1], dp[i - 1][c ^ 1][1] + 1);
				dp[i][c][1] = max(dp[i][c][1], dp[i - 1][c ^ 1][0] + 1);
			}

			dp[i][c][2] = dp[i - 1][c][2];
			if (c == cur){
				dp[i][c][2] = max(dp[i][c][2], dp[i - 1][c ^ 1][1] + 1);
				dp[i][c][2] = max(dp[i][c][2], dp[i - 1][c ^ 1][2] + 1);
			}

			for (int k = 0; k < 3; ++k){
//				cout << i << " " << c << " " << k << " " << dp[i][c][k] << endl;
				ans = max(ans, dp[i][c][k]);
			}
		}
	}

	cout << ans << endl;

	return 0;
}