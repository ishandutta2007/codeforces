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
typedef vector<ll> vi;
typedef vector<ii> vii;

set<ll> st;
int n;
ll k, a[105];

void solve () {
	st.clear();
	
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int j = 0; j < n; j++) {
		for (ll i = 1; 1; i *= k) {
			if (i >= a[j]) {
				while (i) {
					if (i <= a[j]) {
						a[j] -= i;

						if (st.count(i)) {
							cout << "NO" << endl;
							return;
						}

						st.insert(i);
					}

					i /= k;
				}

				if (a[j]) {
					cout << "NO" << endl;
					return;
				}

				break;
			}
		}
	}

	cout << "YES" << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();	

	return 0;
}