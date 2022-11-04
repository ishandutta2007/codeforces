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

#define is(k,x) bool(k&(1<<x))

const int mod = 998244353;
int n, k;
ll pw[20], sum[1<<10][18][2][2], dp[1<<10][18][2][2];
string l, r, s;

ii obtRes (int i, int j, int f, int g) {
	if (!g && (i & 1)) i ^= 1;
	if (__builtin_popcount(i) > k) return {0,0};
	if (j == n) return {1,0};

	ll &ans = dp[i][j][f][g];
	ll &res = sum[i][j][f][g];
	if (ans != -1) return {ans, res};
	ans = 0;

	for (int l = 0; l < 10; l++)
		if (!f || l < s[j]) {
			ii d = obtRes(i|(1<<l), j+1, 0, g || l);

			res += (d.fi * l * pw[n-j-1] % mod + d.se) % mod;
			if (res >= mod) res -= mod;
			
			ans += d.fi;
			if (ans >= mod) ans -= mod;
		}

	if (f) {
		ii d = obtRes(i|(1<<s[j]), j+1, 1, g || s[j]);

		res += (d.fi * (ll)s[j] * pw[n-j-1] % mod + d.se) % mod;
		if (res >= mod) res -= mod;

		ans += d.fi;
		if (ans >= mod) ans -= mod;
	}

	return {ans, res};
}

ll solve (string _s) {
	s = _s;
	n = s.size();
	for (char &c : s) c -= '0';

	memset(dp, -1, sizeof(dp));
	memset(sum, 0, sizeof(sum));
	ii d = obtRes(0, 0, 1, 0);

	return d.se;
}

bool esPos (string s) {
	int mk = 0;
	for (char c : s) mk |= 1 << (c - '0');
	return __builtin_popcount(mk) <= k;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	pw[0] = 1;
	for (int i = 1; i < 20; i++) {
		pw[i] = 10 * pw[i-1];
		pw[i] %= mod;
	}

	cin >> l >> r >> k;

	ll res = solve(r);
	res -= solve(l);

	if (esPos(l)) res += stoll(l);

	cout << MOD(res, mod) << endl;

	return 0;
}