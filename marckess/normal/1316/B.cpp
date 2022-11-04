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
typedef vector<ll> vi;
typedef vector<ii> vii;

int n, k;
string s, res;

void solve () {
	cin >> n >> s;

	res = s;
	reverse(all(res));
	k = n;

	for (int i = 1; i < n; i++) {
		string p;

		for (int j = n - i - 1; j < n; j++)
			p.pb(s[j]);

		if (i % 2) {
			for (int j = 0; j < n - i - 1; j++)
				p.pb(s[j]);
		} else {
			for (int j = n - i - 2; j >= 0; j--)
				p.pb(s[j]);
		}

		if (p <= res) {
			res = p;
			k = n - i;
		}
	}

	cout << res << endl << k << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();	

	return 0;
}