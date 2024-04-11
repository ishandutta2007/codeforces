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

const int MX = 1000005, lim = 2500;
int bs[MX], dp_lo[MX], dp_hi[MX], m;
vi p;
vector<ll> d;
ll a;
map<ll, vector<ll>> mp;

void pre () {
	forn (i, MX) bs[i] = 1;
	bs[0] = bs[1] = 0;

	for (ll i = 2; i < MX; i++)
		if (bs[i]) {
			p.pb(i);
			for (ll j = i * i; j < MX; j += i)
				bs[j] = 0;
		}
}

void go (ll d) {
	if (d <= 2) return;

	ll aux = d - 1;

	for (ll k : p) {
		if (k * k > aux) break;

		if (aux % k == 0) {
			while (aux % k == 0)
				aux /= k;
			
			if (aux > 1) return;

			mp[k].pb(d);
			return;
		}
	}

	mp[aux].pb(d);
}

int& get (ll x) {
	if (x <= m) return dp_lo[x];
	return dp_hi[a / x];
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	pre();

	cin >> a;
	m = sqrt(a);

	for (ll i = 1; i * i <= a; i++)
		if (a % i == 0) {
			go(i);
			d.pb(i);

			if (i * i < a) {
				go(a / i);
				d.pb(a / i);
			}
		}

	sort(all(d), greater<ll>());

	get(1) = 1;

	for (auto it : mp) {
		auto &v = it.se;

		for (ll x : d)
			for (ll y : v)
				if (x % y == 0)
					get(x) += get(x / y);
	}

	cout << get(a) << endl;
	
	return 0;
}