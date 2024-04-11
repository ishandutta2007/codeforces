#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cout << (100000 + i) << ' ';
	}
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}