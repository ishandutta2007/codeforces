#include <bits/stdc++.h>

//#define endl '\n'
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

const int MX = 300005;
int n, a[MX], dp[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	set<ii> inc, dec; 
	
	cin >> n;
	forn (i, n) cin >> a[i];

	for (int i = n - 1; i >= 0; i--) {
		dp[i] = dp[i + 1] + 1;

		{
			while (inc.size() && inc.begin()->fi < a[i]) {
				dp[i] = min(dp[i], inc.begin()->se + 1);
				inc.erase(inc.begin());
			}

			if (inc.size()) {
				dp[i] = min(dp[i], inc.begin()->se + 1);
			}

			if (inc.size() && inc.begin()->fi == a[i]) {
				inc.erase(inc.begin());
			}
		}

		{
			while (dec.size() && dec.rbegin()->fi > a[i]) {
				dp[i] = min(dp[i], dec.rbegin()->se + 1);
				dec.erase(*dec.rbegin());
			}

			if (dec.size()) {
				dp[i] = min(dp[i], dec.rbegin()->se + 1);
			}

			if (dec.size() && dec.rbegin()->fi == a[i]) {
				dec.erase(*dec.rbegin());
			}
		}

		inc.emplace(a[i], dp[i]);
		dec.emplace(a[i], dp[i]);
	}

	cout << dp[0] - 1 << endl;

	return 0;
}