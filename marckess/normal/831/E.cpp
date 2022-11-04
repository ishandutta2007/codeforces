#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define fi first
#define se second
#define endl '\n'
#define MOD(n,k) ( (n % k) + k ) % k
#define isOn(S, j) (S & (1 << j) )
#define setBit(S, j) (S | (1 << j ) )
#define LSB(S) (S & (-S))

struct fenwick_tree {
	vi ft;

	fenwick_tree (int n) : ft(n+1) {}

	void update (int k, int x) {
		while (k < ft.size()) {
			ft[k] += x;
			k += LSB(k);
		}
	}

	int query (int k) {
		int sum = 0;
		while (k) {
			sum += ft[k];
			k -= LSB(k);
		}
		return sum;
	}
};

ll n, res = 0, x;
map<int, vi> v;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		v[x].push_back(i+1);
	}

	fenwick_tree ft(n+2);
	for (int i = 1; i <= n; i++)
		ft.update(i, 1);

	int ind = 1;
	for (auto it = v.begin(); it != v.end(); it++) {
		vi w = it->se;
		int off = lower_bound(w.begin(), w.end(), ind) - w.begin();

		for (int i = 0; i < w.size(); i++) {
			int j = (i + off) % w.size(), val = ft.query(w[j]) - ft.query(ind);
			if ( val < 0 )
				val += n;

			res = res + val + 1;
			ft.update(w[j]+1, -1);
			n--;
			ind = w[j];
		}
	}

	cout << res << endl;

	return 0;
}