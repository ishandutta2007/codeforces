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

const int MX = 1'500'005;
int n, m;
ll d, a[305], b[305], t[305];
ll dp[2][MX], sum = 0, mx = numeric_limits<ll>::min();
deque<pair<int, ll>> q;

void insert (int i, ll k) {
	while (q.size() && q.back().se < k)
		q.pop_back();
	q.emplace_back(i, k);
}

ll query (ll i) {
	while (q.front().fi < i)
		q.pop_front();
	return q.front().se;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> d;
	for (int i = 0; i < m; i++) {
		cin >> a[i] >> b[i] >> t[i];
		sum += b[i];
	}
	t[m] = t[m-1];

	for (int i = m - 1; i >= 0; i--) {
		int x = i % 2, y = 1 - x;
		ll e = (t[i+1] - t[i]) * d;

		for (int j = 1, k = 1; j <= n; j++) {
			while (k <= n && k <= j + e) {
				insert(k, dp[y][k]);
				k++;
			}
			dp[x][j] = query(j - e) - abs(a[i] - j);
		}

		q.clear();
	}

	for (int i = 1; i <= n; i++)
		mx = max(mx, dp[0][i]);

	cout << sum + mx << endl;

	return 0;
}