#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> f(n);
	int r = 0;
	for(int i = 0; i < n; i++){
		cin >> f[i];
		r ^= f[i];
	}
	if(r == 0){
		cout << "DRAW" << '\n';
		return;
	}
	int z = 0;
	for(int b = 30; b >= 0; b--){
		if(r & (1 << b)){
			for(int i = 0; i < n; i++) if(f[i] & (1 << b)) z += 1;
			break;
		}
	}
	int y = n - z;
	if(z % 4 == 3 && y % 2 == 0){
		cout << "LOSE" << '\n';
	} else {
		cout << "WIN" << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}