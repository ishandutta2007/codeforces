#include <bits/stdc++.h>
using namespace std;

bool works(int x, int y){

	vector<int> a, b;
	for(int j = 0; j < 30; j++){
		if(x & (1 << j)) a.push_back(j);
		if(y & (1 << j)) b.push_back(j);
	}
	if(x > y || a.size() < b.size()){
		return false;
	}
	for(int i = 0; i < b.size(); i++){
		if(a[i] > b[i]) return false;
	}
	return true;
}

void solve(){
	int x, y;
	cin >> x >> y;
	bool ans = works(x, y);
	cout << (ans ? "YES" : "NO") << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}