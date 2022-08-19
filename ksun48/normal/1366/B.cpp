#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, x, m;
	cin >> n >> x >> m;
	x--;
	int l = x;
	int r = x;
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		if(b < l || r < a) continue;
		l = min(l, a);
		r = max(r, b);
	}
	cout << r - l + 1 << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}