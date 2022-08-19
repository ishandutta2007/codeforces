#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	vector<ll> a(n); 
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		a[i] = x;
	}
	ll ans = 0;
	for(int i = 0; i < n; i += 2){
		ll psum = 0;
		ll pmin = 0;
		for(int j = i+1; j < n; j++){
			int sign = (j & 1) ? -1 : 1;
			if(sign == 1){
				psum += a[j];
			} else {
				if(psum - a[j] <= pmin && 0 - a[i] <= pmin){
					ans += min(pmin - (0 - a[i]) + 1, pmin - (psum - a[j]) + 1);
					if(j == i+1) ans--;
				}
				psum -= a[j];
				pmin = min(pmin, psum);
			}
		}
	}
	cout << ans << '\n';
}