#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define FORR(i,a,b) for (int i = a; i <= b; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 100005, lim = 1e9;
int n, m, y, a[MX], b[MX], res = 0;
map<int, int> mp;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
		
	cin >> n >> y;
	for (int i = 0; i < n; i++) cin >> a[i];

	cin >> m >> y;
	for (int i = 0; i < m; i++) cin >> b[i];

	ll i = 1;
	while (i <= lim) {
		ll j = 2 * i;
		mp.clear();

		for (int k = 0; k < n; k++) mp[a[k]%j]++;
		for (int k = 0; k < m; k++) mp[(b[k]-i+j)%j]++;

		for (auto &it : mp)
			res = max(res, it.se);

		i *= 2;
	}

	cout << max(res, 2) << endl;

	return 0;
}