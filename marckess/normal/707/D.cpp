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

int n, m, q, op[100005], i[100005], j[100005], res[100005], act = 0, c[1005] = {0}, cn = 0, mv[100005];
vvi adj;
bitset<1000005> bs;
bitset<1005> f;

void dfs (int u);

void move (int u) {
	res[u] = cn;

	for (int v : adj[u])
		dfs(v);
}

void dfs (int u) {
	int x = i[u]-1, y = j[u]-1;

	if (op[u] == 1) {
		if (f[x] == bs[x * m + y]) {
			bs.flip(x*m+y);
			c[x]++;
			cn++;

			move(u);

			bs.flip(x*m+y);
			c[x]--;
			cn--;
		} else {
			move(u);
		}
	}

	if (op[u] == 2) {
		if (f[x] != bs[x * m + y]) {
			bs.flip(x*m+y);
			c[x]--;
			cn--;

			move(u);

			bs.flip(x*m+y);
			c[x]++;
			cn++;
		} else {
			move(u);
		}
	}

	if (op[u] == 3) {
		cn -= c[x];
		c[x] = m - c[x];
		cn += c[x];
		f[x] = f[x] ^ 1;

		move(u);

		cn -= c[x];
		c[x] = m - c[x];
		cn += c[x];
		f[x] = f[x] ^ 1;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> q;
	adj = vvi(q+1);
	
	op[0] = 2;
	i[0] = 1;
	j[0] = 1;

	iota(mv, mv+q+1, 0);

	for (int l = 1; l <= q; l++) {
		cin >> op[l];

		if (op[l] == 4) {
			cin >> i[l];
			act = mv[i[l]];
			mv[l] = mv[i[l]];
		} else {
			cin >> i[l];
			if (op[l] != 3)
				cin >> j[l];

			adj[act].push_back(l);
			act = l;
		}
	}

	dfs(0);
	for (int l = 1; l <= q; l++) {
		if (op[l] == 4)
			res[l] = res[i[l]];
	}

	for (int i = 1; i <= q; i++)
		cout << res[i] << endl;

	return 0;
}