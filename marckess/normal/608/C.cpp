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

const int MX = 1000005;
int n, a[MX], b[MX];
int dp[MX], acu[MX], ex[MX];
int res;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	fill(ex, ex+MX, -1);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		acu[a[i]] = 1;
		ex[a[i]] = i;
	}

	for (int i = 1; i < MX; i++)
		acu[i] += acu[i-1];

	for (int i = 1; i < MX; i++) {
		if (ex[i] == -1) {
			dp[i] = dp[i-1];
		} else {
			int j = ex[i];

			if (a[j] - b[j] <= 0)
				dp[i] = acu[i-1];
			else
				dp[i] = acu[i-1] - acu[a[j] - b[j] - 1] + dp[a[j] - b[j] - 1];
		}
	}

	res = n;
	for (int i = 1; i < MX; i++)
		res = min(res, dp[i] + n - acu[i]);

	cout << res << endl;

	return 0;
}