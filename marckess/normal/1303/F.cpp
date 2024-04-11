#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 2000005;
int n, m, q, res[MX], p[MX], cn, ini[MX], fin[MX], x[MX], y[MX], c[MX], a[305][305];
int mx[] = {1, -1, 0, 0};
int my[] = {0, 0, 1, -1};
vi pos[MX], adj[MX];
vii col[MX];

#define num(i,j) ((i) * m + (j))

int parent (int a) {
	return p[a] == a ? a : p[a] = parent(p[a]);
}

int join (int a, int b) {
	a = parent(a), b = parent(b);
	if (a == b) return 0;
	p[a] = b;
	return 1;
}

bool valid (int i, int j) {
	return 0 <= i && i < n && 0 <= j && j < m;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> q;
	res[0] = 1;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			col[0].emplace_back(i, j);

	for (int i = 1; i <= q; i++) {
		cin >> x[i] >> y[i] >> c[i];
		x[i]--, y[i]--;

		col[c[i]].emplace_back(x[i], y[i]);
		if (!ini[c[i]]) ini[c[i]] = i;
		fin[c[i]] = i;
	}

	for (int i = 0; i < MX; i++) {
		sort(all(col[i]));
		col[i].erase(unique(all(col[i])), col[i].end());
	}

	for (int i = 1; i < MX; i++)
		if (ini[i]) {
			for (ii &x : col[i])
				p[num(x.fi, x.se)] = num(x.fi, x.se);

			for (int j = ini[i]; j <= fin[i]; j++) {
				if (a[x[j]][y[j]] == i) continue;
				
				for (int l = 0; l < 4; l++)
					if (valid(x[j] + mx[l], y[j] + my[l]) && a[x[j]][y[j]] == a[x[j] + mx[l]][y[j] + my[l]])
						adj[j].pb(num(x[j] + mx[l], y[j] + my[l]));

				pos[a[x[j]][y[j]]].pb(j);
				a[x[j]][y[j]] = c[j];
				res[j]++;

				for (int l = 0; l < 4; l++)
					if (valid(x[j] + mx[l], y[j] + my[l]) && i == a[x[j] + mx[l]][y[j] + my[l]])
						res[j] -= join(num(x[j], y[j]), num(x[j] + mx[l], y[j] + my[l]));
			}
		}

	for (int i = 0; i < MX; i++)
		if (pos[i].size()) {
			for (ii &x : col[i])
				p[num(x.fi, x.se)] = num(x.fi, x.se);

			for (ii &x : col[i])
				if (a[x.fi][x.se] == i)
					for (int l = 0; l < 4; l++)
						if (valid(x.fi + mx[l], x.se + my[l]) && a[x.fi + mx[l]][x.se + my[l]] == i)
							join(num(x.fi, x.se), num(x.fi + mx[l], x.se + my[l]));

			reverse(all(pos[i]));

			for (int j : pos[i]) {
				res[j]--;
				for (int v : adj[j])
					res[j] += join(num(x[j], y[j]), v);
			}
		}

	for (int i = 1; i <= q; i++) {
		res[i] += res[i - 1];
		cout << res[i] << endl;
	}

	return 0;
}