#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, k;
	cin >> n >> k;
	if(n <= 2 * k){
		cout << -1 << '\n';
	} else {
		int a = 1;
		int b = n;
		for(int j = 0; j < k; j++){
			cout << a << ' ' << b << ' ';
			a++; b--;
		}
		for(int r = a; r <= b; r++){
			cout << r << ' ';
		}
		cout << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}