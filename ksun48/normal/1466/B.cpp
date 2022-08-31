#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	int R = 2*n+3;
	vector<int> seen(R, 0);
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		x--;
		if(seen[x]) x++;
		seen[x]++;
	}
	int ans = 0;
	for(int x : seen) if(x) ans++;
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}