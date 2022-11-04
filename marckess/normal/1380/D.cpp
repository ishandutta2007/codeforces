#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, m, a[MX], b[MX];
ll x, y, k, res;

void del (int i, int j) {
	if (i > j) return;

	int len = j - i + 1;
	ll p = 1e18;

	int md = 0, me = 0;
	if (i) me = max(me, a[i - 1]);
	if (j + 1 < n) me = max(me, a[j + 1]);

	for (int k = i; k <= j; k++)
		md = max(md, a[k]);

	if (me > md) {
		p = min(p, len * y);
	}

	if (len >= k) {
		p = min(p, x + (len - k) * y);
		p = min(p, (len / k) * x + (len % k) * y);
	}

	if (p == 1e18) {
		cout << -1 << endl;
		exit(0);
	}

	res += p;
}

void solve () {
	cin >> n >> m;
	cin >> x >> k >> y;
	forn (i, n) cin >> a[i];
	forn (i, m) cin >> b[i];

	int j = 0;
	forn (i, n) if (j < m && a[i] == b[j]) j++;

	if (j < m) {
		cout << -1 << endl;
		return;
	}

	int ant = -1;
	res = j = 0;

	forn (i, n) if (j < m && a[i] == b[j]) {
		del(ant + 1, i - 1);
		j++;
		ant = i;
	}

	del(ant + 1, n - 1);

	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t = 1;
	//cin >> t;
	while (t--)
		solve();

	return 0;
}