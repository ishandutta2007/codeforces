// Problem : C. Extreme Extension
// Contest : Codeforces - Codeforces Round #752 (Div. 1)
// URL : https://codeforces.com/contest/1603/problem/C
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005, mod = 998244353;
int n, a[MX];

void main_() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	ll res = 0;
	
	vi s_val = {a[n]};
	vi s_dp = {1};
	
	for (int i = n - 1; i > 0; i--) {
		vi val, dp;
		
		forn (j, s_val.size()) {
			ll act = a[i], k = 1, x = s_val[j];
			
			if (act > x) {
				k = (act + x - 1) / x;
				(res += 1ll * (k - 1) * i % mod * s_dp[j]) %= mod;
				act /= k;
			}
			
			if (val.empty() || val.back() != act) {
				val.pb(act);
				dp.pb(s_dp[j]);
			} else {
				(dp.back() += s_dp[j]) %= mod;
			}
		}
		
		if (val.empty() || val.back() != a[i]) {
			val.pb(a[i]);
			dp.pb(0);
		}
		(dp.back() += 1) %= mod;
		
		s_val = val;
		s_dp = dp;
		
		assert(val.size() <= a[i] && dp.size() <= a[i]);
	}
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}