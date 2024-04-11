#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int64 oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; int64 c;
	cin >> n >> c;

	vector<int64> p(n + 1), s(n + 1);

	for (int i = 1; i <= n; ++i) cin >> p[i];
	for (int i = 1; i <= n; ++i) cin >> s[i];

	vector<int64> dp(n + 1, oo), prev(n + 1);
	dp[0] = 0;

	for (int i = 1; i <= n; ++i){
		dp.swap(prev);

		for (int j = 0; j <= i; ++j){
			dp[j] = j == 0 ? oo : prev[j - 1] + s[i];
			if (j < i) dp[j] = min(dp[j], prev[j] + p[i] + c * j);
		}
	}

	int64 answer = dp[0];

	for (int i = 1; i <= n; ++i)
		answer = min(answer, dp[i]);

	cout << answer << endl;


	return 0;
}