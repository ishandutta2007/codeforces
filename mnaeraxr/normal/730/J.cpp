#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

int dp[2][101][10001];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	vector<pii> V(n);
	int s = 0;

	for (int i = 0; i < n; ++i){
		cin >> V[i].second;
		s += V[i].second;
	}

	for (int i = 0; i < n; ++i)
		cin >> V[i].first;

	sort(V.begin(), V.end());
	reverse(V.begin(), V.end());

	int p = 0, c = 0;

	while (c < s)
		c += V[p++].first;

	for (int k = 0; k <= p; ++k)
		for (int t = 0; t <= s; ++t)
			dp[0][k][t] = dp[1][k][t] = -oo;

	dp[0][0][0] = 0;

	for (int i = 0; i < n; ++i){
		int a = V[i].second, b = V[i].first;
		for (int k = 0; k <= p; ++k)
			for (int t = 0; t <= s; ++t){
				dp[1][k][t] = max(dp[1][k][t], dp[0][k][t]);
				if (k < p) dp[1][k + 1][min(t + b, s)] = max(dp[1][k + 1][min(t + b, s)], dp[0][k][t] + a);
			}

		for (int k = 0; k <= p; ++k)
			for (int t = 0; t <= s; ++t){
				dp[0][k][t] = dp[1][k][t];
				dp[1][k][t] = -oo;
			}
	}

	cout << p << " " << s - dp[0][p][s] << endl;

	return 0;
}