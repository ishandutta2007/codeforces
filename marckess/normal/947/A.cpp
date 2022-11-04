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

const int MX = 1'000'005;
bitset<MX> bs;
vi pr;

void criba () {
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i < MX; i++) {
		if (bs[i]) {
			pr.push_back(i);
			for (ll j = i * i; j < MX; j += i)
				bs[j] = 0;
		}
	}
}

vi fac (int n) {
	vi f;
	for (int i = 0; i < pr.size() && (ll)pr[i] * pr[i] <= n; i++) {
		if (n % pr[i] == 0) {
			f.push_back(pr[i]);
			while (n % pr[i] == 0)
				n /= pr[i];
		}
	}

	if (n > 1)
		f.push_back(n);

	return f;
}

int res = 1e9;
int n;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	criba();

	cin >> n;

	vi f = fac(n);

	for (int i = 4; i <= n; i++) {
		if (!bs[i]) {
			bool pos = 0;

			for (int x : f) {
				if (x < i) {
					int d = (i / x) * x;
					if (d < i)
						d += x;
					if (d == n)
						pos = 1;
				}
			}

			if (pos) {
				vi g = fac(i);
				for (int x : g) {
					int d = i - x + 1;
					if (x < d)
						res = min(res, d);
				}
			}
		}
	}

	cout << res << endl;

	return 0;
}