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
typedef vector<ii> vii;

const int MX = 105;
ll n, m, t[MX], l[MX], r[MX];
ll a, b, act;

void solve () {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> t[i] >> l[i] >> r[i];

	act = 0, a = b = m;
	for (int i = 0; i < n; i++) {
		ll f = t[i] - act;
		act = t[i];

		a -= f;
		b += f;

		a = max(a, l[i]);
		b = min(b, r[i]);

		if (a > b) {
			cout << "NO" << endl;
			return;
		}
	}

	cout << "YES" << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}