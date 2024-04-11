#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, m, a[MX], cn[MX];

void solve () {
	cin >> n >> m;
	
	forn (i, m) cn[i] = 0;
	forn (i, n) {
		cin >> a[i];
		a[i] %= m;
		cn[a[i]]++;
	}
	
	int res = 0;
	forn (i, m) {
		if (cn[i] && cn[(m - i) % m]) {
			if (i == (m - i) % m) {
				res++;
			} else {
				int a = cn[i];
				int b = cn[(m - i) % m];
				res++;
				res += max(0, max(a, b) - min(a, b) - 1);
			}
		} else {
			res += cn[i];
			res += cn[(m - i) % m];
		}
		
		cn[i] = cn[(m - i) % m] = 0;
	}
	
	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}