#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, m;
	cin >> n >> m;
	if(n & 1){
		if(m >= n){
			cout << "Yes" << '\n';
			for(int i = 0; i < n-1; i++){
				cout << "1 ";
			}
			cout << (m-n+1) << '\n';
			return;
		}
	} else {
		if(m % 2 == 0 && m >= n){
			cout << "Yes" << '\n';
			for(int i = 0; i < n-2; i++){
				cout << "1 ";
			}
			int r = (m-(n-2)) / 2;
			cout << r << " " << r << '\n';
			return;
		}
	}
	cout << "No" << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}