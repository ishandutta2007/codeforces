#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve(){
	ll s, n, k;
	cin >> s >> n >> k;
	if(s == k){
		cout << "YES" << '\n';
		return;
	}
	ll th = (s+1) / (2*k) * k + min((s+1) % (2*k), k);
	cout << (th >= (n+1) ? "NO" : "YES") << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}