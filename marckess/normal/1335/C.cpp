#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int n, a;
map<int, int> mp;

void solve () {
	mp.clear();
	
	cin >> n;
	forn (i, n) {
		cin >> a;
		mp[a]++;
	}

	int mx = 0;
	for (auto it : mp)
		mx = max(mx, it.se);

	cout << max(
		min(mx, int(mp.size()) - 1),
		min(mx - 1, int(mp.size()))
	) << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}