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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int a, b, k;
string x, y;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> a >> b >> k;
	
	forn (i, a) x.pb('0'), y.pb('0');
	forn (i, b) x.pb('1'), y.pb('1');
	
	/* do {
		do {
			if (x[0] != '1' || y[0] != '1') continue;
			
			int xn = stoi(x, 0, 2);
			int yn = stoi(y, 0, 2);
			
			if (xn < yn) continue;
			
			int z = xn - yn;
			
			if (__builtin_popcount(z) == k)
			cout << x << " " << y << " " << __builtin_popcount(z) << endl;
			
		} while (next_permutation(all(y)));
	} while (next_permutation(all(x))); */
	
	if (!a || b == 1) {
		if (k == 0) {
			cout << "Yes" << endl;
			forn (kk, 2) {
				forn (i, b) cout << 1;
				forn (i, a) cout << 0;
				cout << endl;
			}
		} else {
			cout << "No" << endl;
		}
		return 0;
	}
	
	if (a + b - 2 < k) {
		cout << "No" << endl;
		return 0;
	}
	
	cout << "Yes" << endl;
	
	if (!k) {
		forn (kk, 2) {
			forn (i, b) cout << 1;
			forn (i, a) cout << 0;
			cout << endl;
		}
		return 0;
	}
	
	x.clear(), y.clear();
	x.pb('1'), y.pb('1');
	b--;
	
	while (1) {
		if (b <= k && k <= a + b - 1) {
			forn (i, b) x.pb('1');
			forn (i, a) x.pb('0');
			
			y.pb('0');
			forn (i, b - 1) y.pb('1');
			forn (i, a - 1) y.pb('0');
			y.pb('1');
			
			int t = a + b - 1, ind = (int)y.size() - 1;
			while (t != k) {
				swap(y[ind], y[ind - 1]);
				ind--;
				t--;
			}
			
			break;
		}
		x.pb('1');
		y.pb('1');
		b--;
	}
	
	cout << x << endl << y << endl;
	
	return 0;
}