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
typedef vector<ll> vi;
typedef vector<ii> vii;

const int MX = 300005, mod = 1000000007;

struct ST {
	ll si, sj, res;
	int cn;
	ST() : res(0), si(0), sj(0), cn(0) {}
}st[8 * MX];

int n, p[MX], q, x[MX], k[MX], in[2 * MX];
ll p2[MX], inv[MX];
vii c;

void build (int i, int j, int pos) {
	if (i == j) {
		in[i] = pos;
		return;
	}
	int m = (i + j) / 2;
	build(i, m, pos * 2);
	build(m + 1, j, pos * 2 + 1);
}

void update (int x, int k) {
	int pos = in[x];
	st[pos].si = k;
	st[pos].sj = inv[1] * k % mod;
	st[pos].cn = bool(k);

	pos /= 2;
	while (pos) {
		int izq = st[pos * 2].cn;
		
		st[pos].res = (st[pos * 2].res + st[pos * 2 + 1].res
					+ st[pos * 2].si * inv[izq] % mod * st[pos * 2 + 1].sj) % mod;
		
		st[pos].si = (st[pos * 2].si + p2[izq] * st[pos * 2 + 1].si) % mod;
		st[pos].sj = (st[pos * 2].sj + inv[izq] * st[pos * 2 + 1].sj) % mod;
		
		st[pos].cn = st[pos * 2].cn + st[pos * 2 + 1].cn;
		
		pos /= 2;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	p2[0] = inv[0] = 1;
	p2[1] = 2;
	inv[1] = 500000004;

	for (int i = 2; i < MX; i++) {
		p2[i] = p2[i - 1] * 2 % mod;
		inv[i] = inv[i - 1] * inv[1] % mod;
	}
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		c.emplace_back(p[i], i);
	}

	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> x[i] >> k[i];
		c.emplace_back(k[i], x[i]);
	}

	sort(all(c));
	c.erase(unique(all(c)), c.end());
	build(1, c.size(), 1);

	#define find(x) upper_bound(all(c), ii(p[x], x)) - c.begin()

	for (int i = 1; i <= n; i++)
		update(find(i), p[i]);
	cout << st[1].res << endl;

	for (int i = 0; i < q; i++) {
		update(find(x[i]), 0);
		p[x[i]] = k[i];
		update(find(x[i]), p[x[i]]);
		cout << st[1].res << endl;
	}

	return 0;
}