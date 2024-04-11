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

const int MX = 300005;

int n, p[MX], dp[MX];
set<ii> mx;

void solve () {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> p[i];
	mx.clear();
	
	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1];
		if (dp[i - 1] >= i) dp[i] = max(dp[i], i + p[i]);
		
		int j = lower_bound(dp, dp + i, i - p[i] - 1) - dp;
		
		if (j < i) {
			const auto it = mx.lower_bound(ii(j + 1, -1));
		
			if (it == mx.end()) dp[i] = max(dp[i], i - 1);
			else dp[i] = max({dp[i], i - 1, it->se});
		}
		
		while (mx.size() && mx.rbegin()->se < i + p[i])
			mx.erase(*mx.rbegin());
		mx.emplace(i, i + p[i]);
	}
	
	if (dp[n] < n) {
		cout << "NO" << endl;
		return;
	}
	
	string res(n + 1, 'R');
	
	for (int i = n; i > 1;) {
		while (i > 1 && dp[i - 1] >= i && dp[i] == max(dp[i - 1], i + p[i]))
			i--;
		
		if (i > 1) {
			res[i] = 'L';
			i = lower_bound(dp, dp + i, i - p[i] - 1) - dp;
		}
	}
	
	cout << "YES" << endl;
	for (int i = 1; i <= n; i++)
		cout << res[i];
	cout << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}