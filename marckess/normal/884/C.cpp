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
typedef vector<vvi> vvvi;

struct DS {
	vi ds, rk, tam;
	ll res;

	DS (int n) : ds(n+1), rk(n+1), tam(n+1, 1) {
		for (int i = 1; i <= n; i++)
			ds[i] = i;
		res = n;
	}

	int parent (int a) {
		return ds[a] == a ? a : ds[a] = parent(ds[a]);
	}

	void joint (int a, int b) {
		a = parent(a), b = parent(b);
		if (a == b)
			return;
		if (rk[a] > rk[b]) {
			ds[b] = a;
			tam[a] += tam[b];
		} else {
			ds[a] = b;
			tam[b] += tam[a];
			if (rk[a] == rk[b])
				rk[b]++;
		}
	}
};

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n, a;

	cin >> n;
	DS ds(n);

	for (int i = 1; i <= n; i++) {
		cin >> a;
		ds.joint(a, i);
	}

	bitset<100005> bs;
	vector<ll> gr;

	for (int i = 1; i <= n; i++) {
		a = ds.parent(i);

		if (!bs[a]) {
			bs[a] = 1;
			gr.push_back(ds.tam[a]);
		}
	}

	sort (gr.begin(), gr.end(), greater<ll>());

	if (gr.size() == 1) {
		cout << gr[0] * gr[0] << endl;
		return 0;
	}

	ll res = (gr[0] + gr[1]) * (gr[0] + gr[1]);
	for (int i = 2; i < gr.size(); i++) {
		res += gr[i] * gr[i];
	}
	cout << res << endl;

	return 0;
}