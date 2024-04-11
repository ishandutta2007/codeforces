#include <bits/stdc++.h>
using namespace std;

set<int> square;

void solve(){
	int n;
	cin >> n;
	bool ans = (n % 2 == 0 && square.count(n / 2)) || (n % 4 == 0 && square.count(n / 4));
	cout << (ans ? "YES" : "NO") << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	for(int i = 1; i * i <= int(1e9); i++){
		square.insert(i*i);
	}
	int T;
	cin >> T;
	while(T--) solve();
}