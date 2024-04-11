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

const int MX = 1000005;
int n, a[MX];
int izq[MX], der[MX], mn;
ll sum = 0, neg = 0, res = -1e18;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] < 0) neg -= a[i];
		else sum += a[i];
	}

	mn = a[0];
	for (int i = 1; i < n; i++) {
		izq[i] = mn;
		mn = min(mn, a[i]);
	}

	mn = a[n-1];
	for (int i = n-2; i >= 0; i--) {
		der[i] = mn;
		mn = min(mn, a[i]);
	}

	for (int i = 0; i < n; i++) {
		ll p = sum;

		if (a[i] < 0) p += 2 * a[i];
		if (izq[i] > 0) p -= 2 * izq[i];
		if (der[i] > 0) p -= 2 * der[i];

		res = max(res, p + neg);
	}

	cout << res << endl;

	return 0;
}