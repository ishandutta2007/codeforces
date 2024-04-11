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

int w, h, n;

void solve () {
	cin >> w >> h >> n;
	int x = 1, y = 1;
	while (w % 2 == 0) {
		w /= 2;
		x *= 2;
	}
	while (h % 2 == 0) {
		h /= 2;
		y *= 2;
	}
	if (x * y >= n) cout << "yes" << endl;
	else cout << "no" << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}