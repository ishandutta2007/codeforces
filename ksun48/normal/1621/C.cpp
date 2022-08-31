#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> perm(n, -1);
	int cur = 0;
	while(cur < n){
		if(perm[cur] == -1){
			vector<int> cycle;
			while(cycle.size() <= 1 || cycle.front() != cycle.back()){
				cout << "? " << (cur+1) << '\n';
				cout << flush;
				int x;
				cin >> x;
				x--;
				cycle.push_back(x);
				for(int i = 0; i + 1 < cycle.size(); i++){
					perm[cycle[i]] = cycle[i+1];
				}
			}
		} else {
			cur++;
		}
	}
	cout << "!";
	for(int x : perm){
		cout << ' ' << (x+1);
	}
	cout << '\n';
	cout << flush;
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}