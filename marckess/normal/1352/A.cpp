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

string s;

void solve () {
	cin >> s;

	int res = 0;
	forn (i, s.size())
		if (s[i] != '0')
			res++;

	cout << res << endl;
	forn (i, s.size()) {
		if (s[i] != '0') {
			cout << s[i];
			forn (j, int(s.size()) - i - 1)
				cout << '0';
			cout << " ";
		}
	}
	cout << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}