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

const int MX = 200005;
int n, a[MX], cn, ini, fin;

void solve () {
	cin >> n;

	cn = 0, ini = 1e9, fin = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != i) {
			cn++;
			ini = min(ini, i);
			fin = max(fin, i);
		}
	}

	if (!cn) cout << 0 << endl;
	else {
		cn = 0;
		for (int j = ini; j <= fin; j++)
			if (a[j] == j)
				cn++;

		if (cn) cout << 2 << endl;
		else cout << 1 << endl;
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