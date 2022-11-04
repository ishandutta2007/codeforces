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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int n, k, a[11111];

bool query (int a, int b, int c) {
	cout << "? " << a << " " << b << " " << c << endl;
	fflush(stdout);
	string r;
	cin >> r;
	return r == "Yes";
}

void ans (int a) {
	cout << "! " << a << endl;
	exit(0);
}

int sz () {
	int ln = 0, x = n, y = 1;
	while (x) {
		x -= y;
		ln++;
		y *= k;
	}
	return ln;
}

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	srand(time(0));

	cin >> n >> k;

	iota(a, a+n, 1);

	int h = sz();

	int rep = 60;
	while (rep--) {
		random_shuffle(a, a+n);
		stack<int> st;

		int x = a[0], y = a[1], cn = 0;

		for (int i = 1; i <= n; i++)
			if (query(x, i, y)) {
				cn++;
				st.push(i);
			}

		if (cn == 2 * h - 1) {
			while (st.size()) {
				cn = 0;
				int z = st.top();
				st.pop();

				for (int i = 1; i <= n; i++)
					cn += query(x, i, z);

				if (cn == h) {
					ans(z);
					return 0;
				}
			}
		}
	}

	return 0;
}