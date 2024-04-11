#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i = (a); i != (b); ++i)
#define REP(i,n) rep(i,0,n)
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

ll run()
{
	int n, m;
	vi v, w;

	cin >> n; v.resize(n); REP(i, n) cin >> v[i];
	cin >> m; w.resize(m); REP(i, m) cin >> w[i];

	int l = 0, r = 0;
	ll diff = 0;
	int ret = 0;

	while (l < n || r < m) {
		if (diff == 0) {
			diff = v[l++] - w[r++];
		} else if (diff < 0) {
			if (l >= n) {
				// v exhausted
				return -1;
			}
			diff += v[l++];
		} else {
			if (r >= m) {
				// w exhausted
				return -1;
			}
			diff -= w[r++];
		}

		ret += (diff == 0);
	}

	// the total sums differ.
	if (diff != 0)
		return -1;

	// ret == 0 => no pieces glued.
	return ret == 0 ? -1 : ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll ans = run();
	cout << ans << endl;

	return 0;
}