#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define FORR(i,a,b) for (int i = a; i <= b; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 1005;
ll n, m, k, p, a[MX][MX], sx[MX], sy[MX];
ll x[MX*MX], y[MX*MX];

priority_queue<ll> pq;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m >> k >> p;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			sx[i] += a[i][j];
			sy[j] += a[i][j];
		}

	for (int i = 0; i < n; i++) pq.push(sx[i]);

	for (int i = 1; i <= k; i++) {
		ll b = pq.top();
		pq.pop();

		x[i] = b;
		pq.push(b - p * m);
	}

	while (pq.size()) pq.pop();

	for (int i = 0; i < m; i++) pq.push(sy[i]);

	for (int i = 1; i <= k; i++) {
		ll b = pq.top();
		pq.pop();

		y[i] = b;
		pq.push(b - p * n);
	}

	ll g = 0, h = 0, res = -1e18;
	ll i = 0, j = k;

	for (int i = 0; i <= k; i++) h += y[i];

	while (i <= k) {
		res = max(res, g + h - i * j * p);
		g += x[++i];
		h -= y[j--];
	}

	cout << res << endl;

	return 0;
}