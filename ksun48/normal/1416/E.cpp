#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
	int n;
	cin >> n;
	vector<ll> a(n);
	for(ll& x : a){
		cin >> x;
		x -= 2;
	}
	// attained where
	ll amin = 0;
	ll amax = 2e9;
	int cdp = 0;
	set<ll> ok;
	ll k = 1;
	ll b = 0;
	for(int i = 0; i < n; i++){
		// cap to [0, a[i]]; best
		amin = max(amin, 0ll);
		amax = min(amax, a[i]);
		while(!ok.empty()){
			ll v = (*ok.begin()) * k + b;
			if(v < 0 || v > a[i]){
				ok.erase(ok.begin());
			} else {
				break;
			}
		}
		while(!ok.empty()){
			ll v = (*prev(ok.end())) * k + b;
			if(v < 0 || v > a[i]){
				ok.erase(prev(ok.end()));
			} else {
				break;
			}
		}
		if(amin <= amax || !ok.empty()){
			cdp += 1;
		} else {
			amin = 0;
			amax = a[i];
		}
		amin = a[i] - amin;
		amax = a[i] - amax;
		swap(amin, amax);
		b = a[i] - b;
		k = -k;
		if(a[i] % 2 == 0){
			ll half = a[i] / 2;
			if((amin <= half && half <= amax) || ok.count((half - b) / k)){
				cdp += 1;
				amin = amax = half;
				ok.clear();
			} else {
				ok.insert((half - b) / k);
			}
		}
	}
	cout << 2*n - (cdp - 1) << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}