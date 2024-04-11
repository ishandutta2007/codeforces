#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve(){
	int n;
	cin >> n;
	vector<ll> a(n);
	for(ll& x : a) cin >> x;
	int ans = 1;
	for(int i = 0; i + 1 < n; i++){
		ll s = a[i];
		ll t = a[i+1];
		int cnt, prv;
		{
			int k = lower_bound(a.begin(), a.end(), a[i]+1) - a.begin();
			if(k == n){
				ans = max(ans, n - i);
				continue;
			}
			cnt = (k+1) - i;
			t = a[k];
			prv = k;
		}
		while(true){
			ll u = 2*t - s;
			int k = lower_bound(a.begin(), a.end(), u) - a.begin();
			k = max(k, prv+1);
			if(k >= n) break;
			prv = k;
			cnt++;
			t = a[k];
		}
		ans = max(ans, cnt);
	}
	cout << (n - ans) << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}