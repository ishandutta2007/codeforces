#include <bits/stdc++.h>
using namespace std;

void solve(){
	int x, y, a, b;
	cin >> x >> y >> a >> b;
	if((y - x) % (a + b) == 0){
		cout << (y - x) / (a + b) << '\n';
	} else {
		cout << -1 << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
}