#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int& x : a) cin >> x;
	a.insert(a.begin(), 0);
	a.insert(a.end(), 0);
	ll ans = 0;
	for(int i = 0; i + 1 < (int)a.size(); i++) ans += abs(a[i] - a[i+1]);
	for(int i = 1; i + 1 < (int)a.size(); i++){
		int v = max(a[i-1], a[i+1]);
		ans -= max(a[i] - v, 0);
	}
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}