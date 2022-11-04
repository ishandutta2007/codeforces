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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 200005;
int n, q;
ll a[MX], cn[MX], res;
map<ii, int> mp;

int f (int n) {
	return max(0ll, cn[n] - a[n]);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		res += a[i];
	}

	cin >> q;
	while (q--) {
		int s, t, u;
		
		cin >> s >> t >> u;
		
		if (mp.count({s, t})) {
			res -= f(mp[{s, t}]);
			cn[mp[{s, t}]]--;
			res += f(mp[{s, t}]);
			mp.erase({s, t});
		}

		if (u) {
			res -= f(u);
			cn[u]++;
			res += f(u);
			mp[{s, t}] = u;
		}

		cout << res - (int)mp.size() << endl;
	}

	return 0;
}