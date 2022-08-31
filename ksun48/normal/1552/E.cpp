#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	vector<vector<int> > a(n);
	for(int i = 0; i < n*k; i++){
		int c;
		cin >> c;
		c--;
		a[c].push_back(i);
	}
	vector<pair<int,int> > ans(n);
	vector<int> done(n, 0);
	int allowed = (n + k-2) / (k-1);
	for(int j = 0; j < k-1; j++){
		vector<int> rem;
		for(int i = 0; i < n; i++) if(!done[i]) rem.push_back(i);
		sort(rem.begin(), rem.end(), [&](int x, int y) -> bool {
			return a[x][j+1] < a[y][j+1];
		});
		if((int)rem.size() > allowed) rem.resize(allowed);
		for(int c : rem){
			ans[c] = {a[c][j], a[c][j+1]};
			done[c] = 1;
		}
	}
	for(auto [x, y] : ans){
		cout << (x+1) << ' ' << (y+1) << '\n';
	}
}