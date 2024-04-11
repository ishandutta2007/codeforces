#include <bits/stdc++.h>
using namespace std;


void solve(){
	auto get = [&](int x, int b) -> int {
		int r = x >> (b+1);
		int s = (x % (1 << (b+1)));
		return (r << b) + max(s - (1 << b), 0);
	};
	int ans = 0;
	int l, r;
	cin >> l >> r;
	for(int b = 0; b < 20; b++){
		ans = max(get(r+1, b) - get(l, b), ans);
	}
	cout << ((r-l+1) - ans) << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}