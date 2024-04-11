#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

ll get(ll A){
	ll cnt = 0;
	for(int j = 0; j <= 2; j++){
		ll s = 0;
		ll e = 1.1e9;
		while(s + 1 < e){
			ll m = (s + e) / 2;
			if(m * (m + j) <= A){
				s = m;
			} else {
				e = m;
			}
		}
		cnt += s;
	}
	return cnt;
}
void solve(){
	ll L, R;
	cin >> L >> R;
	ll ans = get(R) - get(L-1);
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}