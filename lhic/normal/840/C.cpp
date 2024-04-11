#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
        cerr << (*i) << " ";
    }
    cerr << "\n";
}

const ll MOD = 1e9 + 7;
const int MX = 1000;
ll a[400];
int n;
map<ll, int> mm;

ll cnk[MX][MX];
ll dp[MX];
ll dp2[MX];
vector<int> vv;

void add(ll &a, ll b) {
	a += b;
	a %= MOD;
}

int main() {
	for (int i = 0; i < MX; ++i)
		for (int j = 0; j < MX; ++j) {
			if (i == j || j == 0)
				cnk[i][j] = 1;
			else if (j > i)
				cnk[i][j] = 0;
			else
				cnk[i][j] = (cnk[i - 1][j] + cnk[i - 1][j - 1]) % MOD;
		}
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		for (int j = 2; j * j <= a[i]; ++j) {
			while (a[i] % (j * j) == 0)
				a[i] /= j * j;
		}
		++mm[a[i]];
	}
	for (auto it: mm)
		vv.push_back(it.second);
	sort(vv.begin(), vv.end());
	reverse(vv.begin(), vv.end());
	int cc = vv[0];
	dp[cc - 1] = 1;
	for (int it = 1; it < vv.size(); ++it) {
		int c = vv[it];
		fill(dp2, dp2 + cc + c, 0);
		for (int i = 0; i < cc; ++i) {
			if (dp[i] == 0)
				continue;
			for (int j = 1; j <= c; ++j) {
				for (int k = 0; k <= i && k <= j; ++k) {
					if (cc + 1 - i >= j - k)
						add(dp2[i - k + (c - j)], dp[i] * cnk[i][k] % MOD * cnk[cc + 1 - i][j - k] % MOD * cnk[c - 1][j - 1]);
				}
			}
		}
		cc += c;
		for (int i = 0; i < cc; ++i)
			dp[i] = dp2[i];
	}
	ll ans = dp[0];
	for (int i = 0; i < vv.size(); ++i) {
		for (int j = 1; j <= vv[i]; ++j)
			ans = (ans * j) % MOD;
	}
	cout << ans << "\n";
    return 0;
}