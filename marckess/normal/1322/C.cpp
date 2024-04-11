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
typedef vector<ll> vi;
typedef vector<ii> vii;

const int MX = 500005;
int n, m;
ll c[MX], res;
vi inv[MX];
map<vi, ll> mp;

void solve () {
	res = 0;
	mp.clear();

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		inv[i].clear();
	}

	while (m--) {
		int a, b;
		cin >> a >> b;
		inv[b].pb(a);
	}

	for (int i = 1; i <= n; i++) {
		sort(all(inv[i]));
		if (inv[i].size())
			mp[inv[i]] += c[i];
	}

	for (auto it = mp.begin(); it != mp.end(); it++) 
		res = __gcd(res, it->se);

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