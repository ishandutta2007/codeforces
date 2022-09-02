#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

const int N = 1e5;
int cou[N+1][3];
ll pref[N+1];
ll suff[N+1]; 

// Min cost if we fill some prefix of '?'s with 0s, the rest with 1s
ll solve(const string& str, ll x, ll y) {
	int n = str.size();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 3; ++j) cou[i+1][j] = cou[i][j];
		int r = (str[i] == '0' ? 0 : (str[i] == '1' ? 1 : 2));
		++cou[i+1][r];
	}

	// Cost in prefix of filling all '?'s with 0s
	for (int i = 1; i <= n; ++i) {
		pref[i] = pref[i-1];
		if (str[i-1] == '0' || str[i-1] == '?') {
			pref[i] += y * cou[i-1][1];
		} else {
			pref[i] += x * (cou[i-1][0] + cou[i-1][2]);
		}
	}
	
	// Cost in suffix of filling all '='s with 1s
	for (int i = n-1; i >= 0; --i) {
		suff[i] = suff[i+1];
		if (str[i] == '1' || str[i] == '?') {
			suff[i] += y * (cou[n][0] - cou[i][0]);
		} else {
			suff[i] += x * (cou[n][1] - cou[i][1] + cou[n][2] - cou[i][2]);
		}
	}

	/*
	cerr << str << ' ' << x << ' ' << y << ' ' << n << ": " << endl;
	for (int i = 0; i <= n; ++i) cerr << pref[i] << ' '; cerr << endl;
	for (int i = 0; i <= n; ++i) cerr << suff[i] << ' '; cerr << endl;
	*/

	// Find best prefix
	ll res = INF;
	for (int i = 0; i <= n; ++i) {
		ll off = pref[i] + suff[i];
		off += (ll)cou[i][1] * (cou[n][0] - cou[i][0]) * y;
		off += (ll)(cou[i][0] + cou[i][2]) * (cou[n][1] - cou[i][1] + cou[n][2] - cou[i][2]) * x;
		res = min(res, off);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str;
	cin >> str;
	ll x, y;
	cin >> x >> y;

	ll res = solve(str, x, y);
	reverse(str.begin(), str.end());
	res = min(res, solve(str, y, x));
	cout << res << '\n';

}