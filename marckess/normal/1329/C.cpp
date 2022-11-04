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

const int MX = (1 << 20) + 5;
int h, g, a[2 * MX];
vi res;

void solve (int u, int i) {
	if (!a[u]) return;

	while (1) {
		int pos = u, l = i;

		while (1) {
			if (!a[(pos << 1)] && !a[(pos << 1) + 1]) break;
			
			if (a[(pos << 1)] > a[(pos << 1) + 1]) {
				pos = (pos << 1);
			} else {
				pos = (pos << 1) + 1;
			}

			l++;
		}


		if (l == g) break;

		int aux = 0;
		while (pos >= u) {
			swap(aux, a[pos]);
			pos >>= 1;
		}

		res.pb(u);
	}

	solve(u * 2, i + 1);
	solve(u * 2 + 1, i + 1);
}

void solve () {
	cin >> h >> g;
	for (int i = 1; i < (1 << h); i++) {
		cin >> a[i];
		a[2 * i] = 0;
		a[2 * i + 1] = 0;
	}

	res.clear();
	solve(1, 1);

	ll s = 0;
	for (int i = 1; i < (1 << g); i++)
		s += a[i];

	cout << s << endl;
	for (int x : res)
		cout << x << " ";
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