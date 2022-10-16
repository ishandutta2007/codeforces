#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

vector<string> L[80][80];
int64 dp[80][80];

bool check_equal(int a, int b){
	for (auto s : L[a][b])
		if (s == "<" || s == ">") return false;
	for (auto s : L[b][a])
		if (s == "<" || s == ">") return false;
	return true;
}

bool check_less(int a, int b){
	for (auto s : L[a][b])
		if (s == ">=" || s == ">" || s == "=") return false;
	for (auto s : L[b][a])
		if (s == "<=" || s == "<" || s == "=") return false;
	return true;
}

int64 solve(int l, int r){
	if (dp[l][r] != -1) return dp[l][r];

	int64 &val = dp[l][r];
	val = 0;

	if (l + 1 == r){
		if (check_equal(l, r)) val = 1;
		else val = 0;
	}
	else{
		bool ok;

		// Case 1: Both on the left
		ok = true;
		if (!check_equal(l, l + 1)) ok = false;

		for (int i = l + 2; i <= r && ok; ++i){
			if (!check_less(l, i)) ok = false;
			if (!check_less(l + 1, i)) ok = false;
		}

		if (ok) val += solve(l + 2, r);

		// Case 2: Both on the right
		ok = true;
		if (!check_equal(r - 1, r)) ok = false;

		for (int i = l; i <= r - 2 && ok; ++i){
			if (!check_less(r, i)) ok = false;
			if (!check_less(r - 1, i)) ok = false;
		}

		if (ok) val += solve(l, r - 2);

		// Case 3: One on left, one on right
		ok = true;
		if (!check_equal(l, r)) ok = false;

		for (int i = l + 1; i <= r - 1 && ok; ++i){
			if (!check_less(l, i)) ok = false;
			if (!check_less(r, i)) ok = false;
		}

		if (ok) val += solve(l + 1, r - 1);
	}

	return val;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;	

	for (int i = 0; i < k; ++i){
		int u, v;
		string s;
		cin >> u >> s >> v;
		L[u][v].push_back(s);
	}

	memset(dp, -1, sizeof dp);
	cout << solve(1, 2 * n) << endl;

	return 0;
}