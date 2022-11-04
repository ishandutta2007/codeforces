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
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, m, a[MX], res[MX], mx[MX], b[MX];
ll s;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	forn (i, m) {
		cin >> a[i];
		b[i] = a[i] + i;
		if (b[i] > n) {
			cout << -1 << endl;
			return 0;
		}
		s += a[i];
	}

	if (s < n) {
		cout << -1 << endl;
		return 0;
	}

	for (int i = m - 1, j = 1; i >= 0; i--) {
		res[i] = min(j, n - b[i] + 1);
		j = max(j, res[i] + a[i]);
	}

	forn (i, m)
		cout << res[i] << " ";
	cout << endl;

	return 0;
}