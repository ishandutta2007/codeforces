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

ll n, res = 0;
int acu[10] = {0};
ll fac[22];

void obtRes (vi v, int j) {
	bool f = 1;

	for (int i = 0; i < 10; i++)
		f &= v[i] || !acu[i];

	if (f) {
		int p = 0;

		for (int i = 0; i < 10; i++)
			p += v[i];

		for (int i = 1; i < 10; i++) {
			if (v[i]) {
				ll x = fac[p-1];
				for (int j = 0; j < 10; j++)
					x /= fac[v[j]-int(i == j)];
				res += x;
			}
		}
	}

	for (int i = j; i < 10; i++)
		if (v[i] < acu[i]) {
			vi w = v;
			w[i]++;
			obtRes(w, i);
		}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	fac[0] = 1;
	for (ll i = 1; i < 22; i++)
		fac[i] = i * fac[i-1];

	cin >> n;

	while (n) {
		acu[n%10]++;
		n /= 10;
	}

	vi v(10);
	obtRes(v, 0);

	cout << res << endl;

	return 0;
}