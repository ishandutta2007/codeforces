#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	int r = 0;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		r += a-1;
	}
	cout << ((r & 1) ? "errorgorn" : "maomao90") << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}