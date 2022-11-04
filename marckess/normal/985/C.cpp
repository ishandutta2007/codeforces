#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int MX = 100005;
int n, k, l, a[MX], cn = 0, m, mn;
ll res = 0;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k >> l;
	m = n * k;
	for (int i = 0; i < m; i++)
		cin >> a[i];
	mn = *min_element(a, a+m);
	sort(a, a+m);

	for (int i = 0; i < m; i++)
		if (a[i] <= mn + l)
			cn++;

	if (cn < n) {
		cout << 0 << endl;
		return 0;
	}

	for (int x = 0, y = 0; x < n; x++) {
		res += a[y++];
		cn--;

		for (int z = 1; z < k; z++) {
			if (cn >= n - x) {
				cn--;
				y++;
			} else {
				break;
			}
		}
	}

	cout << res << endl;

	return 0;
}