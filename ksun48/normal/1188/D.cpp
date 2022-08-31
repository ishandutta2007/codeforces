#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<ll> a(n);
	int B = 60;
	ll m = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		m = max(m, a[i]);
	}
	for(int i = 0; i < n; i++){
		a[i] = m - a[i];
	}
	vector<int> ord;
	for(int i = 0; i < n; i++){
		ord.push_back(i);
	}
	vector<ll> dp(n, 0);
	for(int v = 0; v <= B; v++){
		ll mask = (1ll << v) - 1;
		for(int i = 1; i < n; i++){
			if((a[ord[i]] & mask) == (a[ord[i-1]] & mask)){
				dp[i] = 1e18;
			}
		}
		vector<int> new_ord;
		vector<int> new_index(n); // index of ord[i] in new_ord

		vector<int> which(n);
		for(int i = 0; i < n; i++){
			which[i] = (a[ord[i]] >> v) & 1;
		}
		// new_ord[new_index[i]] = ord[i];
		for(int b = 0; b < 2; b++){
			for(int i = 0; i < n; i++){
				if(b == which[i]){
					new_index[i] = (int)new_ord.size();
					new_ord.push_back(ord[i]);
				}
			}
		}

		vector<ll> new_dp(n, 1e18);
		int idx = -1;
		for(int b = 1; b >= 0; b--){
			for(int i = n-1; i >= 0; i--){
				if(b == which[i]) idx = new_index[i];
			}
		}
		int cnt = 0;
		for(int i = 0; i < n; i++) cnt += (which[i] == 1);
		for(int b = 1; b >= 0; b--){
			for(int i = n-1; i >= 0; i--){
				if(b == which[i]) idx = new_index[i];
				cnt -= int(which[i] == b) - int(which[i] != b);
				new_dp[idx] = min(new_dp[idx], cnt + dp[i] + (v == B ? (n-i) % n: 0));
			}
		}

		ord = new_ord;
		dp = new_dp;
	}

	ll ans = 1e18;
	for(auto r : dp){
		ans = min(ans, r);
	}
	cout << ans << '\n';
}