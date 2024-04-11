#include <bits/stdc++.h>
using namespace std;



int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	using ll = long long;
	int n, K;
	cin >> n >> K;

	auto add = [&](vector<ll>& dp, int cost, ll wgt) -> void {
		int r = (int)dp.size();
		for(int i = r-1-cost; i >= 0; i--){
			dp[i+cost] = max(dp[i+cost], dp[i] + wgt);
		}
	};
	auto combine = [&](vector<ll> dp1, vector<ll> dp2) -> vector<ll> {
		vector<ll> res(dp1.size(), 0);
		for(int i = 0; i < (int)dp1.size(); i++){
			for(int j = 0; i + j < (int)dp1.size(); j++){
				res[i+j] = max(res[i+j], dp1[i] + dp2[j]);
			}
		}
		return res;
	};
	vector<vector<ll> > arrays;
	vector<pair<int, ll> > obj;
	for(int i = 0; i < n; i++){
		int s;
		cin >> s;
		vector<ll> a(s);
		for(ll& x : a) cin >> x;
		if((int)a.size() > K) a.resize(K);
		arrays.push_back(a);
		ll sum = 0;
		for(ll x : a) sum += x;
		obj.push_back({a.size(), sum});
	}

	const int B = 50;
	vector<int> splits;
	for(int i = 0; i <= n; i++){
		if(i % B == 0 || i == n) splits.push_back(i);
	}
	vector<vector<ll> > pref(splits.size(), vector<ll>(K+1, 0));
	vector<vector<ll> > suff(splits.size(), vector<ll>(K+1, 0));
	for(int i = 0; i + 1 < (int)splits.size(); i++){
		pref[i+1] = pref[i];
		for(int j = splits[i]; j < splits[i+1]; j++){
			add(pref[i+1], obj[j].first, obj[j].second);
		}
	}
	for(int i = (int)splits.size() - 1; i > 0; i--){
		suff[i-1] = suff[i];
		for(int j = splits[i-1]; j < splits[i]; j++){
			add(suff[i-1], obj[j].first, obj[j].second);
		}
	}
	ll ans = 0;
	for(int i = 0; i + 1 < (int)splits.size(); i++){
		vector<ll> res = combine(pref[i], suff[i+1]);
		for(int j = splits[i]; j < splits[i+1]; j++){
			vector<ll> tmp = res;
			for(int k = splits[i]; k < splits[i+1]; k++){
				if(k != j) add(tmp, obj[k].first, obj[k].second);
			}
			ans = max(ans, tmp[K]);
			ll csum = 0;
			for(int v = 0; v < (int)arrays[j].size(); v++){
				csum += arrays[j][v];
				ans = max(ans, tmp[K-v-1] + csum);
			}
		}
	}
	cout << ans << '\n';
}