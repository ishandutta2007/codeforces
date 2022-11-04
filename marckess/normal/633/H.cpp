#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define find(v,x) (lower_bound(all(v), x) - v.begin())

const int MX = 30005, SQ = 175;
int n, mod, a[MX], b[MX], q, l[MX], r[MX], ord[MX], res[MX];
int st[4*MX], aux[4*MX], s[4*MX], cn[MX], f[MX], p[MX];
vi c;

void build (int i, int j, int pos) {
	if (i == j) {
		p[i] = pos;
		return;
	}

	int m = (i+j)/2;
	build(i, m, pos*2);
	build(m+1, j, pos*2+1);
}

void update (int x, int k) {
	int pos = p[x];
	cn[x] += k;

	if (cn[x] > 0) st[pos] = c[x-1], s[pos] = 1;
	else st[pos] = 0, s[pos] = 0;

	pos /= 2;
	while (pos) {
		int z = s[pos*2];
		
		s[pos] = s[pos*2] + s[pos*2+1];
		st[pos] = (st[pos*2] + f[z+1] * st[pos*2+1] + f[z] * aux[pos*2+1]) % mod;
		if (z) aux[pos] = (aux[pos*2] + f[z] * st[pos*2+1] + f[z-1] * aux[pos*2+1]) % mod;
		else aux[pos] = aux[pos*2+1];

		pos /= 2;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> mod;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		c.pb(a[i]);
	}

	f[1] = f[2] = 1;
	for (int i = 3; i < MX; i++)
		f[i] = (f[i-1] + f[i-2]) % mod;

	build(1, n, 1);

	sort(all(c));
	c.erase(unique(all(c)), c.end());

	for (int i = 1; i <= n; i++)
		b[i] = find(c, a[i]) + 1;

	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> l[i] >> r[i];
		ord[i] = i;
	}

	sort(ord, ord+q, [&] (int i, int j) {
		return l[i] / SQ ^ l[j] / SQ ? l[i] < l[j] : r[i] < r[j];
	});

	int i = 1, j = 0;
	for (int _ = 0; _ < q; _++) {
		int u = ord[_];

		while (i < l[u]) update(b[i++], -1);
		while (i > l[u]) update(b[--i], 1);
		while (j < r[u]) update(b[++j], 1);
		while (j > r[u]) update(b[j--], -1);

		res[u] = st[1];
	}

	for (int i = 0; i < q; i++)
		cout << res[i] << endl;

	return 0;
}