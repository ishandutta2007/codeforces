#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 300005;
int n, m;
vi c[MX];

ll f (vi a, vi b) {
	ll x = 0, y = 0;
	ll ca = 0, cb = 0;
	
	forn (i, m) {
		ca += a[i];
		cb += b[i];
		
		if (ca > cb) {
			x += ca - cb;
		} else {
			y += cb - ca;
		}
	}
	
	if (x < y)
		return -1;
	return x - y;
}

void main_() {
	cin >> n >> m;
	forn (i, n) {
		c[i] = vi(m);
		forn (j, m)
			cin >> c[i][j];
	}

	forn (i, n)
		if (f(c[i], c[(i + 1) % n]) == -1) {
			ll mx = 0;
			forn (j, n)
				if (i != j)
					mx = max(mx, f(c[j], c[i]));
			cout << i + 1 << " " << mx << endl;
			return;
		}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}