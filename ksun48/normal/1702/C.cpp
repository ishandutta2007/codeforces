#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, Q;
	cin >> n >> Q;
	vector<int> u(n);
	map<int,int> first_occ, last_occ;
	for(int& x : u){
		cin >> x;
	}
	for(int i = 0; i < n; i++){
		last_occ[u[i]] = i;
	}
	for(int i = n-1; i >= 0; i--){
		first_occ[u[i]] = i;
	}
	for(int i = 0; i < Q; i++){
		int a, b;
		cin >> a >> b;
		if(first_occ.count(a) == 0 || last_occ.count(b) == 0){
			cout << "NO" << '\n';
			continue;
		}
		if(first_occ[a] <= last_occ[b]){
			cout << "YES" << '\n';
		} else {
			cout << "NO" << '\n';
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}