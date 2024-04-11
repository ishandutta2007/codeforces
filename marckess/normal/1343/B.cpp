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
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

ll n, s;

void solve () {
	cin >> n;
	
	if (n % 4 == 2) {
		cout << "NO" << endl;
		return;
	}

	cout << "YES" << endl;
	for (int i = 0; i < n / 2; i++) {
		cout << 2 * (i + 1) << " ";
		s += 2 * (i + 1);
	}

	for (int i = 0; i < n / 2 - 1; i++) {
		cout << 2 * i + 1 << " ";
		s -= 2 * i + 1;
	}

	cout << s << endl;
	s = 0;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}