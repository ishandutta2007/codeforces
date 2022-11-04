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

const int MX = 205;
int n, f[MX], a[MX], in[MX], vis[MX];
ll res = 1, mx;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	forn (i, n) {
		cin >> f[i];
		f[i]--;
		a[i] = i;
	}

	forn (k, n) {
		forn (i, n)
			a[i] = f[a[i]];

		forn (i, n) {
			if (a[i] == i && !in[i]) {
				in[i] = 1;
				res = res / __gcd(res, k + 1ll) * (k + 1);
			}
		}
	}

	iota(a, a + n, 0);

	forn (k, n) {
		forn (i, n)
			a[i] = f[a[i]];

		forn (i, n) {
			if (!in[i] && !vis[i] && in[a[i]]) {
				vis[i] = 1;
				mx = max(mx, k + 1ll);
			}
		}
	}

	if (res < mx) {
		if (mx % res) cout << mx - mx % res + res << endl;
		else cout << mx << endl;
	} else {
		cout << res << endl;
	}

	return 0;
}