#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int64,int64> pii;
typedef vector<int> vi;

const int maxn = 10010;

int64 p[maxn], t;
int64 dp[2][maxn];
pii bulb[maxn];

int64 dist(int64 x, int64 b, int64 e){
	if (b <= x && x <= e) return 0;
	return min(abs(x - b), abs(x - e));
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int64 x;
	cin >> n >> x;

	t = 0;

	p[t++] = x;

	for (int i = 1; i <= n; ++i){
		cin >> bulb[i].first >> bulb[i].second;
		p[t++] = bulb[i].first;
		p[t++] = bulb[i].second;
	}

	sort(p, p + t);
	t = unique(p, p + t) - p;

	int ttt1 = 0, ttt2 = 1;
	for (int i = 0; i < t; ++i)
		dp[ttt1][i] = abs(p[i] - x);

	for (int i = 1; i <= n; ++i){
		ttt1 ^= 1; ttt2 ^= 1;

		int64 cur = dp[ttt2][0] - p[0];
		for (int j = 0; j < t; ++j){
			cur = min(cur, dp[ttt2][j] - p[j]);
			dp[ttt1][j] = cur + p[j] + dist(p[j], bulb[i].first, bulb[i].second);
		}

		cur = dp[ttt2][t - 1];
		for (int j = t - 1; j >= 0; --j){
			cur = min(cur, dp[ttt2][j] - (p[t - 1] - p[j]));
			dp[ttt1][j] = min(dp[ttt1][j], cur + p[t - 1] - p[j] + dist(p[j], bulb[i].first, bulb[i].second));
		}

		// cout << "<" << bulb[i].first << ";" << bulb[i].second << ">" << endl;
		// for (int j = 0; j < t; ++j)
		// 	cout << p[j] << " " << dp[i][j] << endl;
	} 	

	int64 ans = dp[ttt1][0];
	for (int i = 0; i < t; ++i)
		ans = min(ans, dp[ttt1][i]);

	cout << ans << endl;

	return 0;
}