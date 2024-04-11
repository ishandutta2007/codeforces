#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define fi first
#define se second
#define endl '\n'
#define MOD(n,k) ( (n % k) + k ) % k
#define isOn(S, j) (S & (1 << j) )
#define setBit(S, j) (S | (1 << j ) )
#define LSB(S) (S & (-S))

ll n, m, p, a[1005], b[2005], res = 1e18, mx;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m >> p;	

	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];

	sort(a, a+n);
	sort(b, b+m);

	for (int k = 0, lim = m - n; k <= lim; k++) {
		mx = 0;

		for (int i = 0; i < n; i++)
			mx = max (mx, abs(a[i] - b[i+k]) + abs(b[i+k] - p) );

		res = min(res, mx);
	}

	cout << res << endl;

	return 0;
}