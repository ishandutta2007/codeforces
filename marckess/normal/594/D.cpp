#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define find(v,x) (lower_bound(ALL(v), x) - v.begin())

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 200005, mod = 1'000'000'007;
ll st[4*MX];

void push (int i, int j, int pos) {
	if (i < j) {
		st[pos*2] = st[pos] * st[pos*2] % mod;
		st[pos*2+1] = st[pos] * st[pos*2+1] % mod;
		st[pos] = 1;
	}
}

void update (int i, int j, int pos, int a, int b, int k) {
	push(i, j, pos);

	if (b < i || j < a) return;

	if (a <= i && j <= b) {
		st[pos] = st[pos] * k % mod;
		push(i, j, pos);
		return;
	}

	int m = (i+j)/2;
	update(i, m, pos*2, a, b, k);
	update(m+1, j, pos*2+1, a, b, k);
}

ll query (int i, int j, int pos, int x) {
	push(i, j, pos);

	if (x < i || j < x) return 1;
	if (i == j) return st[pos];

	int m = (i+j)/2;
	return query(i, m, pos*2, x) * query(m+1, j, pos*2+1, x);
}

vi f[1000005];
bitset<1000005> bs;
void criba () {
	for (ll i = 2; i < 1000005; i++) 
		if (!bs[i]) 
			for (ll j = i; j < 1000005; j += i) {
				f[j].push_back(i);
				bs[j] = 1;
			}
}

int n, a[MX], Q, l[MX], r[MX], ant[1'000'005];
ll res[MX], acu[MX];
vi q[MX];

ll pot (ll b, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) res = res * b % mod;
		b = b * b % mod;
		p /= 2;
	}
	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	fill(st, st+4*MX, 1);	
	criba();
	acu[0] = 1;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		acu[i] = acu[i-1] * a[i] % mod;
	}

	cin >> Q;
	for (int i = 0; i < Q; i++) {
		cin >> l[i] >> r[i];
		q[r[i]].push_back(i);
	}

	for (int i = 1; i <= n; i++) {
		for (int x : f[a[i]]) {
			update(1, n, 1, ant[x]+1, i, ll(x - 1) * pot(x, mod-2) % mod);
			ant[x] = i;
		}

		for (int x : q[i])
			res[x] = query(1, n, 1, l[x]);
	}

	for (int i = 0; i < Q; i++)
		cout << res[i] * acu[r[i]] % mod * pot(acu[l[i]-1], mod-2) % mod << endl;

	return 0;
}