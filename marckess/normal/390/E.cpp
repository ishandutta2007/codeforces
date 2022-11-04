#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 4000005;
struct BIT {
	ll b1[MX], b2[MX];

	BIT () {
		memset(b1, 0, sizeof(b1));
		memset(b2, 0, sizeof(b2));
	}

	void update (ll ft[], int i, ll k) {
		while (i < MX) {
			ft[i] += k;
			i += i & -i;
		}
	}

	void update (int a, int b, ll k) {
		update(b1, a, k);
		update(b1, b+1, -k);
		update(b2, a, k * (a - 1));
		update(b2, b+1, -k * b);
	}

	ll query (ll ft[], int i) {
		ll sum = 0;
		while (i) {
			sum += ft[i];
			i -= i & -i;
		}
		return sum;
	}

	ll query (int i) {
		return query(b1, i) * i - query(b2, i);
	}

	ll query (int a, int b) {
		return query(b) - query(a-1);
	}
};

int n, m, w, x, y, x2, y2, v, op;
ll tot = 0;
BIT hor, ver;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> w;

	while (w--) {
		cin >> op >> x >> y >> x2 >> y2;

		if (op) {
			cout << hor.query(x, x2) + ver.query(y, y2) - tot << endl;
		} else {
			cin >> v;
			hor.update(x, x2, v * ll(y2 - y + 1));
			ver.update(y, y2, v * ll(x2 - x + 1));
			tot += v * ll(x2 - x + 1) * (y2 - y + 1);
		}
	}

	return 0;
}