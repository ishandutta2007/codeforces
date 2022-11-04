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
typedef double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1000005;
int n;
ll a[MX], b[MX], res;
map<ll, int> mp;
set<ll> vis;

int f (ll d) {
	if (d <= res) return 0;
	int cn = 0;

	for (const auto &it : mp)
		if (it.fi % d == 0)
			cn += it.se;

	return cn;
}

void solve (ll k) {
	mp.clear();

	forn (i, n) {
		b[i] = __gcd(a[i], k);
		mp[b[i]]++;
	}

	for (ll i = 1; i * i <= k; i++)
		if (k % i == 0) {
			if (2 * f(i) >= n) res = i;
			if (2 * f(k / i) >= n) res = k / i;
		}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	cin >> n;
	forn (i, n) cin >> a[i];

	shuffle(a, a + n, rng);

	forn (_, min(n, 10)) solve(a[_]);

	cout << res << endl;

	return 0;
}