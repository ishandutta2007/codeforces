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
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 300005;

struct PST {
	PST *izq, *der;
	int x;

	PST () : izq(0), der(0), x(0) {}
	PST (PST *izq, PST *der) : izq(izq), der(der), x(0) {}
	PST (int x) : izq(0), der(0), x(x) {}

	void build (int i, int j) {
		if (i == j) return;
		int m = (i + j) / 2;
		(izq = new PST)->build(i, m);
		(der = new PST)->build(m + 1, j);
	}

	PST * update (int i, int j, int x, int k) {
		if (j < x || x < i) return this;
		if (i == j) return new PST(k);
		int m = (i + j) / 2;
		return new PST(
			izq->update(i, m, x, k),
			der->update(m + 1, j, x, k)
		);
	}

	int query (int i, int j, int x) {
		if (i == j) return this->x;
		int m = (i + j) / 2;
		if (x <= m)
			return izq->query(i, m, x);
		return der->query(m + 1, j, x);
	}
};

PST *st[MX];
int n, a[MX], dp[MX];
ll res;

void init () {
	res = 0;
	for (int i = 1; i <= n + 1; i++)
		dp[i] = 0;
	(st[n + 1] = new PST)->build(1, n);
}

void solve () {
	cin >> n;
	init();

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = n; i; i--) {
		int sig = st[i + 1]->query(1, n, a[i]);

		if (sig) {
			dp[i] = 1 + dp[sig + 1];
			st[i] = st[sig + 1]->update(1, n, a[i], i);
		} else {
			st[i] = st[n + 1]->update(1, n, a[i], i);	
		}

		res += dp[i];
	}

	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}