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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1000005;
ll n, a[MX], s;
__int128 _ = 1;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	
	forn (i, n) {
		cin >> a[i];
		s += a[i];
	}

	ll i = 0, j = 1e12, rep = 60;
	
	while (rep--) {
		ll m = (i + j + 1) / 2;

		if (_ * m * n + _ * n * (n - 1) / 2 <= s) i = m;
		else j = m;
	}

	ll x = i;
	ll imp = s - (i * n + n * (n - 1) / 2);


	forn (i, n) {
		if (i < imp) cout << x + i + 1 << " ";
		else cout << x + i << " ";
	}
	cout << endl;
	
	return 0;
}