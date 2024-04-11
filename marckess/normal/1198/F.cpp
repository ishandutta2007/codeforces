#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb emplace_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 100005;
int n, a[MX], b[MX], res[MX];
vi px, py, can, cm;
bitset<(1<<20)+5> bs[200];

void fac (int n, vi &p) {
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0) {
			p.pb(i);
			while (n % i == 0) n /= i;
		}
	if (n - 1) p.pb(n);
}

void fcan (int x, int y, vi p) {
	for (int k : p)
		for (int i = 0, j = 0; i < n && j < 10; i++)
			if (i != x && i != y && a[i] % k)
				can.pb(i), j++;
}

bool dfs (int i, int mk) {
	if (!mk) return 1;
	if (i == cm.size()) return 0;
	if (bs[i][mk]) return 0;
	bs[i][mk] = 1;

	int fi = cm[i] & ((1 << px.size()) - 1);
	int se = cm[i] & ~((1 << px.size()) - 1);
	
	if (dfs(i + 1, mk & ~fi)) return 1;
	if (dfs(i + 1, mk & ~se)) {
		res[can[i]] = 1;
		return 1;
	}

	return 0;
}

bool solve (int x, int y) {
	px.clear(), py.clear();
	fac(a[x], px), fac(a[y], py);

	can.clear();
	fcan(x, y, px), fcan(x, y, py);

	sort(all(can));
	can.erase(unique(all(can)), can.end());

	cm.clear();
	forn(j, can.size()) {
		int mk = 0, k = can[j];

		forn(i, px.size())
			if (a[k] % px[i])
				mk |= 1 << i;

		forn(i, py.size())
			if (a[k] % py[i])
				mk |= 1 << (i + px.size());

		cm.pb(mk);
	}

	int mk = (1 << (px.size() + py.size())) - 1;
	for (int i = 0; i <= cm.size(); i++)
		bs[i].reset();
	return dfs(0, mk);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	forn(i, n) cin >> a[i];

	srand(time(0));
	iota(b, b+n, 0);
	random_shuffle(b, b+n);

	for (int i = 1; i < min(n, 10); i++)
		if (solve(b[0], b[i])) {
			res[b[i]] = 1;

			cout << "YES" << endl;
			forn(i, n) cout << res[i] + 1 << " ";
			cout << endl;
			return 0;
		}

	cout << "NO" << endl;

	return 0;
}