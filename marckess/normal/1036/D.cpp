#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 300005;
int n, m;
ll a[MX], b[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i) a[i] += a[i-1];
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> b[i];
		if (i) b[i] += b[i-1];
	}

	if (a[n-1] != b[m-1]) {
		cout << -1 << endl;
		return 0;
	}

	int res = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == *lower_bound(b, b+m, a[i]))
			res++;
	}

	cout << res << endl;

	return 0;
}