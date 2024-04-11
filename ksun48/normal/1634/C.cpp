#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, k;
	cin >> n >> k;
	int odd = (n * k + 1) / 2;
	int even = (n * k) / 2;
	if(odd % k != 0 || even % k != 0){
		cout << "NO" << '\n';
		return;
	}
	cout << "YES" << '\n';
	for(int i = 1; i <= odd; i += k){
		for(int j = 0; j < k; j++){
			cout << ((i + j) * 2 - 1) << ' ';;
		}
		cout << '\n';
	}
	for(int i = 1; i <= even; i += k){
		for(int j = 0; j < k; j++){
			cout << ((i + j) * 2) << ' ';;
		}
		cout << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}