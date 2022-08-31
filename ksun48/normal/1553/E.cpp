#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, m;
	cin >> n >> m;
	vector<int> p(n);
	for(int& x : p){
		cin >> x;
		x--;
	}
	vector<int> freq(n, 0);
	for(int i = 0; i < n; i++){
		freq[(n - p[i] + i) % n]++;
	}
	vector<int> ans;
	for(int c = 0; c < n; c++){
		if(freq[c] >= n - (n / 3) * 2){
			vector<int> vis(n, 0);
			int nc = 0;
			for(int i = 0; i < n; i++){
				if(vis[i]) continue;
				nc++;
				int cur = i;
				while(true){
					vis[cur] = 1;
					cur = p[(cur+c)%n];
					if(vis[cur]) break;
				}
			}
			if(n - nc <= m){
				ans.push_back(c);
			}
		}
	}
	cout << ans.size();
	for(int r : ans){
		cout << ' ' << r;
	}
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}