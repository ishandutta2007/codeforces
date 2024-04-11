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
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1000005;
int n, a[MX], q, w, bs[MX];
map<vi, int> mp;

void solve () {
	cin >> n;
	
	mp.clear();
	forn (i, n) {
		cin >> a[i];
		
		int x = a[i];
		vi v;
		
		while (x > 1) {
			int p = bs[x], pw = 0;
			
			while (x % p == 0) {
				x /= p;
				pw++;
			}
			
			if (pw & 1)
				v.pb(p);
		}
		
		sort(all(v));
		mp[v]++;
	}
	
	int res0 = 0, res1 = 0;
	map<vi, int> mp1;
	for (auto &it : mp) {
		res0 = max(res0, it.se);
		if (it.se & 1) mp1[it.fi] += it.se;
		else mp1[{}] += it.se;
	}
	for (auto &it : mp1)
		res1 = max(res1, it.se);
	
	cin >> q;
	while (q--) {
		ll w;
		cin >> w;
		if (w) cout << res1 << endl;
		else cout << res0 << endl;
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
				
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}