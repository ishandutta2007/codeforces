#include <bits/stdc++.h>
using namespace std;

void solve(){
	using ll = long long;
	ll a, b, c;
	cin >> a >> b >> c;
	if(a < c){
		cout << 1 << ' ';
	} else {
		cout << -1 << ' ';
	}
	if(a * b > c){
		cout << b << ' ';
	} else {
		cout << -1 << '\n';
	}
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}