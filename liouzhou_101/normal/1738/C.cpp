#include <bits/stdc++.h>

using namespace std;

int u[111][111][2];
int dp[111][111][2];

int go(int x, int y, int z)
{
	if (x + y == 0)
		return z == 0;
	int& res = dp[x][y][z];
	if (u[x][y][z]) return res;
	u[x][y][z] = 1;
	if (x > 0)
		res |= 1 - go(x - 1, y, (z + y + 1) % 2);
	if (y > 0)
		res |= 1 - go(x, y - 1, (z + y + 1) % 2);
	return res;
}

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto& e : a) cin >> e;
	int x = 0, y = 0;
	for (auto e : a)
	{
		if (e % 2 == 0) x += 1; else y += 1;
	}
	int res = go(x, y, 0);
	cout << (res ? "Alice" : "Bob") << "\n";
}

int main()
{
	int tests = 1;
	cin >> tests;
	for (int test = 1; test <= tests; ++test)
		solve();
	return 0;
}