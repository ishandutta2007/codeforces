#include <iostream>
using namespace std;

const int N = 1e6;
int dp[N+1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	
	for (int i = 1; i <= n; ++i) {
		dp[i] = dp[i-1];
		if (a[i-1] != b[i-1]) ++dp[i];
		if (i > 1 && (a[i-1] == b[i-2]) && (a[i-2] == b[i-1])) dp[i] = min(dp[i], dp[i-2] + 1);
	}
	cout << dp[n] << '\n';
}