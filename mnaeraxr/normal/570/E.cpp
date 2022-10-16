#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn = 510;
const int64 mod = 1000000007;

int n, m;
char s[maxn][maxn];
int64 dp[2][maxn * 2][maxn * 2];

bool inside(int x, int y){
	return 0 <= x && x < n && 0 <= y && y < m;
}

bool check(int d1, int p1, int d2, int p2){
	int x1 = d1 - p1, y1 = p1;
	int x2 = d2 - p2, y2 = p2;
	return inside(x1, y1) && inside(x2, y2);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> s[i];

	int cur = 0, prev = 1;

	for (int i = (n + m - 2) / 2; i >= 0; --i){
		int d1 = i, d2 = n + m - 2 - i;
		for (int p1 = max(0, d1 - n + 1); p1 <= min(d1, m - 1); ++p1){
			for (int p2 = max(0, d2 - n + 1); p2 <= min(d2, m - 1); ++p2){
				int x1 = d1 - p1, y1 = p1;
				int x2 = d2 - p2, y2 = p2;
				int64 &val = dp[cur][p1][p2];
				val = 0;
				if (d1 == d2) val = (p1 == p2) ? 1 : 0;
				else if (s[x1][y1] != s[x2][y2]) val = 0;
				else if (d1 + 1 == d2) val = (abs(x1 - x2) + abs(y1 - y2) == 1) ? 1 : 0;
				else{
					val = 0;
					if (check(d1 + 1, p1, d2 - 1, p2)) val = (val + dp[prev][p1][p2]) % mod;
					if (check(d1 + 1, p1, d2 - 1, p2 - 1)) val = (val + dp[prev][p1][p2 - 1]) % mod;
					if (check(d1 + 1, p1 + 1, d2 - 1, p2)) val = (val + dp[prev][p1 + 1][p2]) % mod;
					if (check(d1 + 1, p1 + 1, d2 - 1, p2 - 1)) val = (val + dp[prev][p1 + 1][p2 - 1]) % mod;
				}
			}
		}
		cur ^= 1;
		prev ^= 1;
	}

	int64 ans = dp[prev][0][m - 1];

	cout << ans << endl;

	return 0;
}