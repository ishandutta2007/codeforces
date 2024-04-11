#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
void solve(){
	int n;
	cin >> n;
	vector<int> p(n);
	for(int i = 1; i < n; i++){
		cin >> p[i];
		p[i]--;
	}
	vector<ll> l(n), r(n);
	for(int i = 0; i < n; i++) cin >> l[i] >> r[i];
	int ans = 0;
	vector<ll> max_up(n);
	for(int i = n-1; i >= 0; i--){
		if(l[i] > max_up[i]){
			ans++;
			max_up[i] = r[i];
		}
		max_up[i] = min(max_up[i], r[i]);
		if(i > 0){
			max_up[p[i]] += max_up[i];
		}
	}
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}