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

const int MX = 100005;
ll n, a[MX];
ll acu[MX], k;

bool esPos (int m) {
	for (int i = 1; i <= n; i++) {
		// Min
		ll p = a[i] * i - acu[i];

		int j = upper_bound(a+1, a+n+1, a[i] + m) - a;
		if (j <= n) {
			p += (acu[n] - acu[j-1]) - (a[i] + m) * (n - j + 1);
		}

		if (p <= k) {
			// if (m == 1) cout << i << endl;
			return 1;
		}

		if (a[i] - m < 0) continue;
		// Max
		p = (acu[n] - acu[i-1]) - a[i] * (n - i + 1);

		j = int(upper_bound(a+1, a+n+1, a[i] - m) - a) - 1;
		if (j > 0) {
			p += (a[i] - m) * j - acu[j];
		}

		if (p <= k) {
			// if (m == 1) cout << i << endl;
			return 1;
		}
	}

	return 0;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a+1, a+n+1);

	for (int i = 1; i <= n; i++)
		acu[i] = a[i] + acu[i-1];

	int i = 0, j = 1e9 + 5, rep = 32;
	while (rep--) {
		int m = (i + j) / 2;
		if (esPos(m)) j = m;
		else i = m;
	}

	cout << j << endl;

	return 0;
}