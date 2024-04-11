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

ll u, v;

void solve () {
	cin >> u >> v;
	
	if (u > v) {
		cout << "NO" << endl;
		return;
	}
	
	int x = 0, y = 0;
	forn (i, 30) {
		if (u & (1 << i)) x++;
		if (v & (1 << i)) y++;
		
		if (x < y) {
			cout << "NO" << endl;
			return;
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