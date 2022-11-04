#include <bits/stdc++.h>

#define endl '\n'
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
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int n, q;
string s;

void solve () {
	cin >> n >> q >> s;
	s = "x" + s;
	while (q--) {
		int l, r;
		cin >> l >> r;
		int res = 0;
		for (int i = 1; i < l; i++)
			res |= s[i] == s[l];
		for (int i = r + 1; i <= n; i++)
			res |= s[i] == s[r];
		if (res) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}