#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, c;
	cin >> n >> c;
	int ans;
	map<int,int> freq;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		freq[x]++;
	}
	for(auto [x, f] : freq) ans += min(f, c);
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}