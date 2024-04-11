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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n;
ll a[MX], b[MX], q[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		q[i] = i;
	}

	sort(q, q+n, [&] (int i, int j) {
		return a[i] - b[i] > a[j] - b[j];
	});

	ll res = 0;
	for (ll j = 1; j <= n; j++) {
		int u = q[j-1];
		res += a[u] * (j - 1) + b[u] * (n - j);
	}
	cout << res << endl;
	
	return 0;
}