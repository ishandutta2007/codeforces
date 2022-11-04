#include <bits/stdc++.h>

//#define endl '\n'
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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int n, r1 = -1, r2 = -1, c1 = -1, c2 = -1;

int query (int x1, int y1, int x2, int y2) {
	cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
	int r;
	cin >> r;
	if (r == -1) exit(0);
	return r;
}

void ans (int x1, int y1, int x2, int y2) {
	cout << "! " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;	
	exit(0);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		if (query(i, 1, i, n) & 1) {
			if (c1 == -1) c1 = i;
			else c2 = i;
		}
		if (query(1, i, n, i) & 1) {
			if (r1 == -1) r1 = i;
			else r2 = i;
		}
	}

	if (r1 != -1) {
		int i = 1, j = n, rep = 11;

		while (rep--) {
			int m = (i + j) / 2;
			if (query(1, r1, m, r1) & 1) j = m;
			else i = m;
		}

		if (c1 == -1) {
			ans(j, r1, j, r2);
		} else if (c1 == j) {
			ans(c1, r1, c2, r2);
		} else {
			ans(c2, r1, c1, r2);
		}

	} else {
		int i = 1, j = n, rep = 11;

		while (rep--) {
			int m = (i+j)/2;
			if (query(c1, 1, c1, m) & 1) j = m;
			else i = m;
		}

		ans(c1, j, c2, j);
	}

	return 0;
}