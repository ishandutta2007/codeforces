#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define FORR(i,a,b) for (int i = a; i <= b; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

int n, m;
char c;
ll a[55];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> c;
			if (c == '#')
				a[i] += (1ll << j);
		}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			ll k = a[i] & a[j];
			if (k && (k != a[i] || k != a[j])) {
				cout << "No" << endl;
				return 0;
			}
		}

	cout << "Yes" << endl;

	return 0;
}