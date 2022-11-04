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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1005;
int n;
ll x[MX], a[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];

	vi res;
	for (int k = 1; k <= n; k++) {
		bool f = 1;
		for (int i = 1; i <= n; i++) {
			if (i <= k) x[i-1] = a[i] - a[i-1];
			else f &= (a[i] == x[(i-1)%k] + a[i-1]);
		}
		if (f) res.pb(k);
	}

	cout << res.size() << endl;
	for (int x : res) cout << x << " ";
		cout << endl;

	return 0;
}