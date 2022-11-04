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
int n, k, v[MX], c[MX], l[MX], mn = 1e9, mx = 0;
ld e[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);
	
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		v[i] *= 100;
	}
	for (int i = 0; i < n; i++)
		cin >> c[i];

	int act;
	for (int i = n - 1; i >= 0; i--) {
		act = min(c[i], max(v[i], act));
		l[i] = act;
	}

	sort(l, l+n);

	ld res = 0, f = k;
	for (int i = 0; i < n - k + 1; i++) {
		f /= n - i;
		res += f * l[i];
		f *= n - k - i;
	}

	cout << res << endl;

	return 0;
}