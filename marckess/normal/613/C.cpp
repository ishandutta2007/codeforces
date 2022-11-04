#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int n, a[30], f = 0, g = 0;
string s, t;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		f += a[i] % 2;
		g = __gcd(g, a[i]);
	}

	
	string s, t;

	if (f >= 2) {
		cout << 0 << endl;
		for (int i = 0; i < n; i++)
			while (a[i]--)
				cout << char(i+'a');
		cout << endl;
		return 0;
	}

	cout << g << endl;

	if (f) {
		for (int i = 0; i < n; i++) {
			a[i] /= g;
			if (a[i] % 2 == 0)
				for (int j = 0; j < a[i] / 2; j++)
					t.pb(i+'a');
		}

		for (int i = 0; i < n; i++)
			if (a[i] % 2 == 1)
				for (int j = 0; j < a[i]; j++)
					s.pb(i+'a');

		s = t + s;
		reverse(all(t));
		s += t;

		while (g--) cout << s;
		cout << endl;
		return 0;
	}

	for (int i = 0; i < n; i++) {
		a[i] /= g;
		while (a[i]--)
			s.pb(i+'a');
	}

	while (g--) {
		cout << s;
		reverse(all(s));
	}
	cout << endl;

	return 0;
}