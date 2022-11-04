#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 5005;
int n, tag[MX];
ll res, dp[MX], s[MX];

void solve () {
	cin >> n;
	forn (i, n) cin >> tag[i];
	forn (i, n) cin >> s[i];
	
	memset(dp, 0, sizeof(dp));
	forn (i, n) {
		for (int j = i - 1; j >= 0; j--) {
			if (tag[i] != tag[j]) {
				ll aux = dp[j];
				dp[j] = max(dp[j], dp[i] + abs(s[i] - s[j]));
				dp[i] = max(dp[i], aux + abs(s[i] - s[j]));
			}
		}
	}
	
	res = 0;
	forn (i, n)
		res = max(res, dp[i]);
	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}