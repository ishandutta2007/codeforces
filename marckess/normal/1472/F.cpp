#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, m, x[MX], y[MX];
vi a, b;

void solve () {
	a.clear();
	b.clear();
	
	cin >> n >> m;
	forn (i, m) {
		cin >> x[i] >> y[i];
		y[i]--;
		if (x[i] == 1) a.pb(y[i]);
		else b.pb(y[i]);
	}
	
	if (m % 2) {
		cout << "NO" << endl;
		return;
	}
	
	sort(all(a));
	sort(all(b));
	
	int i = 0, j = 0, f = 0, g = 0, h = 0;
	
	while (i < a.size() || j < b.size()) {
		int op;
		
		if (i < a.size() && j < b.size()) {
			if (a[i] == b[j]) op = 2;
			else if (a[i] < b[j]) op = 0;
			else op = 1;
		} else if (i < a.size()) {
			op = 0;
		} else {
			op = 1;
		}
		
		if (op == 2) {
			if (f) {
				cout << "no" << endl;
				return;
			}
			i++, j++;
		} else if (op == 1) {
			if (f && b[j] % 2 != h) {
				cout << "no" << endl;
				return;
			}
			
			if (!f) {
				g = b[j] % 2;
				h = 1 - g;
				f = 1;
			} else {
				f = 0;
			}
			
			j++;
		} else {
			if (f && a[i] % 2 != g) {
				cout << "no" << endl;
				return;
			}
			
			if (!f) {
				h = a[i] % 2;
				g = 1 - h;
				f = 1;
			} else {
				f = 0;
			}
			
			i++;
		}
	}
	
	if (f) cout << "no" << endl;
	else cout << "yes" << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}