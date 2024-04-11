#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int& x : a) cin >> x;
	cout << 3 * n << '\n';
	for(int i = 1; i <= n; i += 2){
		for(int j = 0; j < 3; j++){
			cout << 2 << " " << i << " " << i+1 << '\n';
			cout << 1 << " " << i << " " << i+1 << '\n';			
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}