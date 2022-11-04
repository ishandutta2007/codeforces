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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, m, a[MX], b[MX], c[MX], ind;
map<int, vi> mp;
vi res;

void solve () {
	cin >> n >> m;
	mp.clear();
	
	forn (i, n) {
		cin >> a[i];
	}
	
	forn (i, n) {
		cin >> b[i];
		if (a[i] != b[i])
			mp[b[i]].pb(i);
	}
	
	forn (i, m) cin >> c[i];
	
	res.clear();
	ind = -1;
	
	for (int i = m - 1; i >= 0; i--) {
		if (mp[c[i]].size()) {
			res.pb(mp[c[i]].back());
			ind = mp[c[i]].back();
			mp[c[i]].pop_back();
		} else if (ind != -1) {
			res.pb(ind);
		} else {
			int f = 0;
			
			forn (j, n)
				if (a[j] == b[j] && b[j] == c[i]) {
					ind = j;
					res.pb(j);
					f = 1;
					break;
				}
				
			if (!f) {
				cout << "NO" << endl;
				return;
			}
		}
	}
	
	for (const auto &it : mp)
		if (it.se.size()) {
			cout << "NO" << endl;
			return;
		}
	
	cout << "YES" << endl;
	reverse(all(res));
	for (int x : res)
		cout << x + 1 << " ";
	cout << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}