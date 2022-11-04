#include <bits/stdc++.h>

// #define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
ll n, k, vis[MX];

ll query (int q) {
	cout << "? " << q << endl;
	ll r;
	cin >> r;
	return r;
}

void ans (ll p) {
	cout << "! " << p << endl;
	exit(0);
}

void up (ll i, int len) {
	int j = min(n, i + len), rep = 20;
	while (rep--) {
		int m = (i + j) / 2;
		if (query(m) >= k) j = m;
		else i = m;
	}
	ans(j);
}

void down (ll j, int len) {
	int i = max(1ll, j - len), rep = 20;
	while (rep--) {
		int m = (i + j + 1) / 2;
		if (query(m) <= m) i = m;
		else j = m;
	}
	ans(i);
}

int main () {
	// ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;
	
	query(1);
	
	for (int i = 2, j = 4; i <= n; i += j, j += 2) {
		ll t = query(i);
		if (t == k) {
			ll s = query(i % n + 1);
			if (s > k) ans(i);
			if (s < k) up(i, j + 1);
		} else if (t < k) up(i, j);
		else down(i, j);
	} 
	
	return 0;
}