#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

struct FT {
	vi ft;

	FT () {}
	FT (int n) : ft(n+1) {}

	void update (int i, int k) {
		while (i < ft.size()) {
			ft[i] += k;
			i += i & -i;
		}
	}

	int sum (int i) {
		int res = 0;
		while (i) {
			res += ft[i];
			i -= i & -i;
		}
		return res;
	}
};

int n, q, p[200005];
int l[200005], r[200005], u[200005], d[200005], w[200005];
ll res[200005];
FT ft;

void obtID () {
	sort (w, w+q, [&] (int a, int b) {
		return l[a] < l[b];
	});
	ft = FT(n+3);

	for (int i = 1, j = 0; i <= n; i++) {
		while (j < q && l[w[j]] <= i) {
			int v = w[j];
			ll x;

			x = ft.sum(d[v]-1);
			res[v] += x * (x - 1) / 2;
			x = i - 1 - ft.sum(u[v]);
			res[v] += x * (x - 1) / 2;

			j++;
		}

		ft.update(p[i], 1);
	}
}

void obtDI () {
	sort (w, w+q, [&] (int a, int b) {
		return r[a] > r[b];
	});
	ft = FT (n+3);

	for (int i = n, j = 0; i; i--) {
		while (j < q && r[w[j]] >= i) {
			int v = w[j];
			ll x;

			x = ft.sum(d[v]-1);
			res[v] += x * (x - 1) / 2;
			x = n - i - ft.sum(u[v]);
			res[v] += x * (x - 1) / 2;

			j++;
		}

		ft.update(p[i], 1);
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> p[i];

	fill(res, res+q, (ll(n - 1) * n) / 2);
	for (int i = 0; i < q; i++) {
		cin >> l[i] >> d[i] >> r[i] >> u[i];

		res[i] -= ll(l[i]-1) * (l[i]-2) / 2
			   + ll(n-r[i]) * (n-r[i]-1) / 2
			   + ll(d[i]-1) * (d[i]-2) / 2
			   + ll(n-u[i]) * (n-u[i]-1) / 2;
	}
	iota(w, w+q, 0);

	obtID();
	obtDI();

	for (int i = 0; i < q; i++)
		cout << res[i] << endl;

	return 0;
}