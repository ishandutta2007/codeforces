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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n;
ll x, k, a[MX];

void solve () {
	cin >> n >> k >> x;
	
	forn (i, n)
		cin >> a[i];
	sort(a, a + n);
	
	vi v;
	forn (i, n - 1)
		v.pb(max(0ll, (a[i + 1] - a[i] - 1) / x));
	sort(all(v));
	
	int res = n;
	for (ll b : v) {
		if (b > k)
			break;
		res--;
		k -= b;
	}
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--)
		solve();
	
	return 0;
}