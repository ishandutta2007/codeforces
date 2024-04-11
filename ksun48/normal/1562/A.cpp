#include <bits/stdc++.h>
using namespace std;

void solve(){
	int l, r;
	cin >> l >> r;
	if(r-l < l){
		cout << (r-l) << '\n';
	} else {
		cout << ((r-1) / 2) << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}