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

const int MX = 1000005;
int n;
ll a[MX], acu[MX], mx[MX], x;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	forn (i, (n + 1) / 2) {
		cin >> a[i];
		acu[i] = a[i];
		if (i) acu[i] += acu[i - 1];
	}
	cin >> x;

	for (int i = (n + 1) / 2; i < n; i++) {
		a[i] = x;
		acu[i] = a[i];
		if (i) acu[i] += acu[i - 1];
	}

	for (ll i = 0, s = 0; i < (n + 1) / 2; i++, s += x) {
		mx[i] = acu[i] - s;
		if (i) mx[i] = max(mx[i], mx[i - 1]);
	}

	if (acu[n - 1] > 0) {
		cout << n << endl;
		return 0;
	}

	for (int i = n / 2 + 1; i < n; i++) {
		if (acu[i - 1] <= 0) continue;
		if (acu[i - 1] - mx[n - i - 1] > 0) {
			cout << i << endl;
			return 0;
		}
	}

	cout << -1 << endl;

	return 0;
}