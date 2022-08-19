#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	ll s = -4e18;
	ll e = 4e18;
	while(s + 1 < e){
		ll m = (s + e) / 2;
		ll cnt = 0;
		for(ll q : a){
			ll st = -1;
			ll en = 1e9;
			while(st + 1 < en){
				ll mid = (st + en) / 2;
				ll g = 3 * mid * mid + 3 * mid + 1;
				if(q - g > m){
					st = mid;
				} else {
					en = mid;
				}
			}
			cnt += min(en, q);
		}
		if(cnt <= k){
			e = m;
		} else {
			s = m;
		}
	}
	vector<ll> ans;
	ll m = e;
	ll cnt = 0;
	vector<ll> flex;
	for(ll q : a){
		ll st = -1;
		ll en = 1e9;
		while(st + 1 < en){
			ll mid = (st + en) / 2;
			ll g = 3 * mid * mid + 3 * mid + 1;
			if(q - g > m){
				st = mid;
			} else {
				en = mid;
			}
		}
		ll g = 3 * en * en + 3 * en + 1;
		cnt += min(en, q);
		ans.push_back(min(en, q));
		flex.push_back((q - g == m) && en < q);
	}
	assert(cnt <= k);
	for(int i = 0; i < n; i++){
		if(flex[i] && cnt < k){
			cnt++;
			ans[i]++;
		}
		cout << ans[i] << ' ';
	}
	cout << '\n';
}