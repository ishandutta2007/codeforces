#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<vector<int> > to(n);
	vector<int> deg(n, 0);
	for(int i = 0; i < n; i++){
		int k;
		cin >> k;
		deg[i] = k;
		for(int j = 0; j < k; j++){
			int u;
			cin >> u;
			u--;
			to[u].push_back(i);
		}
	}
	set<int> ok;
	for(int i = 0; i < n; i++){
		if(deg[i] == 0) ok.insert(i);
	}
	int times = 0;
	int nread = 0;
	while(!ok.empty()){
		int cur = 0;
		times++;
		while(true){
			auto v = ok.lower_bound(cur);
			if(v == ok.end()) break;
			cur = *v;
			ok.erase(cur);
			for(int w : to[cur]){
				deg[w]--;
				if(deg[w] == 0) ok.insert(w);
			}
			nread++;
		}
	}
	if(nread == n){
		cout << times << '\n';
	} else {
		cout << -1 << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}