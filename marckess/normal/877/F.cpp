#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define first fi
#define second se
#define SET(p,k) memset(p, k, sizeof(p));

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

int n, k, b, izq[100005], der[100005];
vector<ll> con(1);
ll a[100005];
int x[100005], y[100005], q[100005], _q, sq;
ll res[100005];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> b;
		a[i] = b == 1 ? 1 : -1;
	}
	for (int i = 1; i <= n; i++) {
		cin >> b;
		a[i] *= b;

		if (i)
			a[i] += a[i-1];
		con.insert(con.end(), {a[i], a[i]+k, a[i]-k});
	}
	a[0] = 0, izq[0] = k, der[0] = -k;
	con.insert(con.end(), {0, k, -k});

	//Mapeo
	sort(con.begin(), con.end());
	con.erase(unique(con.begin(), con.end()), con.end());

	for (int i = 0; i <= n; i++) {
		izq[i] = lower_bound(con.begin(), con.end(), a[i]+k) - con.begin();
		der[i] = lower_bound(con.begin(), con.end(), a[i]-k) - con.begin();
		a[i] = lower_bound(con.begin(), con.end(), a[i]) - con.begin();
	}

	cin >> _q;
	for (int i = 0; i < _q; i++) {
		cin >> x[i] >> y[i];
		q[i] = i;
	}

	sq = sqrt(_q);
	sort(q, q+_q, [](int a, int b) {
		int _a = x[a] / sq, _b = x[b] / sq;

		if (_a != _b)
			return _a < _b;
		return y[a] < y[b];
	});

	//Mo
	vector<ll> acu(con.size());

	int l = 1, r = 0;
	ll ns = 0;
	for (int i = 0; i < _q; i++) {
		int u = q[i];

		while (l < x[u]) {
			acu[a[l]]--;
			ns -= acu[izq[l]];
			l++;
		}
		while (l > x[u]) {
			l--;
			ns += acu[izq[l]];
			acu[a[l]]++;
		}
		while (r < y[u]) {
			r++;
			ns += acu[der[r]];
			acu[a[r]]++;
		}
		while (r > y[u]) {
			acu[a[r]]--;
			ns -= acu[der[r]];
			r--;
		}

		res[u] = ns + acu[izq[l-1]];
	}

	for (int i = 0; i < _q; i++)
		cout << res[i] << endl;

	return 0;
}