#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	while(!a.empty()){
		bool done = false;
		for(int j = (int)a.size() - 1; j >= 0; j--){
			if(a[j] % (j+2) != 0){
				a.erase(a.begin() + j);
				done = true;
				break;
			}
		}
		if(!done){
			cout << "NO" << '\n';
			return;
		}
	}
	cout << "YES" << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}