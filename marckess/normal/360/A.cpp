#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 5005;
int n, m, a[MX], b[MX];
int t[MX], l[MX], r[MX], d[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < m; i++)
		cin >> t[i] >> l[i] >> r[i] >> d[i];

	for (int i = 1; i <= n; i++) {
		int off = 0, act = 0, f = 0;
		for (int j = 0; j < m; j++)
			if (l[j] <= i && i <= r[j]) {
				if (t[j] == 1) {
					off += d[j];
				} else {
					if (f) act = min(act, d[j]-off);
					else act = d[j]-off;
					f = 1;
				}
			}
		a[i] = act;
	}

	for (int i = 1; i <= n; i++) b[i] = a[i];

	for (int j = 0; j < m; j++)
		if (t[j] == 1) {
			for (int i = l[j]; i <= r[j]; i++)
				b[i] += d[j];
		} else {
			int mx = -2e9;
			for (int i = l[j]; i <= r[j]; i++)
				mx = max(mx, b[i]);
			if (mx != d[j]) {
				cout << "NO" << endl;
				return 0;
			}
		}

	cout << "YES" << endl;
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
	cout << endl;

	return 0;
}