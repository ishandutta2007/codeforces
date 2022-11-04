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
ll n, p[40], acu[40], res;

void solve () {
	cin >> n;

	res = 0;
	while (res < n) {
		for (int i = 0; i <= 38; i++) {
			if (res + acu[i] >= n) {
				res += p[i];
				break;
			}
		}
	}

	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	p[0] = acu[0] = 1;
	for (int i = 1; i <= 38; i++) {
		p[i] = 3 * p[i-1];
		acu[i] = p[i] + acu[i-1];
	}

	int q;
	cin >> q;
	while (q--)
		solve();

	return 0;
}