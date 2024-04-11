#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define SET(p,k) memset(p, k, sizeof(p));

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;

struct DS {
	vi ds;

	DS (int n) : ds(n+1) {
		for (int i = 1; i <= n; i++)
			ds[i] = i;
	}

	int padre (int a) {
		return a == ds[a] ? a : ds[a] = padre(ds[a]);
	}

	bool joint (int a, int b) {
		a = padre(a), b = padre(b);
		if (a == b)
			return false;
		return ds[a] = b;
	}
};

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n, m, c = 0, a, b, comp = 0;
	set<int> ex;
	ll res = 0;
	cin >> n >> m;

	DS ds(n);
	vi tam(n+1);

	for (int i = 0; i < m; i++) {
		cin >> a >> b;

		ex.insert(a), ex.insert(b); 

		if (a == b)
			c++;
		else
			res += tam[a]++, res += tam[b]++;

		if (ds.joint(a, b))
			comp--;
	}

	res += c * ll(c-1) / 2;
	res += c * ll(m-c);

	cout << (ex.size() + comp == 1 ? res : 0) << endl;

	return 0;
}