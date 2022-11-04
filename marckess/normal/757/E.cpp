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

const int MX = 1e6+5, LMX = 20, mod = 1e9+7;
int q, r, n, f[MX], mx = 0, bs[MX];
ll dp[MX][LMX];

void pre () {
	memset(dp, -1, sizeof(dp));
	for (ll i = 2; i < MX; i++)
		if (!bs[i]) {
			bs[i] = i;
			for (ll j = i * i; j < MX; j += i)
				bs[j] = i;
		}
}

ll go (int r, int pw) {
	ll &res = dp[r][pw];
	if (res != -1) return res;
	res = 0;

	if (pw == 0) return res = 1;
	if (r == 0) return res = 2;
	if (pw == 1) return res = r + 2;

	for (int i = 0; i <= pw; i++)
		res += go(r-1, i);

	return res %= mod;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	pre();

	cin >> q;
	while (q--) {
		cin >> r >> n;
		
		ll res = 1;
		while (bs[n]) {
			int p = bs[n], pw = 0;
			while (n % p == 0) n /= p, pw++;
			res = res * go(r, pw) % mod;
		}

		cout << res << endl;
	}

	return 0;
}