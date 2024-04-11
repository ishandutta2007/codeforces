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

const int MX = 200005, mod = 1000000007;
int n, q, a[MX], bs[MX], act[MX];
ll res;
map<int, int> mp[MX];
multiset<int> mst[MX];
vi in[MX];

void update (int i, map<int, int> &mp, int x) {
	while (x > 1) {
		int p = bs[x];
		
		if (!mp.count(p))
			in[p].pb(i);
		else
			mst[p].erase(mst[p].find(mp[p]));
		
		while (x % p == 0) {
			x /= p;
			mp[p]++;
		}
		
		mst[p].insert(mp[p]);
		
		if (in[p].size() == n)
			while (act[p] != *mst[p].begin()) {
				(res *= p) %= mod;
				act[p]++;
			}
	}
}

void solve () {
	cin >> n >> q;
	res = 1;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		update(i, mp[i], a[i]);
	}
	
	while (q--) {
		int i, x;
		cin >> i >> x;
		update(i, mp[i], x);
		cout << res << endl;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	for (ll i = 2; i < MX; i++)
		if (!bs[i]) {
			bs[i] = i;
			for (ll j = i * i; j < MX; j += i)
				bs[j] = i;
		}
		
	int t = 1;
	// cin >> t;
	while (t--)
		solve();
	
	return 0;
}