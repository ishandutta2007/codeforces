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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int n;
string s, a = "abacaba";

void solve () {
	cin >> n >> s;

	for (int i = 0; i + 7 <= n; i++) {
		string t = s;

		for (int j = 0; j < 7; j++)
			if (t[i + j] == '?')
				t[i + j] = a[j];

		for (char &c : t)
			if (c == '?')
				c = 'z';

		int cn = 0;
		for (int k = 0; k + 7 <= n; k++)
			cn += t.substr(k, 7) == a;

		if (cn == 1) {
			cout << "Yes" << endl;
			cout << t << endl;
			return;
		}
	}

	cout << "No" << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}