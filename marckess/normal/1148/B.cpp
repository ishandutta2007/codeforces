#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) emplace_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, m, k, ta, tb, a[MX], b[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> ta >> tb >> k;
	forn(i, n) cin >> a[i];
	forn(i, m) cin >> b[i];

	if (k >= n) {
		cout << -1 << endl;
		return 0;
	}

	int res = 0;
	for (int i = 0; i <= min(k, n - 1); i++) {
		int j = lower_bound(b, b+m, a[i] + ta) - b;
		if (j + (k - i) >= m) {
			cout << -1 << endl;
			return 0;
		}
		res = max(res, b[j + (k - i)] + tb);
	}
	cout << res << endl;

	return 0;
}