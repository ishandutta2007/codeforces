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
int n, p, x[MX], y[MX], a[MX], b[MX];
ld res = 0;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> p;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];

		a[i] = x[i] - x[i] % p;
		b[i] = y[i] - y[i] % p;

		while (a[i] < x[i])
			a[i] += p;
		a[i] /= p;

		while (b[i] <= y[i])
			b[i] += p;
		b[i] /= p;
	}

	for (int i = 0, j = 1; i < n; i++, j = (j + 1) % n) {
		res += 2000.0L * (1 - ld(y[i] - x[i] - (b[i] - a[i]) + 1) * ld(y[j] - x[j] - (b[j] - a[j]) + 1) / (y[i] - x[i] + 1) / (y[j] - x[j] + 1));
	}

	cout << fixed << setprecision(8) << res << endl;

	return 0;
}