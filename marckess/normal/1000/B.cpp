#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 100005;

int n, m;
ll rev[MX], aux, res = 0;
ll a[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;

	a[0] = 0;
	n++;
	a[n] = m;

	for (int i = 1; i < n; i++)
		cin >> a[i];

	for (int i = 1; i <= n; i += 2)
		res += a[i] - a[i-1];

	for (int i = n; i >= 0; i--) {
		rev[i] = rev[i+1];
		if (i % 2 && i < n)
			rev[i] += a[i+1] - a[i];
	}

	aux = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] + 1 < a[i+1]) {
			if (i % 2 == 0) {
				res = max(res, aux + a[i+1] - 1 - a[i] + rev[i+1]);
			} else {
				aux += a[i] - a[i-1];
				res = max(res, aux + a[i+1] - (a[i] + 1) + rev[i+1]);
			}
		} else if (i % 2) {
			aux += a[i] - a[i-1];
		}
	}

	cout << res << endl;

	return 0;
}