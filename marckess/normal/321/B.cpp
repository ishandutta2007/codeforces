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

const int MX = 105;
int n, m, x[MX], res, ex[MX], mem[MX][MX];
vi a, b;

int dp (int i, int j) {
	if (i == a.size() || j == m) return 0;

	int &res = mem[i][j];
	if (res != -1) return res;

	res = max(dp(i + 1, j), dp(i, j + 1));

	if (a[i] <= x[j]) res = max(res, dp(i + 1, j + 1) + x[j] - a[i]);

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(mem, -1, sizeof(mem));
	
	cin >> n >> m;
	forn (i, n) {
		int p;
		string s;
	
		cin >> s >> p;

		if (s[0] == 'A') a.pb(p);
		else b.pb(p);
	}

	sort(all(a));
	sort(all(b));

	forn (i, m) cin >> x[i];

	sort(x, x + m);

	for (int k : b) {
		int ind = -1, d;

		forn (i, m) {
			if (!ex[i] && x[i] > k) {
				if (ind == -1 || x[i] - k < d) {
					ind = i;
					d = x[i] - k;
				}
			}
		}

		if (ind == -1) {
			res = -1;
			break;
		}

		ex[ind] = 1;
	}

	if (res != -1) {
		for (int k : a) {
			int ind = -1, d;

			forn (i, m) {
				if (!ex[i] && x[i] >= k) {
					if (ind == -1 || x[i] - k < d) {
						ind = i;
						d = x[i] - k;
					}
				}
			}

			if (ind == -1) {
				res = -1;
				break;
			}

			ex[ind] = 1;
			res += d;
		}
	}

	if (res != -1) {
		forn (i, m)
			if (!ex[i])
				res += x[i];
	}

	cout << max(res, dp(0, 0)) << endl;

	return 0;
}