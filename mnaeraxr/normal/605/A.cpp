#include <bits/stdc++.h>
#include <ext/algorithm>
#include <ext/numeric>

using namespace std;
using namespace __gnu_cxx;

#define endl '\n'

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	vector<int> dp(n);

	int ans = 0;

	for (int i = 0; i < n; ++i){
		int v; cin >> v;
		--v;
		if (v == 0) dp[v] = 1;
		else dp[v] = dp[v - 1] + 1;
		ans = max(ans, dp[v]);
	}

	cout << n - ans << endl;



	return 0;
}