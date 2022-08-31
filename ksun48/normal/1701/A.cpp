#include <bits/stdc++.h>
using namespace std;

void solve(){
	vector<vector<int> > a(2, vector<int>(2));
	for(auto& x : a) for(auto& y : x) cin >> y;
	if(a == vector<vector<int>>{{1, 1}, {1, 1}}){
		cout << 2 << '\n';
	} else if(a == vector<vector<int>>{{0, 0}, {0, 0}}){
		cout << 0 << '\n';
	} else {
		cout << 1 << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}