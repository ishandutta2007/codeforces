#include <bits/stdc++.h>
using namespace std;

void solve(){
	int x1, y1, z1, x2, y2, z2;
	cin >> x1 >> y1 >> z1;
	cin >> x2 >> y2 >> z2;
	int v = min(z1, y2);
	v -= max(y1 + z2 - (x1 + y1 + z1 - v), 0);
	cout << 2 * v << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}