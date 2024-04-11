#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, z;
	cin >> n >> z;
	int m = 0;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		m = max(m, a | z);
	}
	cout << m << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}