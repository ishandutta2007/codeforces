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
int n, u, v, a[MX];

void solve () {
	cin >> n >> u >> v;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	int f = 1, g = 1;
	for (int i = 1; i < n; i++) {
		f &= abs(a[i] - a[i + 1]) <= 1;
		g &= a[i] == a[i + 1];
	}
	
	if (g) cout << v + min(u, v) << endl;
	else if (f) cout << min(u, v) << endl;
	else cout << 0 << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}