#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> b(n);
	for(int& x : b){
		cin >> x;
		x--;
	}
	vector<int> p(n);
	vector<int> dist(n);
	for(int i = 0; i < n; i++){
		cin >> p[i];
		p[i]--;
		dist[p[i]] = i;
	}
	for(int i = 0; i < n; i++){
		if(dist[b[i]] > dist[i]){
			cout << -1 << '\n';
			return;
		}
	}
	for(int i = 0; i < n; i++){
		cout << (dist[i] - dist[b[i]]) << ' ';
	}
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}