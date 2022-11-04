#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define fill_to_n(a,n,k) iota(a,a+n,k)
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

struct DS {
	vi p;

	DS (int n) : p(n) {
		iota(p.begin(), p.end(), 0);
	}

	int parent (int a) {
		return a == p[a] ? a : p[a] = parent(p[a]);
	}

	void joint (int a, int b) {
		a = parent(a), b = parent(b);

		if (a != b)
			p[a] = b;
	}
};

int n, m, w, b[1005], c[1005], u, v, gc[1005], bc[1005];
vvi dp;
DS ds(1);
vvi ing;

int obtRes (int i, int k) {
	if (i > n)
		if (k <= w)
			return 0;
		else
			return -2e9;

	if (k > w) 
		return -2e9;

	if (dp[i][k] != -1)
		return dp[i][k];

	int mx = obtRes(i+1, k);

	for (int x : ing[i])
		mx = max(mx, obtRes(i+1, k + c[x]) + b[x]);

	return dp[i][k] = max(mx, obtRes(i+1, k + gc[i]) + bc[i]);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> w;
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	for (int j = 1; j <= n; j++)
		cin >> b[j];

	ds = DS(n+2);

	while (m--) {
		cin >> u >> v;
		ds.joint(u, v);
	}

	fill(gc, gc+1005, 0);
	fill(bc, bc+1005, 0);
	ing = vvi(n+2);

	for (int i = 1; i <= n; i++) {
		ing[ds.parent(i)].push_back(i);
		gc[ds.parent(i)] += c[i];
		bc[ds.parent(i)] += b[i];
	}

	dp = vvi(n+2, vi(w+2, -1));

	cout << obtRes(1, 0) << endl;

	return 0;
}