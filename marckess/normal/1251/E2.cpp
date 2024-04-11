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

const int MX = 200005;
int n;
ii a[MX];
multiset<int> pq;

void solve () {
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> a[i].fi >> a[i].se;
	sort(a, a+n);

	ll res = 0;
	pq.clear();

	for (int i = n - 1, cn = 0; i >= 0; ) {
		int act = a[i].fi;

		while (i >= 0 && a[i].fi == act) {
			pq.insert(a[i].se);
			i--;
		}

		while (cn + i + 1 < act) {
			res += *pq.begin();
			pq.erase(pq.begin());
			cn++;
		}
	}

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