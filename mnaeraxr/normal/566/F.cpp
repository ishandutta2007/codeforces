#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn = 1000100;
int tot[maxn];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	for (int i = 0; i < n; ++i){
		int v; cin >> v;
		tot[v]++;
	}

	int ans = 0;
	for (int i = maxn - 1; i; --i){
		if (!tot[i]) continue;
		int dp = 0;
		for (int j = 2 * i; j < maxn; j += i)
			dp = max(dp, tot[j]);
		tot[i] += dp;
		ans = max(ans, tot[i]);
	}

	cout << ans << endl;

	return 0;
}