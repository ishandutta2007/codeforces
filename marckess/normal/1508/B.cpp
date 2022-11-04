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

int n;
ll k, pot[66];

void solve () {
	cin >> n >> k;
	
	if (n <= 61 && k > pot[n - 1]) {
		cout << -1 << endl;
		return;
	}
	
	for (int i = 1; i <= n;) {
		for (int j = i; j <= n; j++) {
			ll x = 1;
			
			if (j < n) {
				if (n - j - 1 <= 60)
					x = pot[n - j - 1];
				else
					x = k;
			}
			
			if (x >= k) {
				for (int l = j; l >= i; l--)
					cout << l << " ";
				i = j + 1;
				break;
			}
			
			k -= x;
		}
	}
	
	cout << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	pot[0] = 1;
	for (int i = 1; i <= 60; i++)
		pot[i] = 2 * pot[i - 1];
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}