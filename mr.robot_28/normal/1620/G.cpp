#include <bits/stdc++.h>
using namespace std;
#define int long long
#define x first
#define y second
#define sz(a) (int)a.size()
const int N = 2e5 + 100;
const int mod = 998244353;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector <vector <int> > cnt(n, vector <int> (26));
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < sz(s); j++) {
			cnt[i][s[j] - 'a']++;
		}
	}
	vector <vector <int> > dp_sum((1 << n), vector <int> (2, 1));
	vector <int> dp_min(1 << n);
	for (int i = 0; i < 26; i++) {
		fill(dp_min.begin(), dp_min.end(), 1e9);
		for (int bit = 0; bit < n; bit++) {
			for (int msk = 0; msk < (1 << bit); msk++) {
				dp_min[(1 << bit) + msk] = min(dp_min[msk], cnt[bit][i]);
			}
		}
		dp_min[0] = 0;
		for (int msk = 0; msk < (1 << n); msk++) {
			dp_sum[msk][1] = 1LL * dp_sum[msk][1] * (dp_min[msk] + 1) % mod; 
		}
	}
	dp_sum[0][1] = 0;
	for (int msk = 0; msk < (1 << n); msk++) {
		int c = 0;
		dp_sum[msk][0] = 0;
		for (int j = 0; j < n; j++) {
			c ^= (((1 << j) & msk) >> j);
		}
		if (!c) {
			dp_sum[msk][0] = (mod - dp_sum[msk][1]) % mod;
			dp_sum[msk][1] = 0;
		}
	}
	for (int k = 0; k < 2; k++) {
		for (int i = 0; i < n; i++) {
			for (int msk = 0; msk < (1 << n); msk++) {
				if (msk & (1 << i)) {
					continue;
				}
				dp_sum[msk | (1 << i)][k] += dp_sum[msk][k];
				if (dp_sum[msk | (1 << i)][k] >= mod) {
					dp_sum[msk | (1 << i)][k] -= mod;
				}
			}
		}
	}
	int ans = 0;
	for (int msk = 0; msk < (1 << n); msk++) {
	    int sum = 0;
	    int c = 0;
	    for (int i = 0; i < n; i++) {
	    	if ((1 << i) & msk) {
	    		c++;
	    		sum += i + 1;
	    	}
	    }
	  //  cout << msk << " ";
	//    cout << dp_sum[msk][0] << " " << dp_sum[msk][1] << "\n";
	    int s = (dp_sum[msk][0] + dp_sum[msk][1]) % mod;
	    ans = ans ^ (1LL * sum * c * s);
	}
	cout << ans;
	return 0;
}