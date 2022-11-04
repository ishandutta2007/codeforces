#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1 << 19, mod = 1e9+7;
int n, num[80][80], sig[80];
int dp[76][MX];
string s;

int obtNum (int i, int j) {
	if (num[i][j] != -1) return num[i][j];
	return num[i][j] = stoi(s.substr(i, j - i + 1), nullptr, 2);
}

int obtRes (int i, int mk, int mx) {
	if (i == n)
		return mk && mk == (1 << mx) - 1;

	int &res = dp[i][mk];
	if (res != -1) return res;
	res = 0;

	if (mk && mk == (1 << mx) - 1)
		res++;

	for (int j = i; j < min(n, i + 5); j++) {
		int a = obtNum(i, j);
		if (a > 19) continue;

		res += obtRes(sig[j+1], mk | (1 << (a - 1)), max(mx, a));
		if (res >= mod) res -= mod;
	}

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(dp, -1, sizeof(dp));
	memset(num, -1, sizeof(num));

	cin >> n >> s;

	sig[n] = n;
	for (int i = n - 1; i >= 0; i--)
		if (s[i] == '1') sig[i] = i;
		else sig[i] = sig[i+1];

	ll res = 0;
	for (int i = 0; i < n; i++)
		res += obtRes(sig[i], 0, 0);

	cout << res % mod << endl;

	return 0;
}