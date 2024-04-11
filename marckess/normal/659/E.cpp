#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define SET(p,k) memset(p, k, sizeof(p));
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

struct DS {
	vi p, rk;

	DS (int n) : p(n+1), rk(n+1) {
		for (int i = 1; i <= n; i++)
			p[i] = i;
	}

	int parent (int a) {
		return a == p[a] ? a : p[a] = parent(p[a]);
	}

	void joint (int a, int b) {
		a = parent(a), b = parent(b);

		if (rk[a] > rk[b]) {
			p[b] = a;
		} else {
			p[a] = b;
			if (rk[a] == rk[b])
				rk[b]++;
		}
	}
};

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	vi gra;
	vvi comp;
	int n, m, a, b;

	cin >> n >> m;
	gra = vi(n+1);
	comp = vvi(n+1);
	DS ds(n+1);

	while (m--) {
		cin >> a >> b;
		gra[a]++;
		gra[b]++;
		ds.joint(a, b);
	} 

	for (int i = 1; i <= n; i++)
		comp[ds.parent(i)].push_back(i);

	int res = 0;
	for (int i = 1; i <= n; i++) {
		if (comp[i].size()) {
			int sg = 0;

			for (int x : comp[i])
				sg += gra[x];

			if (sg / 2 == comp[i].size() - 1)
				res++;
		}
	}

	cout << res << endl;

	return 0;
}