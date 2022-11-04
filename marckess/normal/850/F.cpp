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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005, mod = 1000000007;
int n, a[MX];
ll s, dp1[MX], dp2[MX], res;

ll pot (ll b, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;

	forn (i, n) {
		cin >> a[i];
		s += a[i];
	}

	dp2[0] = s - 1;
	for (int i = 1; i < min(1ll * MX, s); i++) {
		dp2[i] = (dp2[i - 1] - (s - 1) * pot(s - i + 1, mod - 2)) % mod;
		dp1[i] = (dp1[i - 1] + dp2[i]) % mod;
	}

	forn (i, n) res += dp1[a[i]];

	cout << MOD(res, mod) << endl;

	return 0;
}