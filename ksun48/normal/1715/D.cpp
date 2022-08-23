#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N, Q;
	cin >> N >> Q;
	vector<tuple<int,int,int>> cons(Q);
	for(int i = 0; i < Q; i++){
		int u, v, x;
		cin >> u >> v >> x;
		u--; v--;
		cons[i] = {u, v, x};
	}
	vector<int> a(N, 0);
	for(int b = 0; b < 30; b++){
		vector<int> forced_0(N, 0);
		vector<int> need(N, 0);
		for(auto [u, v, x] : cons){
			if(!(x & (1 << b))){
				forced_0[u] = forced_0[v] = 1;
			}
		}
		vector<vector<int> > e(N);
		for(auto [u, v, x] : cons){
			if(!(x & (1 << b))) continue;
			if(forced_0[u]){
				need[v] = 1;
			} else if(forced_0[v]){
				need[u] = 1;
			} else {
				if(u > v) swap(u, v);
				if(u == v){
					need[u] = 1;
				} else {
					e[u].push_back(v);
				}
			}
		}
		for(auto [u, v, x] : cons){
			if(!(x & (1 << b))) continue;
		}
		for(int u = 0; u < N; u++){
			if(!need[u]){
				for(int v : e[u]){
					need[v] = 1;
				}
			}
			a[u] ^= need[u] << b;
		}
	}
	for(int i = 0; i < N; i++){
		cout << a[i] << " \n"[i == N-1];
	}
}