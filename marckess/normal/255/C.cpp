#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define find(v,x) (lower_bound(ALL(v), x) - v.begin())

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 1000005, MN = 4005;
int n, a[MX], dp[MX], ant[MX], ult, res = 0, acu = 0;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; cin >> a[i++]);

	for (int i = 0; i < n; i++) {
		acu = 0;
		for (int j = 0; j < n; j++) {
			dp[a[j]] = 0;
			ant[a[j]] = -1;
		}

		for (int j = i; j < n; j++) {
			if (a[j] == a[i]) {
				ult = j;
				acu++;
			} else {
				if (ant[a[j]] < ult) {
					ant[a[j]] = j;
					dp[a[j]] += 2;
				}
			}
		}

		res = max(res, acu);

		for (int j = i; j < n; j++)
			if (a[i] != a[j]) {
				if (ant[a[j]] < ult) res = max(res, dp[a[j]]+1);
				else res = max(res, dp[a[j]]);
			}
	}

	cout << res << endl;

	return 0;
}