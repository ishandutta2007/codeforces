#include <bits/stdc++.h>
using namespace std;

void solve(){
	int c, d;
	cin >> c >> d;
	if(c == 0 && d == 0){
		cout << 0 << '\n';
	} else if(c + d == 0){
		cout << 1 << '\n';
	} else if(c == d){
		cout << 1 << '\n';
	} else if((c-d) & 1){
		cout << -1 << '\n';
	} else {
		cout << 2 << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}