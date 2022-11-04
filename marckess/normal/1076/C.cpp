#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int t;
	cin >> t;

	while (t--) {
		ld d;
		cin >> d;

		if (d == 0) {
			cout << "Y " << 0.0 << " " << 0.0 << endl;
		} else if (d < 4) {
			cout << "N" << endl;
		} else {
			ld i = 0, j = d / 2.0, rep = 100;

			while (rep--) {
				ld m = (i+j)/2;
				ld k = d - m;
				if (k * m < d) i = m;
				else j = m;
			}

			cout << "Y " << j << " " << d - j << endl;
		}
	}

	return 0;
}