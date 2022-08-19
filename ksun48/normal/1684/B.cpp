#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
void solve(){
	ll a, b, c;
	cin >> a >> b >> c;
	cout << (c*b + a) << ' ' << (b) << ' ' << (c) << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}