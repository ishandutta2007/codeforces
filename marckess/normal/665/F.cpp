#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 50000005;
int bs[MX];
ll res;

ll pi (ll n) {
	ll m = sqrt(n);

	vi lo(m + 1), hi(m + 1), val;

	auto at = [&] (ll x) -> ll& {
		if (x <= m) return lo[x];
		return hi[n / x];
	};

	for (ll i = 1; i <= m; i++) {
		val.pb(i);
		val.pb(n / i);
	}

	sort(all(val));
	val.erase(unique(all(val)), val.end());
	reverse(all(val));

	for (ll n : val)
		at(n) = n - 1;

	for (ll p = 2; p <= m; p++) {
		if (bs[p] == bs[p - 1]) continue;

		for (ll n : val) {
			if (n < p * p) break;
			at(n) -= at(n / p) - at(p - 1);
		}
	}

	return at(n);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	forn (i, MX) bs[i] = 1;
	bs[0] = bs[1] = 0;

	for (int i = 4; i < MX; i += 2)
		bs[i] = 0;

	for (ll i = 3; i * i < MX; i += 2)
		if (bs[i])
			for (ll j = i * i; j < MX; j += i)
				bs[j] = 0;

	forn (i, MX) if (i) bs[i] += bs[i - 1];

	ll n;
	cin >> n;

	for (ll i = 2; i * i * i <= n; i++)
		if (bs[i] != bs[i - 1])
			res++;

	for (ll i = 2; i * i <= n; i++)
		if (bs[i] != bs[i - 1]) {
			ll x = n / i;
			if (x < MX) res += bs[x];
			else res += pi(x);
			res -= bs[i];
		}

	cout << res << endl;

	return 0;
}