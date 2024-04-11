#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn = 300100;
const int maxk = 5010;
const int64 oo = 0x3f3f3f3f3f3f3f3f;

int64 v[maxn];
int64 dp[maxk][maxk];
bool memo[maxk][maxk];
int szl, szh;

int64 solve(int l, int h){
	if (max(l, h) == 0) return 0;
	int64 &val = dp[l][h];
	if (memo[l][h]) return val;
	memo[l][h] = true;
	int pos = l * szl + h * szh - 1;
	val = oo;
	if (l > 0) val = min(val, v[pos] - v[pos - szl + 1] + solve(l - 1, h));
	if (h > 0) val = min(val, v[pos] - v[pos - szh + 1] + solve(l, h - 1));
	return val;
}

int main()
{
#ifndef ONLINE_JUDGE
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; ++i){
		cin >> v[i];
	}

	sort(v, v + n);

	szl = n / k;
	szh = szl + (n % k != 0);
	int64 ans = solve(k - n % k, n % k);

	cout << ans << endl;

	return 0;
}