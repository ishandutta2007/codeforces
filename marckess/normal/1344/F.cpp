#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 2005;
int n, q, sz, f[256];
char rev[4];
bitset<MX> x[MX], m[MX], res;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	rev[0] = '.';
	f['R'] = 1; rev[1] = 'R';
	f['Y'] = 2; rev[2] = 'Y';
	f['B'] = 3; rev[3] = 'B';

	cin >> n >> q;

	for (int i = 0; i < n; i++) {
		x[2 * i][2 * i] = 1;
		x[2 * i + 1][2 * i + 1] = 1;
	}

	while (q--) {
		string s;
		int k;

		cin >> s >> k;
		if (s == "mix") {
			while (k--) {
				int i;
				cin >> i;
				i--;

				m[sz] ^= x[2 * i];
				m[sz + 1] ^= x[2 * i + 1];
			}

			char r;
			cin >> r;
			m[sz][2 * n] = f[r] & 1;
			m[sz + 1][2 * n] = f[r] & 2; 

			sz += 2;
		} else if (s == "RY") {
			while (k--) {
				int i;
				cin >> i;
				i--;

				swap(x[2 * i], x[2 * i + 1]);
			}
		} else if (s == "RB") {
			while (k--) {
				int i;
				cin >> i;
				i--;

				x[2 * i + 1] ^= x[2 * i];
			}
		} else {
			while (k--) {
				int i;
				cin >> i;
				i--;

				x[2 * i] ^= x[2 * i + 1];
			}
		}
	}

	for (int i = 0, j = 0; i < sz && j < 2 * n; j++) {
		int ind = -1;

		for (int k = i; k < sz; k++)
			if (m[k][j])
				ind = k;

		if (ind == -1) continue;

		swap(m[i], m[ind]);

		for (int k = 0; k < sz; k++)
			if (k != i && m[k][j])
				m[k] ^= m[i];

		i++;
	}

	for (int i = 0; i < sz; i++) {
		int f = 0;

		for (int k = 0; k < 2 * n; k++)
			if (m[i][k]) {
				res[k] = m[i][2 * n];
				f = 1;
				break;
			}

		if (!f && m[i][2 * n]) {
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES" << endl;
	for (int i = 0; i < n; i++)
		cout << rev[int(res[2 * i]) + 2 * int(res[2 * i + 1])];
	cout << endl;

	return 0;
}