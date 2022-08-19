#include <bits/stdc++.h>
using namespace std;

void solve(){
	using ll = long long;
	int n;
	cin >> n;
	ll used = 0;
	ll cur;
	cin >> cur;
	for(int i = 1; i < n; i++){
		ll a;
		cin >> a;
		while(cur > a + (1ll << used) - 1) used++;
		cur = max(a, cur);
	}
	cout << used << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}