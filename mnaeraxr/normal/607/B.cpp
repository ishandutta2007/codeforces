#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 510;

int v[maxn];
int dp[maxn][maxn];

int solve(int b, int e){
	if (e <= b) return 1;
	if (dp[b][e]) return dp[b][e];
	int &ans = dp[b][e];
	ans = e - b + 1;
	if (v[b] == v[e]) ans = min(ans, solve(b + 1, e - 1));
	for (int i = b; i < e; ++i)
		ans = min(ans, solve(b, i) + solve(i + 1, e));
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	cout << solve(0, n - 1) << endl;

	return 0;
}