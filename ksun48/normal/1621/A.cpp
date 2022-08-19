#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, k;
	cin >> n >> k;
	if(n < 2*k-1){
		cout << -1 << '\n';
	} else {
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if((i == j) && (i % 2 == 0) && i <= 2*(k-1)){
					cout << 'R';
				} else {
					cout << '.';
				}
			}
			cout << '\n';
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}