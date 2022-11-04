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

const int MX = 200005;
int n;
ll a[MX], k, g;

void solve () {
	cin >> n >> k;
	
	g = 0;
	forn (i, n) {
		cin >> a[i];
		if (i) g = __gcd(g, a[i] - a[i - 1]);
	}
	
	forn (i, n) {
		if ((k - a[i]) % 2 == 0) {
			if (((k - a[i]) / 2) % g == 0) {
				cout << "YES" << endl;
				return;
			}
		}
	}
	
	cout << "NO" << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
			
	return 0;
}