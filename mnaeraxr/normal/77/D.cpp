#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 300;
const int64 mod = 1000000007;

const char O = 'O';

char mp[maxn * 5][maxn * 5];
pii mat[maxn][maxn];
int64 dp[maxn];
bool ok[maxn];
int64 rdp[maxn];

pii read(int x, int y){
	int t = 0;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			if (mp[i + x][j + y] == O)
				++t;

	if (t == 2 || t == 3)
		return pii(t, mp[x][y] == O ? 1 : 2);
	else if (t == 6)
		return pii(t, mp[x][y + 1] == O ? 1 : 2);
	return pii(t, 0);
}

int64 solve(int c, int n){
	vector<int64> t(n);

	if (mat[0][c].second <= 1 && mat[0][c + 1].second <= 1)
		t[0] = 1;

	if (n == 1) return t[0];

	if (mat[1][c].second <= 1 && mat[1][c + 1].second <= 1)
		t[1] = t[0];

	if (mat[1][c].second != 1 && mat[0][c].second != 1 &&
		mat[1][c + 1].second != 1 && mat[0][c + 1].second != 1)
		t[1]++;

	for (int i = 2; i < n; ++i){
		if (mat[i][c].second <= 1 && mat[i][c + 1].second <= 1)
			t[i] = t[i - 1];

		if (mat[i][c].second != 1 && mat[i - 1][c].second != 1 &&
			mat[i][c + 1].second != 1 && mat[i - 1][c + 1].second != 1)
			t[i] = (t[i] + t[i - 2]) % mod;
	}

	return t.back() - (ok[c] && ok[c + 1]);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < 4 * n + 1; ++i)
		cin >> mp[i];

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			mat[i][j] = read(4 * i + 1, 4 * j + 1);

	if (n % 2 == 0){
		for (int j = 0; j < m; ++j){
			ok[j] = true;
			for (int i = 0; i < n && ok[j]; ++i)
				if (mat[i][j].second == 1) ok[j] = false;
		}
	}

	for (int i = 0; i + 1 < m; ++i){
		dp[i] = solve(i, n);
	}

	if (ok[0]) rdp[0] = 1;

	if (m > 1){
		if (ok[1]) rdp[1] = rdp[0];
		rdp[1] = (rdp[1] + dp[0]) % mod;

		for (int j = 2; j < m; ++j){
			if (ok[j]) rdp[j] = rdp[j - 1];
			rdp[j] = (rdp[j] + dp[j - 1] * rdp[j - 2] % mod) % mod;
		}
	}

	cout << rdp[m - 1] << endl;

	return 0;
}