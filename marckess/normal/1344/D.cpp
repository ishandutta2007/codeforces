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

const int MX = 100005;
int n;
ll k, a[MX], b[MX];
priority_queue<ii> pq;

#define dif(b) (3 * (b) * (b) - 3 * (b) + 1)

ll f2 (ll n) {
	ll i = 0, j = 1e9, rep = 32;
	while (rep--) {
		ll m = (i + j + 1) / 2;
		if (dif(m) <= n) i = m;
		else j = m;
	}
	return i;
}

ll f (ll m) {
	ll res = 0;
	forn (i, n) {
		if (a[i] <= m) continue;
		res += min(a[i], f2(a[i] - m));
	}
	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;
	forn (i, n)
		cin >> a[i];

	ll i = -4e18, j = 4e18, rep = 64;
	while (rep--) {
		ll m = (i + j) / 2;
		if (f(m) <= k) j = m;
		else i = m;
	}

	ll x = j;
	k -= f(x);

	forn (i, n) {
		if (a[i] > x)
			b[i] = min(a[i], f2(a[i] - x));
		pq.emplace(a[i] - dif(b[i] + 1), i);
	}

	while (k) {
		ll y = pq.top().fi;
		int i = pq.top().se;
		pq.pop();

		if (b[i] == a[i]) continue;
		b[i]++;
		k--;

		pq.emplace(a[i] - dif(b[i] + 1), i);
	} 

	/*ll s = 0;
	forn (i, n) s += b[i] * (a[i] - b[i] * b[i]);
	cout << s << endl;*/

	forn (i, n) cout << b[i] << " ";
	cout << endl;

	return 0;
}