#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, a[MX], res;
vi pos[MX];

void solve () {
	cin >> n;
	
	for (int i = 1; i <= n; i++)
		pos[i].clear();
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pos[a[i]].pb(i);
	}
	
	res = n;
	for (int i = 1; i <= n; i++)
		if (pos[i].size()) {
			int p = 0;
			forn (j, pos[i].size()) {
				if (j) {
					if (pos[i][j - 1] + 1 < pos[i][j]) p++;
				} else {
					if (pos[i][j] > 1) p++;
				}
			}
			if (pos[i].back() < n) p++;
			res = min(res, p);
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