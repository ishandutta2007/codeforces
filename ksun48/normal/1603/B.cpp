#include <bits/stdc++.h>
using namespace std;

void solve(){
	using ll = int64_t;
	ll x, y;
	cin >> x >> y;
	if(y < x){
		cout << (x + y) << '\n';
	} else {
		cout << (y - (y % x) / 2) << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}