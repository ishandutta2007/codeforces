#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	if(n == 1){
		cout << -1 << '\n';
	} else {
		cout << "2";
		cout << string(n-1, '3');
		cout << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		solve();
	}
}