#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
void solve(){
	ll n, m;
	cin >> n >> m;
	vector<ll> a(m);
	for(ll& x : a){
		cin >> x;
		x--;
	}
	sort(a.begin(), a.end());
	vector<ll> diffs;
	for(int i = 1; i < m; i++){
		diffs.push_back(a[i] - a[i-1] - 1);
	}
	diffs.push_back(a[0] + n - a[m-1] - 1);
	sort(diffs.rbegin(), diffs.rend());
	int cur = 0;
	ll ans = n;
	for(ll x : diffs){
		if(x >= cur + 1 + cur + 2){
			ans -= x - (cur + cur + 1);
		} else if(x >= cur + 1 + cur){
			ans -= 1;
			break;
		} else {
			break;
		}
		cur += 2;
	}
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}