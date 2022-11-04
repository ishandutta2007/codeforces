#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define SET(p,k) memset(p, k, sizeof(p));
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	ll a, b, t;
	int n, mx = 1;
	string s;

	cin >> n >> a >> b >> t >> s;

	if (s[0] == 'h')
		t -= 1;
	else
		t -= 1 + b;

	if (t < 0) {
		cout << 0 << endl;
		return 0;
	}

	ll izq[500005], der[500005];

	der[0] = izq[0] = 0;
	for (int i = 1; i < n; i++)
		if (s[i] == 'h')
			der[i] = 1 + der[i-1] + a;
		else
			der[i] = 1 + der[i-1] + a + b;

	for (int i = 1; i < n; i++)
		if (s[n-i] == 'h')
			izq[i] = 1 + izq[i-1] + a;
		else
			izq[i] = 1 + izq[i-1] + a + b;

	for (int i = 1; i < n; i++) {
		if (der[i] > t)
			break;

		ll r = t - der[i];
		int acu = i, j;

		r -= i * a;
		if (r > 0) {
			j = (upper_bound(izq, izq+n, r) - izq) - 1;
			j = min(j, n - i - 1);
			acu += j;
		}

		mx = max(mx, acu+1);
	}

	for (int i = 1; i < n; i++) {
		if (izq[i] > t)
			break;

		ll r = t - izq[i];
		int acu = i, j;

		r -= i * a;
		if (r > 0) {
			j = (upper_bound(der, der+n, r) - der) - 1;
			j = min(j, n - i - 1);
			acu += j;
		}

		mx = max(mx, acu+1);
	}

	cout << mx << endl;

	return 0;
}