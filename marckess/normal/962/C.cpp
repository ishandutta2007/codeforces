#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int dp[(1<<10)][10];
ll n;
string s;

bool esc (ll n) {
	ll sq = sqrt(n);
	for (ll i = sq - 2; i <= sq + 2; i++)
		if (i * i == n)
			return 1;
	return 0;
}

int obtRes (int mk, int i) {
	if (i == s.size()) {
		ll acu = 0, res = 0;

		for (int i = 0, j = 1; i < s.size(); i++, j *= 2) {
			if (j & mk) {
				if (acu == 0 && s[i] == '0')
					return 0;
				acu++;
				res *= 10;
				res += s[i] - '0';
			}
		}

		if (esc(res))
			return acu;
		else
			return 0;
	}

	if (dp[mk][i] != -1)
		return dp[mk][i];
	return dp[mk][i] = max(obtRes(mk | (1 << i), i+1), obtRes(mk, i+1));
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 0, lim = (1 << 10); i < lim; i++)
		for (int j = 0; j < 10; j++)
			dp[i][j] = -1;

	cin >> n;
	s = to_string(n);
	int res = obtRes(0, 0);
	if (res <= 0)
		cout << -1 << endl;
	else 
		cout << s.size() - res << endl;

	return 0;
}