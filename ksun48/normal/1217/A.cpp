#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
	ll s, i, e;
	cin >> s >> i >> e;
	if(2 * e <= i + e - s){
		cout << 0 << '\n';
	} else {
		ll v = (i + e - s + 2) / 2;
		if(v < 0) v = 0;
		cout << e - v + 1 << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	for(int t = 0; t < T; t++){
		solve();
	}
}