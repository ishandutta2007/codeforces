#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define find(v,x) (lower_bound(ALL(v), x) - v.begin())

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, m, w[MX], q, l, r;

bitset<MX> bs;
vector<ll> pr;

void criba () {
	for (ll i = 2; i < MX; i++) 
		if (!bs[i]) {
			pr.push_back(i);
			for (ll j = i * i; j < MX; j += i)
				bs[j] = 1;
		}
}

map<int, int> mp;
ll phi (ll n) {
	if (mp.count(n)) return mp[n];
	ll res = n, aux = n;

	int i = 0;
	while (pr[i] * pr[i] <= n) {
		if (n % pr[i] == 0) res -= res / pr[i];
		while (n % pr[i] == 0) n /= pr[i];
		i++;
	}

	if (n != 1) res -= res / n;
	return mp[aux] = res;
}

ll mod (ll x, ll y) {
	if (x < y) return x;
	return x % y + y;
}

ll pot (ll b, ll p, ll m) {
	ll res = 1;
	
	while (p) {
		if (p & 1) res = mod(res * b, m);
		b = mod(b * b, m);
		p /= 2;
	}

	return res;
}

ll obtRes (int l, int r, int m) {
	if (l == r || m == 1) return mod(w[l], m);
	return pot(w[l], obtRes(l+1, r, phi(m)), m);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	criba();

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> w[i];

	cin >> q;
	while (q--) {
		cin >> l >> r;
		cout << obtRes(l, r, m) % m << endl;
	}

	return 0;
}