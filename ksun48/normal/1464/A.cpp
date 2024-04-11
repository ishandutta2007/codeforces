#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, m;
	cin >> n >> m;
	vector<int> go(n, -1);
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		go[a] = b;
	}
	vector<int> vis(n, 0);
	int ans = m;
	for(int i = 0; i < n; i++){
		if(vis[i]) continue;
		if(go[i] == i){
			ans -= 2;
		}
		int cur = i;
		while(cur != -1 && !vis[cur]){
			vis[cur] = 1;
			cur = go[cur];
		}
		if(cur >= 0 && cur == i){
			ans++;
		}
	}
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}