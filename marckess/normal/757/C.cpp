#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1000005, mod = 1e9+7;
int n, m, g, x;
ll res = 1, fac[MX];
vii pos[MX];
map<vii, int> mp;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	fac[0] = 1;
	for (int i = 1; i < MX; i++)
		fac[i] = (fac[i-1] * i) % mod;
	
	cin >> n >> m;
	while (n--) {
		cin >> g;

		while (g--) {
			cin >> x;

			if (pos[x].empty() || pos[x].back().fi != n) {
				pos[x].emplace_back(n, 1);
			} else {
				pos[x].back().se++;
			}
		}
	}

	for (int i = 1; i <= m; i++)
		mp[pos[i]]++;

	for (auto it : mp)
		res = res * fac[it.se] % mod;

	cout << res << endl;

	return 0;
}