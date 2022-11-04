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

const int MX = 1000000;
int n, cn = 0, f = 1;
ll a[MX], b[MX];

void obtRes (int ini) {
	a[ini] = b[ini];
	for (int i = 0, j = (ini+n-1)%n; i < n-1; i++, j = (j+n-1)%n)
		a[j] = a[(j+1)%n] * (b[(j+n-1)%n] / a[(j+1)%n] + 1) + b[j];
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		cn += bool(b[i]);
		if (i) f &= b[i] == b[i-1];
	}

	if (!cn) {
		cout << "YES" << endl;
		while (n--) cout << 1 << " ";
		cout << endl;

		return 0;
	}

	if (f) {
		cout << "NO" << endl;
		return 0;
	}

	for (int i = 0; i < n; i++)
		if (b[i] < b[(i+1)%n]) {
			obtRes((i+1)%n);

			cout << "YES" << endl;
			for (int i = 0; i < n; i++)
				cout << a[i] << " ";
			cout << endl;

			return 0;
		}

	return -1;
}