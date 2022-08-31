#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
	ll y, x;
	cin >> y >> x;
	y -= x;
	if(y == 1){
		cout << "NO" << '\n';
	} else {
		cout << "YES" << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	for(int _ = 0; _ < T; _++){
		solve();
	}
}