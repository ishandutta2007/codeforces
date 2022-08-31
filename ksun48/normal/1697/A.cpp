#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		m -= a;
	}
	cout << max(0, -m) << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}