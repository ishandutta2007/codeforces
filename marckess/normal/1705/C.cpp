#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int n, c, q;
string s;
vii a, b;

void main_() {
	cin >> n >> c >> q >> s;
	a = {{0, int(s.size()) - 1}};
	b = a;
	
	ll sz = n;
	forn (kk, c) {
		ll l, r;
		cin >> l >> r;
		l--, r--;
		a.pb({l, r});
		b.pb({sz, sz + r - l});
		sz += r - l + 1;
	}
	
	forn (kk, q) {
		ll k;
		cin >> k;
		k--;
		
		for (int i = (int)a.size() - 1; i > 0; i--)
			if (b[i].fi <= k && k <= b[i].se) {
				k = a[i].fi + (k - b[i].fi);
			}
		
		cout << s[k] << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}