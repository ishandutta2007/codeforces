#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int MX = 5005, mod = 1000000007;
int n, m, a[MX], f[MX], h[MX];
int mx;
ll cn = 1;
vi pos[MX], v[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);	
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		pos[a[i]].pb(i);
	}

	for (int i = 0; i < m; i++) {
		cin >> f[i] >> h[i];
		v[f[i]].pb(h[i]);
	}

	for (int i = 1; i <= n; i++) {
		int f = 0;

		for (int x : v[i])
			if (x <= pos[i].size())
				f++;

		if (f) {
			mx++;
			(cn *= f) %= mod;
		}
	}

	for (int i = 0; i < n; i++) {
		int can = 0, f = 0;
		ll acu = 1;

		for (int j = 1; j <= n; j++) {
			int a = 0, b = 0, ab = 0, g = 0;

			for (int x : v[j])
				if (x <= pos[j].size()) {
					int fa = 0, fb = 0;
					
					if (pos[j][x - 1] < i) fa = 1;
					if (*(pos[j].end() - x) > i) fb = 1;
					if (pos[j][x - 1] == i) {
						g = 1;
						fb = 0;
					}

					a += fa;
					b += fb;
					ab += fa & fb;
				}

			if (g) {
				a = 1, ab = 0, f = 1;
			}

			if (a * b - ab) {
				can += 2;
				(acu *= a * b - ab) %= mod;
			} else if (a + b) {
				can++;
				(acu *= a + b) %= mod;
			}
		}

		if (f) {
			if (can > mx) {
				mx = can;
				cn = acu;
			} else if (can == mx) {
				(cn += acu) %= mod;
			}
		}
	}

	cout << mx << " " << cn << endl;

	return 0;
}