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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 100005;
int n, w, h, g[MX], p[MX], t[MX], rx[MX], ry[MX], x[MX], y[MX];
map<int, vi> mp;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> w >> h;
	for (int i = 0; i < n; i++) {
		cin >> g[i] >> p[i] >> t[i];
		
		if (g[i] == 1) 
			x[i] = p[i], y[i] = -t[i];
		else
			x[i] = -t[i], y[i] = p[i];

		mp[x[i] + y[i]].pb(i);
	}

	for (auto it = mp.begin(); it != mp.end(); it++) {
		vi &v = it->se;
		sort(all(v), [&] (int i, int j) {
			return x[i] < x[j];
		});

		int off = 0;
		vi a, b;
		for (int i : v)
			if (x[i] <= 0) {
				off++;
				a.pb(w);
				b.pb(y[i]);
			} else {
				a.pb(x[i]);
				b.pb(h);
			}

		for (int i = 0; i < v.size(); i++) {
			rx[v[i]] = a[(i+off)%v.size()];
			ry[v[i]] = b[(i+off)%v.size()];
		}
	}

	for (int i = 0; i < n; i++)
		cout << rx[i] << " " << ry[i] << endl;

	return 0;
}