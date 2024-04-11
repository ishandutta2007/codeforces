#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int64 oo = 0x3f3f3f3f3f3f3f3f;

int64 dp[31][31][51];
bool memo[31][31][51];

int64 solve(int a, int b, int k){
	// cout << "start: " << a << " " << b << " " << k << endl;
	if ((a * b == k) || k == 0){
		// cout << a << " " << b << " " << k << " 0" << endl;
	 	return 0;
	}
	if (a * b < k){
		// cout << a << " " << b << " " << k << " " << oo << endl;
	 	return oo;
	}

	if (memo[a][b][k]) return dp[a][b][k];
	memo[a][b][k] = true;
	int64 &ans = dp[a][b][k];

	int64 cur1 = oo;
	for (int i = 1; i < a; ++i){
		for (int j = 0; j < k; ++j)
			cur1 = min(cur1, solve(i, b, j) + solve(a - i, b, k - j) + 1LL * b * b);
	}
	ans = cur1;
	cur1 = oo;
	for (int i = 1; i < b; ++i){
		for (int j = 0; j < k; ++j)
			cur1 = min(cur1, solve(a, i, j) + solve(a, b - i, k - j) + 1LL * a * a);
	}
	ans = min(ans, cur1);

	// cout << a << " " << b << " " << k << " " << ans << endl;
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
	while (t--){
		int a, b, k;
		cin >> a >> b >> k;
		cout << solve(a, b, k) << endl;
	}

	return 0;
}