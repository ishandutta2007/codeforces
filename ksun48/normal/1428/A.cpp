#include <bits/stdc++.h>
using namespace std;

void solve(){
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int ans = abs(x1 - x2) + abs(y1 - y2);
	if(x1 != x2 && y1 != y2) ans += 2;
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}