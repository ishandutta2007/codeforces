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
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n;
ll a[MX], mx;

void solve () {
	cin >> n;

	mx = 0;
	forn (i, n) {
		cin >> a[i];
		if (i) {
			if (a[i - 1] > a[i]) {
				mx = max(mx, a[i - 1] - a[i]);
				a[i] = a[i - 1];
			}
		}
	}

	int res = 0;
	for (int i = 0; (1ll << i) <= mx; i++)
		if (mx & (1ll << i))
			res = i + 1;
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