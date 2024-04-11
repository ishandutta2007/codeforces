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

ll n, l, r;

ll cn (ll n) {
	if (n <= 1) return 1;
	return 2 * cn(n / 2) + 1; 
}

ll acu (ll n) {
	if (n <= 1) return n;
	return 2 * acu(n / 2) + n % 2;
}

ll res (ll n, ll k) {
	if (!k) return 0;
	if (n <= 1) return n;

	ll c = cn(n / 2);
	if (c >= k) return res(n / 2, k);

	return acu(n / 2) + n % 2 + res(n / 2, k - c - 1);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> l >> r;
	cout << res(n, r) - res(n, l-1) << endl;

	return 0;
}