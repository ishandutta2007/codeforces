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
typedef pair<ll, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const ll inf = 1'000'000'000'000'000'001ll;
const int MX = 100005, lim = 32000000;
ll n, k;
bitset<lim> bs;
vi prime;
map<ll, vi> mf, md;

void pre () {
	prime.pb(2);

	for (ll i = 3; i < lim; i += 2)
		if (!bs[i]) {
			prime.pb(i);
			for (ll j = i * i; j < lim; j += 2 * i)
				bs[j] = 1;
		}
}

vi fac (ll n) {
	ll _ = n;

	if (!mf.count(_)) {
		for (ll &p : prime)
			if (n % p == 0) {
				mf[_].pb(p);
				while (n % p == 0)
					n /= p;
			}

		if (n > 1) mf[_].pb(n);
	}

	return mf[_];
}

void euc (ll a, ll b, ll &x, ll &y) {
	if (!b) {
		x = 1, y = 0;
		return;
	}

	euc(b, a % b, x, y);

	ll x1 = y, y1 = x - (a / b) * y;
	x = x1, y = y1;
}

__int128 floor (__int128 a, __int128 b) {
	__int128 res = a / b;
	if (a < 0 && a % b) res--;
	return res;
} 

__int128 ceil (__int128 a, __int128 b) {
	if (a < 0) return a / b;
	return (a + b - 1) / b;
}

bool dio (ll a, ll b, ll n) {
	ll x, y;
	euc(a, b, x, y);
	return ceil(__int128(-x) * n, b) <= floor(__int128(y) * n, a);
}

vi dij (vi &f, ll k) {
	if (!md.count(k)) {
		vi dis(f[0], -1);
		priority_queue<ii, vii, greater<ii>> pq;

		dis[0] = 0;
		pq.emplace(0, 0);

		while (pq.size()) {
			int u = pq.top().se;
			ll d = pq.top().fi;
			pq.pop();

			if (d > dis[u]) continue;

			for (ll &p : f) {
				int v = (u + p) % f[0];
				ll w = min(dis[u] + p, inf);

				if (dis[v] == -1 || dis[v] > w) {
					dis[v] = w;
					pq.emplace(w, v);
				}
			}
		}

		md[k] = dis;
	}

	return md[k];
}

void solve () {
	cin >> n >> k;

	vi f = fac(k);

	#define imp(x) cout << ((x) ? "YES" : "NO") << endl
	
	if (!f.size()) imp(0);
	else if (f.size() == 1) imp(n % f[0] == 0);
	else if (f.size() == 2) imp(dio(f[0], f[1], n));
	else {
		vi dis = dij(f, k);
		imp(dis[n % f[0]] != -1 && dis[n % f[0]] <= n);
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	pre();

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}