#include <bits/stdc++.h>
using namespace std;

void solve(){
	vector<int> ans;
	int n;
	cin >> n;
	int c1 = 0;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		if(a == 0){
			if(c1){
				c1 = 0;
			}
			ans.push_back(0);
		} else if(a == 1){
			if(c1){
				ans.push_back(1);
				ans.push_back(1);
				c1 = 0;
			} else {
				c1 = 1;
			}
		}
	}
	cout << ans.size() << '\n';
	for(int a : ans){
		cout << a << ' ';
	}
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}