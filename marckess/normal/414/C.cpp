#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

#define find(v,x) (lower_bound(ALL(v), x) - v.begin() + 1);

const int MX = (1<<20)+5;
int n, q, a[MX], b, r;
vi c;
ll res = 0;

// BIT
int ft[MX];

void update (int i, int k) {
	while (i < MX) {
		ft[i] += k;
		i += i & -i;
	}
}

int query (int i) {
	int sum = 0;
	while (i) {
		sum += ft[i];
		i -= i & -i;
	}
	return sum;
}
// ---

ll cn[MX], par[22], inv[22];

void obtInv (int i, int j, int k) {
	if (!k) return;

	int l = i - 1, r = j - 1, m = (i + j) / 2 - 1;

	for (int o = m+1; o <= r; o++)
		update(a[o], 1);

	for (int o = l; o <= m; o++) {
		int d = query(a[o]-1);
		inv[k] += d;
		par[k] += (m - l + 1) - query(a[o]) + d;
	}

	for (int o = m+1; o <= r; o++)
		update(a[o], -1);

	obtInv(i, m+1, k-1);
	obtInv(m+2, j, k-1);
}

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	
	scanf("%d", &r);
	n = (1 << r);
	for (int i = 0; i < n; i++) {
		scanf("%d", a+i);
		c.push_back(a[i]);
	}

	sort(ALL(c));
	c.erase(unique(ALL(c)), c.end());

	for (int i = 0; i < n; i++)
		a[i] = find(c, a[i]);
	
	obtInv(1, n, r);

	scanf("%d", &q);
	while (q--) {
		scanf("%d", &b);
		
		for (int i = 1; i <= b; i++)
			inv[i] = par[i] - inv[i];

		res = 0;
		for (int i = 1; i <= r; i++)
			res += inv[i];

		cout << res << endl;
	}

	return 0;
}