#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

ll n, q, x, y, f, d;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> q;

	f = (n * n + 1) / 2;

	while (q--) {
		cin >> x >> y;
		if (x % 2) {
			d = (y-1) / 2;
			if (y % 2 == 0) d += f;
			d++;
		} else {
			d = (y-1) / 2;
			if (n % 2 == 0) d += n / 2;
			else {
				if (y % 2) d += n / 2;
				else d += (n + 1) / 2;
			}
			if (y % 2) d += f;
			d++;
		}
		cout << d + n * ((x - 1) / 2) << endl;
	}

	return 0;
}