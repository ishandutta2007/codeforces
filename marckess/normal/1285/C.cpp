#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 1000005;
ll n, ps[MX], ra, rb;
ll x;
map<ll, int> mp;

ll pot (ll b, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) res *= b;
		b *= b;
		p /= 2;
	}
	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> x;

	ll n = x;
	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			int pw = 0;
			while (n % i == 0) {
				n /= i;
				pw++;
			}
			mp[i] = pw;
		}
	}

	if (n > 1)
		mp[n] = 1;

	ra = 1, rb = x;
	for (int mk = 0; mk < (1 << mp.size()); mk++) {
		ll a = 1, b = 1;
		int i = 0;
		for (auto it = mp.begin(); it != mp.end(); it++, i++)
			if (mk & (1 << i)) {
				a *= pot(it->fi, it->se);
			} else {
				b *= pot(it->fi, it->se);
			}
		if (a > b) swap(a, b);
		if (b < rb) {
			ra = a;
			rb = b;
		}
	}

	cout << ra << " " << rb << endl;

	return 0;
}