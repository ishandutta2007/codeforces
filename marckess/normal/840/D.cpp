#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MX = 300005;
int n, q, a[MX], vis[MX], col;
vi pos[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pos[a[i]].pb(i);
	}
	
	while (q--) {
		int l, r, k;
		cin >> l >> r >> k;
		
		int t = (r - l + 1) / k, res = MX;
		col++;
		
		forn (kk, 70) {
			int x = a[uniform_int_distribution<int>(l, r)(rng)];
			
			if (vis[x] == col)
				continue;
			vis[x] = col;
			
			if (pos[x].size() <= t)
				continue;

			int f = upper_bound(all(pos[x]), r) - lower_bound(all(pos[x]), l);
			
			if (f > t)
				res = min(res, x);
		}
		
		if (res == MX) cout << -1 << endl;
		else cout << res << endl;
	}
		
	return 0;
}