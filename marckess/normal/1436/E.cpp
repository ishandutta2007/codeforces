#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, a[MX], p[MX], sig[MX], ex[MX], uno;
int st[4 * MX];

void build (int i, int j, int pos) {
	if (i == j) {
		p[i] = pos;
		return;
	}
	int m = (i + j) / 2;
	build(i, m, pos * 2);
	build(m + 1, j, pos * 2 + 1);
}
	
void update (int i, int x) {
	int pos = p[i];
	st[pos] = x;
	pos /= 2;
	
	while (pos) {
		st[pos] = max(st[pos * 2], st[pos * 2 + 1]);
		pos /= 2;
	}
}

int query (int i, int j, int pos, int x) {
	if (j <= x) return st[pos];
	if (x < i) return 0;
	int m = (i + j) / 2;
	return max(
		query(i, m, pos * 2, x),
		query(m + 1, j, pos * 2 + 1, x)
	);
}

void solve () {
	cin >> n;
	
	build(1, n, 1);
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		update(i, 1e9);
		sig[i] = n + 1;
		if (a[i] == 1) uno++;
	}
	sig[n + 1] = n + 1;
	
	if (uno == n) {
		cout << 1 << endl;
		return;
	}
	
	for (int i = n; i > 0; i--) {
		if (a[i] > 1) {
			int x = query(1, n, 1, a[i] - 1);
			if (x < sig[a[i]]) ex[a[i]] = 1;
		}
		sig[a[i]] = i;
		update(a[i], i);
	}
	
	for (int i = 2; i <= n + 1; i++) {
		int x = query(1, n, 1, i - 1);
		if (x < sig[i]) ex[i] = 1;
	}
	
	for (int i = 2; i <= n + 1; i++)
		if (!ex[i]) {
			cout << i << endl;
			return;
		}
	cout << n + 2 << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--)
		solve();
	
	return 0;
}