#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 3005, mod = 998244353;
string s, t;
int n, m;
ll res, mem[MX][MX];

ll dp (int i, int j) {
	if (i + j == 0) return 1;

	ll &res = mem[i][j];
	if (res != -1) return res;
	res = 0;

	int k;
	if (i) {
		k = i - 1;
		if (k >= m || t[k] == s[n - i - j])
			res += dp(i - 1, j);
	}

	if (j) {
		k = n - j;
		if (k >= m || t[k] == s[n - i - j])
			res += dp(i, j - 1);
	}

	if (!i && n - i - j >= m) res++;

	res %= mod;
	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(mem, -1, sizeof(mem));

	cin >> s >> t;
	n = s.size(), m = t.size();

	for (int i = 0; i <= n; i++)
		(res += dp(i, n - i)) %= mod;
	cout << res << endl;

	return 0;
}