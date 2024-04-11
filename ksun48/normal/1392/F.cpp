#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	using ll = long long;
	ll n;
	cin >> n;
	vector<ll> a(n);
	for(ll& x : a) cin >> x;
	vector<ll> diffs(n-1);
	for(ll i = 0; i < n-1; i++){
		diffs[i] = a[i+1] - a[i];
	}
	set<ll> empty;
	for(ll i = 0; i < n-1; i++) empty.insert(i);
	for(ll i = 0; i < n-1; i++){
		while(diffs[i]){
			if((ll)empty.size() <= 1) break;
			if(empty.count(i)){
				diffs[i]--;
				empty.erase(i);
			} else {
				auto v = empty.lower_bound(i);
				if(v == empty.begin()){
					ll w = *v;
					empty.erase(w);
					ll g = min(diffs[i], (w+1) / (i+1));
					w -= g * (i+1);
					diffs[i] -= g;
					if(w >= 0) empty.insert(w);
				} else if(v == empty.end()){
					ll w = *prev(v);
					empty.erase(w);
					ll g = min(diffs[i], (n-1-w) / (n-1-i));
					w += g * (n-1-i);
					diffs[i] -= g;
					if(w < n-1) empty.insert(w);
				} else {
					ll w1 = *prev(v);
					ll w2 = *v;
					diffs[i]--;
					empty.erase(w1);
					empty.erase(w2);
					empty.insert(w1 + w2 - i);
				}
			}
		}
	}
	ll tsum = 0;
	for(ll x : a) tsum += x;
	vector<ll> ans(n, 0);
	if((ll)empty.size() > 1){
		for(ll i = 1; i < n; i++){
			ans[i] = ans[i-1];
			if(!empty.count(i-1)) ans[i] += 1;
		}
	} else {
		for(ll i = 0; i < n; i++){
			ans[i] = i-1;
		}
	}
	ll rsum = 0;
	for(ll x : ans) rsum += x;
	ll d = tsum - rsum;
	if((ll)empty.size() > 1) assert(d % n == 0);
	for(ll& x : ans) x += d / n;
	for(ll i = 0; i < (d % n); i++){
		ans[i] += 1;
	}
	for(ll x : ans) cout << x << ' ';
	cout << '\n';
}