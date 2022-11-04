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

int n, k1, k2, w, b;

void solve () {
	cin >> n >> k1 >> k2;
	cin >> w >> b;
	
	if (k1 + k2 - abs(k1 - k2) % 2 < 2 * w) {
		cout << "NO" << endl;
		return;
	}
	
	if (2 * n - k1 - k2 - abs((n - k1) - (n - k2)) % 2 < 2 * b) {
		cout << "NO" << endl;
		return;
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