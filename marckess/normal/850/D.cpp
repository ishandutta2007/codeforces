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

const int MX = 101;
int m, a[MX], mem[35][MX][MX * MX][2], adj[MX][MX];
vii d;

int dp (int i, int k, int sum, int f) {
	if (!k) return sum == 0 && (i == -1 || (i == 0 && f));
	if (i < 0 || sum < 0) return 0;
	if (sum < k * (k - 1) / 2) return 0;

	int &res = mem[i][k][sum][f];
	if (res != -1) return res;

	res = dp(i, k - 1, sum - a[i], 1);
	if (f) res |= dp(i - 1, k, sum, 0);

	return res;
}

void rec (int i, int k, int sum) {
	if (!k) return;

	if (dp(i, k - 1, sum - a[i], 1)) {
		d.emplace_back(a[i], d.size());
		return rec(i, k - 1, sum - a[i]);
	}

	rec(i - 1, k, sum);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(mem, -1, sizeof(mem));

	cin >> m;
	forn (i, m) cin >> a[i];
	sort (a, a + m);

	for (int n = 1; n < MX; n++)
		if (dp(m - 1, n, n * (n - 1) / 2, 0)) {
			rec(m - 1, n, n * (n - 1) / 2);

			while (d.size()) {
				sort(all(d));

				forn (i, (int)d.size() - 1) {
					if (i < d.back().fi) adj[d.back().se][d[i].se] = 1;
					else {
						adj[d[i].se][d.back().se] = 1;
						d[i].fi--;
					}
				}

				d.pop_back();
			}

			cout << n << endl;
			forn (i, n) {
				forn (j, n)
					cout << adj[i][j];
				cout << endl;
			}

			return 0;
		}

	cout << "=(" << endl;

	return 0;
}