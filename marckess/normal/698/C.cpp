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

const int MX = (1 << 20) + 5;
int n, k;
ll comb[22][22], acu[MX];
ld p[22], res[22];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> p[i];

	if (n == k) {
		for (int i = 0; i < n; i++)
			cout << 1.0 * (p[i] != 0) << " ";
		cout << endl;
		return 0;
	}

	for (int i = 0; i < 22; i++) {
		comb[i][0] = 1;
		for (int j = 1; j <= i; j++)
			comb[i][j] = comb[i-1][j] + comb[i-1][j-1];
	}

	acu[k - 1] = 1;
	for (int i = k - 2; i + 1; i--) {
		acu[i] = 1;
		for (int j = i + 1; j < k; j++)
			acu[i] -= acu[j] * comb[n - 1 - i][j - i];
	}

	for (int i = 0; i < n; i++) {
		ld x = 0;

		if (p[i] == 0 || p[i] == 1 || k == 1) {
			res[i] = p[i];
			continue;
		}

		for (int j = 0; j < (1 << n); j++) {
			int cb = __builtin_popcount(j);

			if (!(j & (1 << i)) && cb <= k - 1) {
				ld y = 0;

				for (int t = 0; t < n; t++)
					if (j & (1 << t))
						y += p[t];

				x += 1 / (1 - y) * acu[cb];
			}
		}

		res[i] = p[i] * x;
	}

	for (int i = 0; i < n; i++)
		cout << res[i] << " ";
	cout << endl;

	return 0;
}