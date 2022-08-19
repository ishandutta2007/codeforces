#include <bits/stdc++.h>
using namespace std;

void solve(){
	using ll = int64_t;
	int n, x;
	ll y;
	cin >> n >> x >> y;
	y ^= x;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		y ^= a;
	}
	if(y & 1){
		cout << "Bob" << '\n';
	} else {
		cout << "Alice" << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}