#include <bits/stdc++.h>

//#define endl '\n'
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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

void solve () {
	int n, a = 0, b = 0;
	cin >> n;
	
	forn (i, n) {
		int x;
		cin >> x;
		if (x) b++;
		else a++;
	}

	if (a >= n / 2) {
		cout << a << endl;
		forn (i, a) cout << 0 << " ";
		cout << endl;
	} else {
		b -= b & 1;
		cout << b << endl;
		forn (i, b) cout << 1 << " ";
		cout << endl;
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